#include "Shader.h"

Shader::Shader ( const char *verticeShader, const char *fragmentoShader ) {
	std::string codigoVertice;
	std::string codigoFragmento;
	std::fstream arquivoVertice;
	std::fstream arquivoFragmento;
	
	arquivoVertice.exceptions(std::fstream::failbit | std::fstream::badbit);
	arquivoFragmento.exceptions(std::fstream::failbit | std::fstream::badbit);
	
	try {
		arquivoVertice.open(verticeShader);
		arquivoFragmento.open(fragmentoShader);
		
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;
		
		vShaderStream << arquivoVertice.rdbuf();
		fShaderStream << arquivoFragmento.rdbuf();
		
		arquivoVertice.close();
		arquivoFragmento.close();
		
		codigoVertice = vShaderStream.str();
		codigoFragmento = fShaderStream.str();
	} catch (std::fstream::failure erro) {
		 std::cout << "SHADER ERRO: NÃO FOI POSSÍVEL ABRIR OS ARQUIVOS" << std::endl;
	}
	
	const char *codigoVShader = codigoVertice.c_str();
	const char *codigoFShader = codigoFragmento.c_str();
	
	unsigned int vertice;
	unsigned int fragmento;
	int sucesso;
	char logErro[512];
	
	vertice = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertice, 1, &codigoVShader, nullptr);
	glCompileShader(vertice);
	
	glGetShaderiv(vertice, GL_COMPILE_STATUS, &sucesso);
	
	if (!sucesso) {
		glGetShaderInfoLog(vertice, 512, nullptr, logErro);
		std::cout << "ERRO: FALHA AO COMPILAR O SHADER VERTICE\n" << logErro << std::endl;
	}
	
	fragmento = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmento, 1, &codigoFShader, nullptr);
	glCompileShader(fragmento);
	
	glGetShaderiv(fragmento, GL_COMPILE_STATUS, &sucesso);
	
	if (!sucesso) {
		glGetShaderInfoLog(fragmento, 512, nullptr, logErro);
		std::cout << "ERRO: FALHA AO COMPILAR O SHADER FRAGMENTO\n" << logErro << std::endl;
	}
	
	id = glCreateProgram();
	glAttachShader(id, vertice);
	glAttachShader(id, fragmento);
	glLinkProgram(id);
	
	glGetProgramiv(id, GL_LINK_STATUS, &sucesso);
	
	if (!sucesso) {
		glGetProgramInfoLog(id, 512, nullptr, logErro);
		std::cout << "ERRO: FALHA AO LIGAR O PROGRAMA\n" << logErro << std::endl;
	}
	
	glDeleteShader(vertice);
	glDeleteShader(fragmento);
}
/*===============================================================================================================================*/
void Shader::usar () {
	glUseProgram(id);
}
/*===============================================================================================================================*/
void Shader::desusar () {
	glUseProgram(0);
}
/*===============================================================================================================================*/
void mudar_i ( const Shader &shader, const std::string &nome, int valor ) {
	glUniform1i(glGetUniformLocation(shader.id, nome.c_str()), valor);
}
/*===============================================================================================================================*/
void mudar_ui ( const Shader &shader, const std::string &nome, unsigned int valor ) {
	glUniform1ui(glGetUniformLocation(shader.id, nome.c_str()), valor);
}
/*===============================================================================================================================*/
void mudar_f ( const Shader &shader, const std::string &nome, float valor ) {
	glUniform1f(glGetUniformLocation(shader.id, nome.c_str()), valor);
}
/*===============================================================================================================================*/
void mudarVec2_i ( const Shader &shader, const std::string &nome, int v0, int v1 ) {
	glUniform2i(glGetUniformLocation(shader.id, nome.c_str()), v0, v1);
}
/*===============================================================================================================================*/
void mudarVec2_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1 ) {
	glUniform2ui(glGetUniformLocation(shader.id, nome.c_str()), v0, v1);
}
/*===============================================================================================================================*/
void mudarVec2_f ( const Shader &shader, const std::string &nome, float v0, float v1 ) {
	glUniform2f(glGetUniformLocation(shader.id, nome.c_str()), v0, v1);
}
/*===============================================================================================================================*/
void mudarVec2_iv ( const Shader &shader, const std::string &nome, int *vetor, int count ) {
	glUniform2iv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec2_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count ) {
	glUniform2uiv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec2_fv ( const Shader &shader, const std::string &nome, float *vetor, int count ) {
	glUniform2fv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec3_i ( const Shader &shader, const std::string &nome, int v0, int v1, int v2 ) {
	glUniform3i(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2);
}
/*===============================================================================================================================*/
void mudarVec3_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1, unsigned int v2 ) {
	glUniform3ui(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2);
}
/*===============================================================================================================================*/
void mudarVec3_f ( const Shader &shader, const std::string &nome, float v0, float v1, float v2 ) {
	glUniform3i(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2);
}
/*===============================================================================================================================*/
void mudarVec3_iv ( const Shader &shader, const std::string &nome, int *vetor, int count ) {
	glUniform3iv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec3_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count ) {
	glUniform3uiv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec3_fv ( const Shader &shader, const std::string &nome, float *vetor, int count ) {
	glUniform3fv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec4_i ( const Shader &shader, const std::string &nome, int v0, int v1, int v2, int v3 ) {
	glUniform4i(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2, v3);
}
/*===============================================================================================================================*/
void mudarVec4_ui ( const Shader &shader, const std::string &nome, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3 ) {
	glUniform4ui(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2, v3);
}
/*===============================================================================================================================*/
void mudarVec4_f ( const Shader &shader, const std::string &nome, float v0, float v1, float v2, float v3 ) {
	glUniform4f(glGetUniformLocation(shader.id, nome.c_str()), v0, v1, v2, v3);
}
/*===============================================================================================================================*/
void mudarVec4_iv ( const Shader &shader, const std::string &nome, int *vetor, int count ) {
	glUniform4iv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec4_uiv ( const Shader &shader, const std::string &nome, unsigned int *vetor, int count ) {
	glUniform4uiv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarVec4_fv ( const Shader &shader, const std::string &nome, float *vetor, int count ) {
	glUniform4fv(glGetUniformLocation(shader.id, nome.c_str()), count, vetor);
}
/*===============================================================================================================================*/
void mudarMatriz2 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix2fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz3 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix3fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz4 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix4fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz2x3 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix2x3fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz3x2 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix3x2fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz2x4 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix2x4fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz4x2 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix4x2fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz3x4 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix3x4fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
void mudarMatriz4x3 ( const Shader &shader, const std::string &nome, float *matriz, int count, bool transpor ) {
	glUniformMatrix4x3fv(glGetUniformLocation(shader.id, nome.c_str()), count, transpor, matriz);
}
/*===============================================================================================================================*/
