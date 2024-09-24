#include "Renderer.h"

#include <iostream>

#include "shader.h"

Renderer::Renderer(){

}

Renderer::~Renderer() {

}



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
    };

    unsigned int indicesTriangle[] = {
    0, 1, 2,
    };

	glGenBuffers(1, &buffer); //renderer
	glBindBuffer(GL_ARRAY_BUFFER, buffer); //renderer   
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW); //renderer a square (*2) no (*2) = triangle

	glEnableVertexAttribArray(0);  //renderer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //renderer

    unsigned int ibo;
    glGenBuffers(1, &ibo); //renderer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo); //renderer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indicesTriangle, GL_STATIC_DRAW); // change indice type to draw square or triangle
}


void Renderer::Render() {

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glDrawArrays(GL_TRIANGLES, 0, 3);  // renders just a triangle

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);   // renders a  square and triangle
}


// Below all belongs to shader ---------------------------------------

unsigned int shader;

// Shader Initialization ---------------------------------------------

void Renderer::initShader() {

    shaderProgramSource source = ParseShader("Renderer/Shader/Basic.shader");

    shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    /* test if is picking up shader
    std::cout << "VERTEX" << std::endl;
    std::cout << source.VertexSource << std::endl;
    std::cout << "FRAGMENT" << std::endl;
    std::cout << source.FragmentSource << std::endl;
    */

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
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

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





