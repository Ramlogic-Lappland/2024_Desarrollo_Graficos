#include "Renderer.h"

Renderer::Renderer(){

}

Renderer::~Renderer() {

}

void Renderer::initBuffers() {

	unsigned int buffer;

	float triangle[6] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f
	};

	glGenBuffers(1, &buffer); //renderer
	glBindBuffer(GL_ARRAY_BUFFER, buffer); //renderer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), triangle, GL_STATIC_DRAW); //renderer

	glEnableVertexAttribArray(0);  //renderer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //renderer
}

void Renderer::Render() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}


/*
* 	// Shader
	static unsigned int CompileShader(unsigned int type, const std::string & source)
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

	static unsigned int CreateShader(const std::string & vertexShader, const std::string & fragmentShader)
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

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main() \n"
		"{\n"
		"gl_Position = position;\n"
		"}\n";


	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main()\n"
		"{\n"
		"color {1.0, 0.0, 0.0, 1.0}\n"
		"}\n";



	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

*/

