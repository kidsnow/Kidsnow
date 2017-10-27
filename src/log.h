#pragma once

#include <iostream>

#ifdef _DEBUG

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define LogDebug(...) \
    { printf (ANSI_COLOR_RED); \
    printf ("%s:%d\n", __FILE__, __LINE__); \
    printf ("\tKidsnow: " __VA_ARGS__ ); \
    printf (ANSI_COLOR_RESET); \
    printf ("\n") }

#else
#define LogDebug(...)
#endif

#define LogInfo(...) \
    { printf (ANSI_COLOR_CYAN); \
    printf ("Kidsnow: " __VA_ARGS__); \
    printf (ANSI_COLOR_RESET); \
    printf ("\n") }
