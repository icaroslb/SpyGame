#ifndef ENGINE_OPENGL_H
#define ENGINE_OPENGL_H

#include <GL/glew.h>
#include <vector>

class Engine_OpenGl {
	std::vector<unsigned int> VAOs,
	                          VBOs,
	                          EBOs;
public:
	Engine_OpenGl ();
	
	unsigned int criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data = nullptr, int uso = GL_STATIC_DRAW );
	unsigned int criar_element_buffer ( unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso = GL_STATIC_DRAW );
	void reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data );
	void atualizar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void usar_vertice_buffer ( int id );
	void usar_element_buffer ( int id );
	
	void desusar_vertice_buffer ();
	void desusar_element_buffer ();
};

unsigned int criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data = nullptr, int uso = GL_STATIC_DRAW );
unsigned int criar_element_buffer ( unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso = GL_STATIC_DRAW );
void reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data );
void atualizar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void usar_vertice_buffer ( int id );
void usar_element_buffer ( int id );

void desusar_vertice_buffer ();
void desusar_element_buffer ();

#endif
