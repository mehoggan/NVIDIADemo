#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "nvidia_demo/iscene.h"

#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <memory>

#include <GL/gl.h>

#include <SDL.h>

class Application
{
public:
  Application(const std::string &name, int argc, char **argv);

  ~Application();

  void set_scene(std::unique_ptr<IScene> &&client_scene);

  void clear_scene();

  int run();

private:
  static void check_SDL_error(int line);

  static int render_thread(void *ptr);

private:
  std::condition_variable start_rendering;
  std::mutex render_mutex;
  std::atomic_bool ready;
  std::atomic_bool render;
  std::atomic_bool running;
  SDL_Window *mainwindow;
  SDL_Thread *thread;

  std::mutex scene_lock;
  std::unique_ptr<IScene> scene;
};

#endif
