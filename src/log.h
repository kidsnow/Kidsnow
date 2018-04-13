#pragma once

#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifdef _DEBUG

#define LogDebug(...)								\
  {													\
      std::cout << ANSI_COLOR_RED;					\
      std::cout << "%s:%d\n", __FILE__, __LINE__;	\
      std::cout << "\tKidsnow: " __VA_ARGS__ ;		\
      std::cout << ANSI_COLOR_RESET << std::endl;	\
  }

#else
#define LogDebug(...)
#endif

#define LogInfo(...)								\
  {													\
    std::cout << ANSI_COLOR_CYAN;					\
    std::cout << "Kidsnow: " __VA_ARGS__;			\
    std::cout << ANSI_COLOR_RESET << std::endl;		\
  }
