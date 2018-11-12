project(KIDSNOW_ENGINE)
cmake_minimum_required(VERSION 3.9)

add_definitions(-D_DEBUG -DTOS -DGL_GLEXT_PROTOTYPES)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR}/../..)

include_directories(/system/include)

include_directories(${PROJECT_DIR}/include)
link_directories(${PROJECT_DIR}/lib/Mac)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)
file(GLOB SOURCES ${PROJECT_DIR}/src/*.cpp)
add_executable(clear_color ${SOURCES})
target_link_libraries(clear_color glfw3 EGL GL)
