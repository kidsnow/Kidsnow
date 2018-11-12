#ifdef OS_TOS
#include <GL/gl.h>
#include <GL/glext.h>
#include <glm/gtc/matrix_transform.hpp>
#elif _WIN32
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#else // MAC
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#endif
