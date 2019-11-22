#ifndef DECLSPEC_H_INCLUDED
#define DECLSPEC_H_INCLUDED

#if defined(__CYGWIN__) || defined(__MINGW32__)
  #ifdef _USRDLL
    #ifdef OPENGL_CORE_EXPORTS
      #define OPENGL_CORE_API __declspec(dllexport)
      #define EXTERN_OPENGL_CORE_API extern __declspec(dllexport)
    #else
      #define OPENGL_CORE_API __declspec(dllimport)
      #define EXTERN_OPENGL_CORE_API extern __declspec(dllimport)
    #endif
  #else
    #define OPENGL_CORE_API extern
  #endif

  #include <stdint.h>
  #ifndef OGLAPIENTRY
  #  define OGLAPIENTRY __stdcall
  #endif
  #ifndef OPENGL_CORE_APIENTRY
  #  define OPENGL_CORE_APIENTRY __stdcall
  #endif

  #define OGLAPI extern

#elif (defined WIN32) || (defined _WIN32) || (defined __WIN32__)
  #if defined(_USRSHARED)
    #if defined(OPENGL_CORE_EXPORTS)
      #define OPENGL_CORE_API __declspec(dllexport)
      #define EXTERN_OPENGL_CORE_API extern __declspec(dllexport)
    #else
      #define OPENGL_CORE_API __declspec(dllimport)
      #define EXTERN_OPENGL_CORE_API extern __declspec(dllimport)
    #endif
  #elif defined(_USRSTATIC)
    #define OPENGL_CORE_API
    #define EXTERN_OPENGL_CORE_API extern
  #else
    #define OPENGL_CORE_API
    #define EXTERN_OPENGL_CORE_API extern __declspec(dllimport)
  #endif

  #include <stdint.h>
  #ifndef OGLAPIENTRY
  #  define OGLAPIENTRY __stdcall
  #endif
  #ifndef OPENGL_CORE_APIENTRY
  #  define OPENGL_CORE_APIENTRY __stdcall
  #endif

  #define OGLAPI __declspec(dllimport)

#elif (defined __gnu_linux__) || (defined __linux__) || __APPLE__
  #define OPENGL_CORE_API
  #define EXTERN_OPENGL_CORE_API extern __attribute__ \
    ((visibility("default")))

  #include <stddef.h>
  #include <stdint.h>
  #ifndef OGLAPIENTRY
  #  define OGLAPIENTRY
  #endif
  #ifndef OPENGL_CORE_APIENTRY
  #  define OPENGL_CORE_APIENTRY
  #endif

  #define OGLAPI

#endif

#endif
