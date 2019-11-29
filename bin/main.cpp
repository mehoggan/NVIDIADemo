#include <nvidia_demo/application.h>
#include <nvidia_demo/square_scene.h>
#include <nvidia_demo/gl_functions.h>

#include <memory>

int main(int argc, char* argv[])
{
  opengl_core::gl_version opengl_version {3, 2};
  Application app("NVIDIA Demo", argc, argv, opengl_version);
  app.set_scene(std::make_unique<SquareScene>(opengl_version));
  return app.run();
}
