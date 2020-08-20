#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <vector>

#include "../personagens/Heroi.h"
#include "../personagens/Inimigo.h"
#include "../objetos/Barreira_2d.h"

#include "../leitor_imagem/Leitor_imagem.h"

template <class T>
class Mapa {
public:
    std::vector<Barreira_2d<T>> barreiras;

    Heroi<T> *heroi;
    std::vector<Inimigo<T>> inimigos;

    Vec_2<T> posicao;

    unsigned int id_textura;
    unsigned int VAO;
    unsigned int EBO;

    Mapa ( Heroi<T> *heroi, std::string nome_fundo )
    : heroi( heroi )
    {
        int largura;
        int altura;
        int n_canais;
        
        heroi->posicao = Vec_2<T>( T(-1), T(-1) );

        id_textura = ler_imagem( nome_fundo, largura, altura, n_canais );

        T vertices_img[] = { T(-1.0), T(-1.0), T(0.0), T(0.0),
	                         T( 1.0), T(-1.0), T(1.0), T(0.0),
	                         T( 1.0), T( 1.0), T(1.0), T(1.0),
	                         T(-1.0), T( 1.0), T(0.0), T(1.0) };
        unsigned int indices_img[] = { 0, 1, 3,
	                                   1, 2, 3 };
        int divisoes_img[] = { 2, 2 };
        
        VAO = criar_vertice_buffer( vertices_img, sizeof(T), 4, 16, 2, divisoes_img );
	    EBO = criar_element_buffer( indices_img, 6 );
    }

    void restart ()
    {
        heroi->posicao = Vec_2<T>( T(-1), T(-1) );
    }

    void mostrar_ambiente ( const Shader &shader )
    {
        usar_vertice_buffer( VAO );
        usar_element_buffer( EBO );
        
        mudarVec2_fv( shader, "posicao_objeto", posicao.coord );
        
        glBindTexture( GL_TEXTURE_2D, id_textura );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }

    void mostrar_personagens ( const Shader &shader )
    {
        heroi->mostrar( shader );
    }

    void mostrar_auxiliares ()
    {}
};

#endif