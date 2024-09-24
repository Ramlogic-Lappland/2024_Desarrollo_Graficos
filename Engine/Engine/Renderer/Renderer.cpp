#include "Renderer.h"

#include <iostream>

#include "shader.h"
#include "ErrorHandler.h"

Renderer::Renderer(){

}

Renderer::~Renderer() {

}

int locaA;

float r = 0.0f;
float g = 0.0f;
float b = 0.0f;

float increment = 0.05f;

void Renderer::initBuffers() {

	unsigned int buffer;

    float positions[] = {
    -0.5f, -0.5f,
     0.5f, -0.5f,
     0.5f,  0.5f,
    -0.5f,  0.5f,
    };

    unsigned int indicesSquare[] = {
        0, 1, 2,
        2, 3, 0
    };  // SQUARE INDICES

    unsigned int indicesTriangle[] = {
    0, 1, 2,
    }; //TRIANGLE INDICES

	GLCall(glGenBuffers(1, &buffer)); //renderer
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer)); //renderer   
	GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW)); //renderer a square (*2) no (*2) = triangle

	GLCall(glEnableVertexAttribArray(0));  //renderer
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0)); //renderer

    unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo)); //renderer
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo)); //renderer
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indicesTriangle, GL_STATIC_DRAW)); // change indice type to draw square or triangle
}


void Renderer::Render() {


    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

    //glDrawArrays(GL_TRIANGLES, 0, 3);  // renders just a triangle


    glUniform4f(locaA, r, 0.3f, 0.8f, 1.0f); // color

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);   // renders a  square and triangle

    if (GetKeyState(VK_SPACE) & 0x8000) // escape to close
    {
        if (r > 1.0f)
        {
            increment = -0.05f;
        }
        else if (r < 0.0f)
        {
            increment = 0.05f;
        }

        r += increment;
    }

}


// Below all belongs to shader ---------------------------------------

unsigned int shader;

// Shader Initialization ---------------------------------------------

void Renderer::initShader() {

    shaderProgramSource source = ParseShader("Renderer/Shader/Basic.shader");

    shader = CreateShader(source.VertexSource, source.FragmentSource);
    GLCall(glUseProgram(shader)); // USE PROGRAM *------------------------------*

    GLCall(int location = glGetUniformLocation(shader, "u_Color"));
    ASSERT(location != -1);
    GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f)); // color

    locaA = location;

}

// Shader builder   ---------------------------------------------

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

// Shader Compiler  ---------------------------------------------

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int results;
    glGetShaderiv(id, GL_COMPILE_STATUS, &results);

    if (results == GL_FALSE) {

        int lenght;

        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)alloca(lenght * sizeof(char));
        glGetShaderInfoLog(id, lenght, &lenght, message);

        std::cout << "Failed to compile: " << (type == GL_VERTEX_SHADER ? "Vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    };

    return id;
}





