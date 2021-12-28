#pragma once
#include <glad/glad.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader
{
public:

	Shader(const std::string& bodyPiece_sourceCode, const std::string& bodyPieceColor_sourceCode);



	void use();

	unsigned int getID()const;

private:
	void compileShader(unsigned int& shader, const int shaderType, const char* codeStorage, const std::string& identifier);

	void checkCompileErrors(unsigned int shader, const std::string& type);

	unsigned int ID;
};