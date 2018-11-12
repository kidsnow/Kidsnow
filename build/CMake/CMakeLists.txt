project(KIDSNOW_ENGINE)
cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)

# * twk/views/widget/widget.h를 include할 때 내부 구현체 중 OS dependent한 부분에서
#   TOS를 위한 구현체는 OS_TOS라는 definition이 있어야 활성화된다.
# * GL_GLEXT_PROTOTYPES는 OpenGL extension(거의 모든 최근 feature가 다 ext)
#   를 쓰기 위해 필요함.
add_definitions(-D_DEBUG -DOS_TOS -DGL_GLEXT_PROTOTYPES)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR}/../..)

include_directories(/system/include)
link_directories(/system/lib/i386-linux-gnu)

include_directories(${PROJECT_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)
file(GLOB SOURCES ${PROJECT_DIR}/src/*.cpp)
add_executable(clear_color ${SOURCES})

set(TOS_SYSTEM_LIB
    EGL
    GL
    twk
    views
    print_lib
    controls
)
target_link_libraries(clear_color ${TOS_SYSTEM_LIB})
