#include "Window.h"
//#include"GL/glew.h"

int createWindow (void)
{

GLFWwindow* window;

/* Initialize the library */
if (!glfwInit()) return -1;

/* Create a windowed mode window and its OpenGL context */
window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

if (!window)
{
    glfwTerminate();
    return -1;
}

/* Make the window's context current */
glfwMakeContextCurrent(window);

if (glewInit() != GLEW_OK) std::cout << "ERROR! GLEW WASN´T INITIALIZED CORRECTLY" << std::endl;

Renderer renderer;
renderer.initBuffers();


/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    renderer.Render();



    /* Swap front and back buffers */
    glfwSwapBuffers(window);


    /* Poll for and process events */
    glfwPollEvents();
}

glfwTerminate();
return 0;
}





