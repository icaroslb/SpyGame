#include "Engine_OpenGl.h"

Engine_OpenGl::Engine_OpenGl () {
	glEnable( GL_PROGRAM_POINT_SIZE );
	glEnable( GL_BLEND );
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
/*===============================================================================================================================*/
unsigned int Engine_OpenGl::criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data, int uso ) {
	unsigned int novaVAO, novaVBO;
	int pos_mem = 0;
	
	if ( tam_sub_data == nullptr )
		tam_sub_data = &qtd_data;
	
	glGenVertexArrays( 1, &novaVAO );
	glBindVertexArray( novaVAO );
	
	glGenBuffers( 1, &novaVBO );
	glBindBuffer( GL_ARRAY_BUFFER, novaVBO );
	
	glBufferData( GL_ARRAY_BUFFER, ( tam_array * tam_data ), vertices, uso );
	
	for ( int i = 0; i < qtd_sub_data; i++ ) {
		glVertexAttribPointer( i, tam_sub_data[i], GL_FLOAT, GL_FALSE, tam_data * qtd_data, (void*)pos_mem );
		glEnableVertexAttribArray( i );
		
		pos_mem += tam_sub_data[i] * tam_data;
	}
	
	VAOs.push_back( novaVAO );
	VBOs.push_back( novaVBO );
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
	
	return VAOs.size() - 1;
}
/*===============================================================================================================================*/
unsigned int Engine_OpenGl::criar_element_buffer ( unsigned int *indices, int qtd, int uso ) {
	unsigned int novaEBO;
	
	glGenBuffers( 1, &novaEBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, novaEBO );
	
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * qtd, indices, uso );
	
	EBOs.push_back( novaEBO );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
	
	return EBOs.size() - 1;
}
/*===============================================================================================================================*/
void Engine_OpenGl::reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso ) {
	glBindVertexArray( VAOs[id] );
	glBindBuffer( GL_ARRAY_BUFFER, VBOs[id] );
	
	glBufferData( GL_ARRAY_BUFFER, tam_data * qtd_data, vertices, uso );
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void Engine_OpenGl::reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBOs[id] );
	
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * qtd, indices, uso );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/
void Engine_OpenGl::atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data ) {
	glBindVertexArray( VAOs[id] );
	glBindBuffer( GL_ARRAY_BUFFER, VBOs[id] );
	
	glBufferSubData( GL_ARRAY_BUFFER, ini_data * tam_data, tam_data * qtd_data, vertices_atu );
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void Engine_OpenGl::atualizar_element_buffer ( int id, unsigned int *vertices_atu, int ini_data, int qtd_data ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBOs[id] );
	
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, ini_data * sizeof(unsigned int), sizeof(unsigned int) * qtd_data, vertices_atu );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/
void Engine_OpenGl::usar_vertice_buffer ( int id ) {
	glBindVertexArray( VAOs[id] );
}
/*===============================================================================================================================*/
void Engine_OpenGl::usar_element_buffer ( int id ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBOs[id] );
}
/*===============================================================================================================================*/
void Engine_OpenGl::desusar_vertice_buffer () {
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void Engine_OpenGl::desusar_element_buffer () {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/


unsigned int criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data, int uso ) {
	unsigned int novaVAO, novaVBO;
	int pos_mem = 0;
	
	if ( tam_sub_data == nullptr )
		tam_sub_data = &qtd_data;
	
	glGenVertexArrays( 1, &novaVAO );
	glBindVertexArray( novaVAO );
	
	glGenBuffers( 1, &novaVBO );
	glBindBuffer( GL_ARRAY_BUFFER, novaVBO );
	
	glBufferData( GL_ARRAY_BUFFER, ( tam_array * tam_data ), vertices, uso );
	
	for ( int i = 0; i < qtd_sub_data; i++ ) {
		glVertexAttribPointer( i, tam_sub_data[i], GL_FLOAT, GL_FALSE, tam_data * qtd_data, (void*)pos_mem );
		glEnableVertexAttribArray( i );
		
		pos_mem += tam_sub_data[i] * tam_data;
	}
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
	
	return novaVAO;
}
/*===============================================================================================================================*/
unsigned int criar_element_buffer ( unsigned int *indices, int qtd, int uso ) {
	unsigned int novaEBO;
	
	glGenBuffers( 1, &novaEBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, novaEBO );
	
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * qtd, indices, uso );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
	
	return novaEBO;
}
/*===============================================================================================================================*/
void reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso ) {
	glBindVertexArray( id );
	glBindBuffer( GL_ARRAY_BUFFER, id );
	
	glBufferData( GL_ARRAY_BUFFER, tam_data * qtd_data, vertices, uso );
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id );
	
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * qtd, indices, uso );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/
void atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data ) {
	glBindVertexArray( id );
	glBindBuffer( GL_ARRAY_BUFFER, id );
	
	glBufferSubData( GL_ARRAY_BUFFER, ini_data * tam_data, tam_data * qtd_data, vertices_atu );
	
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void atualizar_element_buffer ( int id, unsigned int *vertices_atu, int ini_data, int qtd_data ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id );
	
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, ini_data * sizeof(unsigned int), sizeof(unsigned int) * qtd_data, vertices_atu );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/
void usar_vertice_buffer ( int id ) {
	glBindVertexArray( id );
}
/*===============================================================================================================================*/
void usar_element_buffer ( int id ) {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id );
}
/*===============================================================================================================================*/
void desusar_vertice_buffer () {
	glBindVertexArray( 0 );
}
/*===============================================================================================================================*/
void desusar_element_buffer () {
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
/*===============================================================================================================================*/
