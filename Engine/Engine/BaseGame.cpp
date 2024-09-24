#include "BaseGame.h"

#include "Window.h"
#include "Input.h"

#include "Renderer/Renderer.h"

static unsigned int CompileShader(unsigned int type, const std::string& source);

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);


int main(void)
{
    GLFWwindow* window = createWindow(1024, 768, "Engine"); //width - height - name

    if (glewInit() != GLEW_OK) std::cout << "ERROR! GLEW WASN´T INITIALIZED CORRECTLY" << std::endl;

    Renderer renderer;
    renderer.initBuffers();


    renderer.initShader();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

         
        if (GetKeyState(VK_ESCAPE) & 0x8000) // escape to close
        {
            closeEngine();
            return 0;
        }

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.Render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        /* Poll for and process events */
        glfwPollEvents();
    }

    
    glDeleteProgram(shader);
    std::cout << "program deleted" << std::endl;
    glfwTerminate();
    return 0;
}

void initEngine()
{

}

void deInitEngine()
{

}

void closeEngine()
{
    glfwTerminate();
}

