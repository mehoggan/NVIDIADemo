#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#if defined(__ANDROID__)
  #define __OPENGL_CORE_ANDROID__ 1
  #define msvc_typename
#elif defined(__CYGWIN__)
  #define __OPENGL_CORE_CYGWIN__ 1
  #define msvc_typename
#elif defined(__gnu_linux__) || defined(__linux__)
  #define __OPENGL_CORE_GNULINUX__ 1
  #define msvc_typename
  #include <GL/glx.h>
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__)
  #define __OPENGL_CORE_MACOSX__ 1
  #define msvc_typename
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
  #define __OPENGL_CORE_WINDOWS__ 1
  #define msvc_typename typename
  #if defined(_WIN16)
    #define __OPENGL_CORE_16_BIT__ 1
  #elif defined(_WIN32)
    #define __OPENGL_CORE_32_BIT__ 1
  #elif defined(_M_IA64) || defined(_M_AMD64) || defined(__x86_64__) || \
    defined(__x86_64)
    #define __OPENGL_CORE_64_BIT__ 1
  #else
    #define __OPENGL_CORE_32_BIT__ 1
  #endif
#endif

#endif
