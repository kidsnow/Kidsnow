project(KIDSNOW_ENGINE)

cmake_minimum_required(VERSION 3.9)

set(FRAMEWORK_DEPENDENCIES Cocoa OpenGL IOKit CoreVideo)

foreach (FRAMEWORK ${FRAMEWORK_DEPENDENCIES})
    find_library(LIB_${FRAMEWORK} ${FRAMEWORK})
    list (APPEND FRAMEWORK_LIST ${LIB_${FRAMEWORK}})
    if(NOT LIB_${FRAMEWORK})
        message(FATAL_ERROR "${FRAMEWORK} not found")
    endif()
endforeach()

include_directories(include)
link_directories(lib/Mac)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(clear_color src/main.cpp)
target_link_libraries(clear_color glfw3 ${FRAMEWORK_LIST})
