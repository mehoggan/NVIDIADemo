if(WIN32)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1 /W4")
  set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1 /W4")
  set(CMAKE_C_FLAGS_RELEASE "/MD /Zi /Ob0 /Od /RTC1 /W4")
  set(CMAKE_CXX_FLAGS_RELEASE "/MD /Zi /Ob0 /Od /RTC1 /W4")
endif ()
