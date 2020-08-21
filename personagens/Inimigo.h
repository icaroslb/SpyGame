#ifndef INIMIGO_H
#define INIMIGO_H

#include "Personagem.h"

template <class T>
class Inimigo : public Personagem<T> {
public:
    Vec_2<T> tamanho_textura;
    Vec_2<T> dimen;

    Vec_2<T> direcao;
    T tamanho;
    T angulo;

    unsigned int tempo_caminho;
    std::vector<Vec_2<T>> caminho;
    std::vector<bool> esperar;
    unsigned int tempo_inicial;
    unsigned int tempo_espera;
    T dist_caminhar;

    int estado;
    bool esperando;

    unsigned int id_textura;
    
    Inimigo ( T tamanho, T angulo
            , std::vector<Vec_2<T>> caminho, unsigned int tempo_inicial, unsigned int tempo_caminho
            , std::vector<bool> esperar, unsigned int tempo_espera
            , T largura, T altura, std::string nome_img )
    : Personagem<T>()
    , tamanho( tamanho )
    , angulo( cos( angulo ) )
    , estado( -1 )
    , caminho( caminho )
    , tempo_inicial( tempo_inicial )
    , tempo_caminho( tempo_caminho )
    , esperar( esperar )
    , tempo_espera( tempo_espera )
    , esperando( false )
    {
        int text_largura;
        int text_altura;
        int text_n_canais;

        Vec_2<T> vertices[8];
        unsigned int indices_vertices[6] = { 0, 1, 2
                                           , 2, 3, 0 };
        int divisoes_img[2] = { 2, 2 };

        tamanho_textura = Vec_2<T>( largura / T( 2 ), altura / T( 2 ) );
        dimen = Vec_2<T>( tamanho, tamanho );

        id_textura = ler_imagem( nome_img, text_largura, text_altura, text_n_canais );

        vertices[0] = Vec_2<T>( T(-1), T( 1) ); vertices[1] = Vec_2<T>( T(0.0), T(1.0) );
        vertices[2] = Vec_2<T>( T(-1), T(-1) ); vertices[3] = Vec_2<T>( T(0.0), T(0.0) );
        vertices[4] = Vec_2<T>( T( 1), T(-1) ); vertices[5] = Vec_2<T>( T(1.0), T(0.0) );
        vertices[6] = Vec_2<T>( T( 1), T( 1) ); vertices[7] = Vec_2<T>( T(1.0), T(1.0) );

        Personagem<T>::VAO = criar_vertice_buffer( vertices, sizeof(T), 4, 16, 2, divisoes_img );
	    Personagem<T>::EBO = criar_element_buffer( indices_vertices, 6 );

        atualizar_caminho();
        Personagem<T>::posicao = caminho[0];
    }

    void mover ( const Vec_2<T> &direcao, T magnitude )
    {
        Personagem<T>::posicao += direcao * magnitude;
    }

    void loop ( unsigned int tempo )
    {
        const unsigned int dif_tempo = tempo - tempo_inicial;
        T caminhado;
        
        if ( !esperando ) {
            if ( dif_tempo <= tempo_caminho ) {
                caminhado = T(dif_tempo) / T(tempo_caminho);
            } else {
                caminhado = T(0);
                tempo_inicial += tempo_caminho;
                atualizar_caminho( !esperar[( estado + 1 ) % esperar.size()] );
                esperando = esperar[estado];
            }
        } else {
            if ( dif_tempo > tempo_espera ) {
                esperando = false;
                tempo_inicial += tempo_espera;
                atualizar_direcao();
            }
        }

        Personagem<T>::posicao = caminho[estado] + ( direcao * dist_caminhar * caminhado );
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
    {
        usar_vertice_buffer( Personagem<T>::VAO );
		usar_element_buffer( Personagem<T>::EBO );

        mudarVec2_fv( shader, "posicao", Personagem<T>::posicao.coord );
        mudarVec2_fv( shader, "dimen", dimen.coord );

		mudarVec2_fv( shader, "direcao", direcao.coord );
		mudar_f( shader, "raio", tamanho );
		mudar_f( shader, "abertura", angulo );

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }

    void atualizar_caminho ( bool atu_direcao = true )
    {
        estado = ( estado + 1 ) % caminho.size();
        if ( atu_direcao ) {
            atualizar_direcao();
        }
    }

    void atualizar_direcao ()
    {
        direcao = caminho[( estado + 1 ) % caminho.size()] - caminho[estado];
        dist_caminhar = norma( direcao );
        direcao = unitario( direcao );
    }

    bool posicao_vista ( Vec_2<T> pos )
    {
        const Vec_2<T> direcao_pos = pos - Personagem<T>::posicao;
        const Vec_2<T> direcao_uni = unitario( direcao_pos );

        if ( norma( direcao_pos ) <= tamanho
        && produto_escalar( direcao_uni, direcao ) >= angulo )
            return true;
        return false;
    }

    void restart ( unsigned int tempo )
    {
        estado = -1;
        tempo_inicial = tempo;
        esperando = false;

        atualizar_caminho();
        Personagem<T>::posicao = caminho[estado];
    }
};

#endif