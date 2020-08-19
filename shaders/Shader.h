#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Shader {
public:
	unsigned int id;
	
	Shader ( const char *verticeShader, const char *fragmentoShader );
	void usar ();
	void desusar ();
};

void mudar_i ( const Shader &shader, const std::string &nome, int valor );
void mudar_ui ( const Shader &shader, const std::string &nome, unsigned int valor );
void mudar_f ( const Shader &shader, const std::string &nome, float valor );


void mudarVec2_i ( const Shader &shader, const std::string &nome, int v0, int v1 );
void mudarVec2_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1 );
void mudarVec2_f ( const Shader &shader, const std::string &nome, float v0, float v1 );

void mudarVec2_iv ( const Shader &shader, const std::string &nome, int *vetor, int count = 1 );
void mudarVec2_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count = 1 );
void mudarVec2_fv ( const Shader &shader, const std::string &nome, float *vetor, int count = 1 );


void mudarVec3_i ( const Shader &shader, const std::string &nome, int v0, int v1, int v2 );
void mudarVec3_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1, unsigned int v2 );
void mudarVec3_f ( const Shader &shader, const std::string &nome, float v0, float v1, float v2 );

void mudarVec3_iv ( const Shader &shader, const std::string &nome, int *vetor, int count = 1 );
void mudarVec3_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count = 1 );
void mudarVec3_fv ( const Shader &shader, const std::string &nome, float *vetor, int count = 1 );


void mudarVec4_i ( const Shader &shader, const std::string &nome, int v0, int v1, int v2, int v3 );
void mudarVec4_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3 );
void mudarVec4_f ( const Shader &shader, const std::string &nome, float v0, float v1, float v2, float v3 );

void mudarVec4_iv ( const Shader &shader, const std::string &nome, int *vetor, int count = 1 );
void mudarVec4_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count = 1 );
void mudarVec4_fv ( const Shader &shader, const std::string &nome, float *vetor, int count = 1 );


void mudarMatriz2 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz3 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz4 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );

void mudarMatriz2x3 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz3x2 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz2x4 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz4x2 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz3x4 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );
void mudarMatriz4x3 ( const Shader &shader, const std::string &nome, float *matriz, int count = 1, bool transpor = false );

#endif
