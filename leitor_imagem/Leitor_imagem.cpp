#define STB_IMAGE_IMPLEMENTATION
#include "Leitor_imagem.h"

unsigned int ler_imagem ( std::string nome_imagem, int &largura, int &altura, int &n_canais ) {
	unsigned int id;
	unsigned char *data;
	
	stbi_set_flip_vertically_on_load(true);
	
	glGenTextures( 1, &id );
	glBindTexture( GL_TEXTURE_2D, id );
	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	
	data = stbi_load( nome_imagem.data(), &largura, &altura, &n_canais, 0 );
	
	if ( data ) {
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, largura, altura, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
    	glGenerateMipmap( GL_TEXTURE_2D );
	} else {
		std::cout << "Falha ao ler a imagem " << nome_imagem << "!" << std::endl;
	}
	
	stbi_image_free( data );
	
	return id;
}
