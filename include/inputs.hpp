#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <istream>

#include "settings.hpp"

void getInputs(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}