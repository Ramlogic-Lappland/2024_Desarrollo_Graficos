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