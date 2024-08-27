#include "BaseGame.h"

#include "Window.h"
#include "Input.h"

#include "Renderer/Renderer.h"

int main(void)
{
    GLFWwindow* window = createWindow(1024, 768, "Engine");

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