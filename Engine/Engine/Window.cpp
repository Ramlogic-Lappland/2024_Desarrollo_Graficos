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

/* Loop until the user closes the window */

float positions[6];
unsigned int buffer;

positions[6] = triangle();

glGenBuffers(1, &buffer);
glBindBuffer(GL_ARRAY_BUFFER, buffer);
glBufferData(GL_ARRAY_BUFFER,6* sizeof(float), positions, GL_STATIC_DRAW);




while (!glfwWindowShouldClose(window))
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);



    /* Swap front and back buffers */
    glfwSwapBuffers(window);



    /* Poll for and process events */
    glfwPollEvents();
}

glfwTerminate();
return 0;
}

 
float triangle(void)
{
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };


    return vertices[6];
}
