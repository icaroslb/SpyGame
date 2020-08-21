#ifndef HEROI_H
#define HEROI_H

#include "Personagem.h"

template <class T>
class Heroi : public Personagem<T> {
public:
    Vec_2<T> tamanho_textura;
    unsigned int id_textura;

    Heroi ( const Vec_2<T> &posicao, T largura, T altura, std::string nome_img )
    : Personagem<T>( posicao, 0, 0 )
    {
        int text_largura;
        int text_altura;
        int text_n_canais;

        Vec_2<T> vertices[8];
        unsigned int indices_vertices[6] = { 0, 1, 2
                                           , 2, 3, 0 };
        int divisoes_img[2] = { 2, 2 };

        tamanho_textura = Vec_2<T>( largura / T( 2 ), altura / T( 2 ) );

        id_textura = ler_imagem( nome_img, text_largura, text_altura, text_n_canais );

        vertices[0] = Vec_2<T>( T(-1), T( 1) ); vertices[1] = Vec_2<T>( T(0.0), T(1.0) );
        vertices[2] = Vec_2<T>( T(-1), T(-1) ); vertices[3] = Vec_2<T>( T(0.0), T(0.0) );
        vertices[4] = Vec_2<T>( T( 1), T(-1) ); vertices[5] = Vec_2<T>( T(1.0), T(0.0) );
        vertices[6] = Vec_2<T>( T( 1), T( 1) ); vertices[7] = Vec_2<T>( T(1.0), T(1.0) );

        Personagem<T>::VAO = criar_vertice_buffer( vertices, sizeof(T), 4, 16, 2, divisoes_img );
	    Personagem<T>::EBO = criar_element_buffer( indices_vertices, 6 );
    }

    void mover ( const Vec_2<T> &direcao, T magnitude )
    {
        Personagem<T>::posicao += direcao * magnitude;
    }

    void mostrar_personagem ( const Shader &shader )
    {
        usar_vertice_buffer( Personagem<T>::VAO );
		usar_element_buffer( Personagem<T>::EBO );

        glBindTexture( GL_TEXTURE_2D, id_textura );

        mudarVec2_fv( shader, "posicao_objeto", Personagem<T>::posicao.coord );
        mudarVec2_fv( shader, "dimen", tamanho_textura.coord );

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }

    void mostrar_auxiliar ( const Shader &shader )
    {}
};

#endif