#pragma once
#include "../BaseGame.h"

#include "Entity/Entity.h"

class Renderer 
{

public:
	Renderer();
	~Renderer();

	void initBuffers();
	void initShader();
	void Render();

private:

};

static unsigned int CompileShader(unsigned int type, const std::string& source);

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

extern unsigned int shader;