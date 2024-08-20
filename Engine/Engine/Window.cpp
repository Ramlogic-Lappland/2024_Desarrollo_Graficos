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

unsigned int buffer;

//triangle
float positions[6] = {
-0.5f, -0.5f,
 0.0f,  0.5f,
 0.5f, -0.5f
};

glGenBuffers(1, &buffer); //renderer
glBindBuffer(GL_ARRAY_BUFFER, buffer); //renderer
glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); //renderer

glEnableVertexAttribArray(0);  //renderer
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //renderer

glBindBuffer(GL_ARRAY_BUFFER, 0);

/* Loop until the user closes the window */
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





