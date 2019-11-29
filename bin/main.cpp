#include <nvidia_demo/application.h>
#include <nvidia_demo/square_scene.h>

#include <memory>

int main(int argc, char* argv[])
{
  Application app("NVIDIA Demo", argc, argv);
  app.set_scene(std::make_unique<SquareScene>());
  return app.run();
}
