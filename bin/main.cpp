#include <nvidia_demo/application.h>
#include <nvidia_demo/simple_scene.h>

#include <memory>

int main(int argc, char* argv[])
{
  Application app("NVIDIA Demo", argc, argv);
  std::unique_ptr<IScene> scene(new SimpleScene);
  app.set_scene(std::move(scene));
  return app.run();
}
