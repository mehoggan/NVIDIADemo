#include "nvidia_demo/application.h"

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/resource_loader.h"

Application::Application(
  const std::string &name,
  int, char **argv,
  const opengl_core::gl_version &version) :
  ready(false),
  render(true),
  running(false),
  version_(version)
{
  std::string exe_path(argv[0]);
  ResourceLoader::exe_path(exe_path.substr(0, exe_path.find_last_of("\\/")));

  SDL_Init(SDL_INIT_VIDEO);
  mainwindow = SDL_CreateWindow(
      name.c_str(),
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      800,
      600,
      SDL_WINDOW_OPENGL);
  check_SDL_error(__LINE__);

  thread = SDL_CreateThread(render_thread, "Renderer", (void *)this);
  check_SDL_error(__LINE__);
}

Application::~Application()
{
  int return_val;
  SDL_WaitThread(thread, &return_val);
  SDL_DestroyWindow(mainwindow);
  SDL_Quit();
}

void Application::set_scene(std::unique_ptr<IScene> &&client_scene)
{
  {
    std::lock_guard<std::mutex> lg(scene_lock);
    if (scene_ != nullptr) {
      scene_->destroy();
      scene_.reset(nullptr);
    }

    scene_ = std::move(client_scene);
  }
}

void Application::clear_scene()
{
  {
    std::lock_guard<std::mutex> lg(scene_lock);
    if (scene_ != nullptr) {
      scene_->destroy();
      scene_.reset(nullptr);
    }
  }
}

int Application::run()
{
  if (running.load()) {
    return EXIT_FAILURE;
  }

  SDL_Event event;
  bool poll = true;
  std::atomic_bool first_show(false);
  running.store(true);

  while (poll) {
    while(SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_WINDOWEVENT: {
        switch (event.window.type) {
        case 512: { // First message that comes in not defined in doc.
          if (not first_show.load()) {
            std::cout << "First show event." << std::endl;
            {
              std::lock_guard<std::mutex> lg(render_mutex);
              ready = true;
            }
            start_rendering.notify_one();
            first_show.store(true);
          }
        }
          break;
        }
      }
        break;
      case SDL_QUIT: {
        render.store(false);
        SDL_Delay(10);
        poll = false;
      }
        break;
      case SDL_KEYUP: {
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE: {
          render.store(false);
          SDL_Delay(10);
          poll = false;
        }
          break;
        }
      }
        break;
      case SDL_MOUSEMOTION: {
      }
        break;
      default: {
      }
        break;
      }

      if (!poll) {
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}

void Application::check_SDL_error(int line)
{
  const char *error = SDL_GetError();
  if (*error != '\0') {
    std::cerr << "SDL Error: " << error << " line: " << line << std::endl;
    SDL_ClearError();
    throw std::runtime_error(std::string("FAILURE: ") + error);
  }
}

int Application::render_thread(void *ptr)
{
  Application *self = reinterpret_cast<Application *>(ptr);
  SDL_Window *mainwindow = self->mainwindow;
  SDL_GLContext gl_context = SDL_GL_CreateContext(mainwindow);
  check_SDL_error(__LINE__);
  SDL_GL_SetSwapInterval(1);

  std::unique_lock<std::mutex> render_lock(self->render_mutex);
  self->start_rendering.wait(render_lock,
    [&]
    {
      return self->ready.load();
    }); 

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, self->version_.major);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, self->version_.minor);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_MakeCurrent(mainwindow, gl_context);
  opengl_core::gl_functions::configure(self->version_);

  {
    std::lock_guard<std::mutex> lg(self->scene_lock);
    if (self->scene_ != nullptr && not self->scene_->loaded()) {
      self->scene_->load();
    }
  }

  while (self->render.load()) {
    {
      std::lock_guard<std::mutex> lg(self->scene_lock);
      if (self->scene_ != nullptr) {
        int w = 800;
        int h = 600;
        SDL_GetWindowSize(mainwindow, &w, &h);
        self->scene_->render(w, h);
      }
    }
    SDL_GL_SwapWindow(mainwindow);
  }

  {
    std::lock_guard<std::mutex> lg(self->scene_lock);
    if (self->scene_ != nullptr) {
      self->scene_->destroy();
    }
  }

  return EXIT_SUCCESS;
}
