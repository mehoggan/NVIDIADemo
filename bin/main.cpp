#include <nvidia_demo/application.h>
#include <nvidia_demo/square_scene.h>
#include <nvidia_demo/gl_functions.h>

#include <memory>

int main(int argc, char* argv[])
{
  Application app("NVIDIA Demo", argc, argv);
  app.set_scene(std::make_unique<SquareScene>(
    opengl_core::gl_version {3, 2} ));
  return app.run();
}
