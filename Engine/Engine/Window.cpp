#include "Window.h"
#include "Input.h"

GLFWwindow* createWindow(int width, int height, const char* name)
{
    /* Initialize the library */
    if (!glfwInit()) { std::cout << "glf couldn´t be Initialized" << std::endl; glfwTerminate();};

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
    
    if (!window)
    {
        std::cout << "Window couldn´t be created" << std::endl;
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    return window;
}