#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <vector>

#include "../personagens/Heroi.h"
#include "../personagens/Inimigo.h"
#include "../objetos/Parede_2d.h"

#include "../leitor_imagem/Leitor_imagem.h"

template <class T>
class Mapa {
public:
    std::vector<Parede_2d<T>> paredes;

    Heroi<T> *heroi;
    std::vector<Inimigo<T>> inimigos;

    Vec_2<T> posicao;
    Vec_2<T> saida;

    T dist_saida;

    bool venceu;

    unsigned int id_textura;
    unsigned int id_textura_saida;
    unsigned int VAO_chao;
    unsigned int EBO_chao;
    
    unsigned int VAO_paredes;
    unsigned int EBO_paredes;

    int qtd_indices_paredes;
    
    Vec_2<T> dimen_textura;
    Vec_2<T> dimen_saida;

    Mapa ( Heroi<T> *heroi, std::string nome_fundo, std::string nome_saida )
    : heroi( heroi )
    , venceu( false )
    , saida( Vec_2<T>( T(0.8), T(0.8) ) )
    , dist_saida( T(0.1) )
    {
        int largura;
        int altura;
        int n_canais;
        
        heroi->posicao = Vec_2<T>( T(-0.8), T(-0.8) );

        id_textura = ler_imagem( nome_fundo, largura, altura, n_canais );
        id_textura_saida = ler_imagem( nome_saida, largura, altura, n_canais );

        T vertices_img[] = { T(-1.0), T(-1.0), T(0.0), T(0.0),
	                         T( 1.0), T(-1.0), T(1.0), T(0.0),
	                         T( 1.0), T( 1.0), T(1.0), T(1.0),
	                         T(-1.0), T( 1.0), T(0.0), T(1.0) };
        unsigned int indices_img[] = { 0, 1, 3,
	                                   1, 2, 3 };
        int divisoes_img[] = { 2, 2 };

        std::vector<Vec_2<T>> posicoes_paredes;
        std::vector<unsigned int> indices_paredes;

        dimen_textura = Vec_2<T>( T(1), T(1) );
        dimen_saida = Vec_2<T>( dist_saida, dist_saida );
        
        VAO_chao = criar_vertice_buffer( vertices_img, sizeof(T), 4, 16, 2, divisoes_img );
	    EBO_chao = criar_element_buffer( indices_img, 6 );


        std::vector<Vec_2<T>> caminho;
        std::vector<bool> esperar;

        caminho.push_back( Vec_2<T>( T(-0.4), T(-0.8) ) );
        caminho.push_back( Vec_2<T>( T( 0.8), T(-0.8) ) );

        esperar.push_back( true );
        esperar.push_back( true );

        inimigos.push_back( Inimigo<T>( T(0.5), T( M_PI_4 / 1.5 )
                          , caminho, 0, 2000
                          , esperar, 1000
                          , 0.05f, 0.05f , "modelos/inimigo.png" ) );
        
        caminho.clear();
        caminho.push_back( Vec_2<T>( T( 0.0), T( 0.4) ) );
        caminho.push_back( Vec_2<T>( T( 0.0), T(-0.4) ) );
        
        esperar.clear();
        esperar.push_back( true );
        esperar.push_back( true );

        inimigos.push_back( Inimigo<T>( T(0.5), T( M_PI_4 / 1.5 )
                          , caminho, 0, 2000
                          , esperar, 1000
                          , 0.05f, 0.05f , "modelos/inimigo.png" ) );
        
        caminho.clear();
        caminho.push_back( Vec_2<T>( T( 0.8), T( 0.0) ) );
        caminho.push_back( Vec_2<T>( T( 0.4), T( 0.0) ) );
        
        esperar.clear();
        esperar.push_back( true );
        esperar.push_back( true );

        inimigos.push_back( Inimigo<T>( T(0.5), T( M_PI_4 )
                          , caminho, 0, 1000
                          , esperar, 1000
                          , 0.05f, 0.05f , "modelos/inimigo.png" ) );
        
        caminho.clear();
        caminho.push_back( Vec_2<T>( T(-0.4), T( 0.0) ) );
        caminho.push_back( Vec_2<T>( T(-0.4), T( 0.8) ) );
        caminho.push_back( Vec_2<T>( T(-0.8), T( 0.8) ) );
        caminho.push_back( Vec_2<T>( T(-0.8), T( 0.0) ) );
        
        esperar.clear();
        esperar.push_back( true );
        esperar.push_back( false );
        esperar.push_back( false );
        esperar.push_back( false );

        inimigos.push_back( Inimigo<T>( T(0.5), T( M_PI_4 )
                          , caminho, 0, 1000
                          , esperar, 1000
                          , 0.05f, 0.05f , "modelos/inimigo.png" ) );


        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-1.0), T(-1.0) ), T(0.004), T(2.0) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-1.0), T(-1.0) ), T(2.0), T(0.004) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-1.0), T(0.996) ), T(2.0), T(0.004) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(0.996), T(-1.0) ), T(0.004), T(2.0) ) );

        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.608), T(-1.0) ), T(0.016), T(0.4) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-1.0), T(-0.208) ), T(0.816), T(0.016) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.2), T(-0.608) ), T(0.016), T(0.416) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.2), T(-0.608) ), T(0.8), T(0.016) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T( 0.2), T(-0.208) ), T(0.8), T(0.016) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T( 0.2), T(-0.208) ), T(0.016), T(0.8) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.2), T( 0.592) ), T(0.416), T(0.016) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.2), T( 0.192) ), T(0.016), T(0.4) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T(-0.6), T( 0.192) ), T(0.016), T(0.4) ) );
        paredes.push_back( Parede_2d<T>( Vec_2<T>( T( 0.6), T( 0.2) ), T(0.016), T(0.8) ) );
        
        qtd_indices_paredes = 6 * paredes.size();
        posicoes_paredes.reserve( paredes.size() * 4 );
        indices_paredes.reserve( qtd_indices_paredes );

        for ( int i = 0; i < paredes.size(); i++ )
        {
            for ( int j = 0; j < 4; j++ )
                posicoes_paredes.push_back( paredes[i].barreiras[j].p_inicial );
            
            indices_paredes.push_back( ( i * 4 ) );
            indices_paredes.push_back( ( i * 4 ) + 1 );
            indices_paredes.push_back( ( i * 4 ) + 2 );

            indices_paredes.push_back( ( i * 4 ) + 2 );
            indices_paredes.push_back( ( i * 4 ) + 3 );
            indices_paredes.push_back( ( i * 4 ) );
        }

        VAO_paredes = criar_vertice_buffer( (T*)posicoes_paredes.data(), sizeof(T), 2, posicoes_paredes.size() * 2, 1 );
        EBO_paredes = criar_element_buffer( indices_paredes.data(), indices_paredes.size() );
    }

    void restart ( unsigned int tempo )
    {
        heroi->posicao = Vec_2<T>( T(-0.8), T(-0.8) );

        for ( int i = 0; i < inimigos.size(); i++ ) {
            inimigos[i].restart( tempo );
        }

        venceu = false;
    }

    void mostrar_ambiente ( const Shader &shader )
    {
        usar_vertice_buffer( VAO_chao );
        usar_element_buffer( EBO_chao );
        
        mudarVec2_fv( shader, "posicao_objeto", posicao.coord );
        mudarVec2_fv( shader, "dimen", dimen_textura.coord );
        
        glBindTexture( GL_TEXTURE_2D, id_textura );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );


        mudarVec2_fv( shader, "posicao_objeto", saida.coord );
        mudarVec2_fv( shader, "dimen", dimen_saida.coord );
        
        glBindTexture( GL_TEXTURE_2D, id_textura_saida );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }

    void mostrar_paredes ( const Shader &shader )
    {
        usar_vertice_buffer( VAO_paredes );
        usar_element_buffer( EBO_paredes );

		glDrawElements( GL_TRIANGLES, qtd_indices_paredes, GL_UNSIGNED_INT, (void*)0 );
    }

    void mostrar_personagens ( const Shader &shader )
    {
        heroi->mostrar_personagem( shader );

        for ( auto i : inimigos )
            i.mostrar_personagem( shader );
    }

    void mostrar_auxiliares ( const Shader &shader )
    {
        std::string nome_id;

        mudar_i( shader, "qtd_barreiras", paredes.size() * 4 );

        for ( int i = 0; i < paredes.size(); i++ ) {
		    for ( int j = 0; j < 4; j++ )
		    {
		    	nome_id = std::to_string( ( i * 4 ) + j );

		    	mudarVec2_fv( shader, "barreiras[" + nome_id + "].pos_1", paredes[i].barreiras[j].p_final.coord );
		    	mudarVec2_fv( shader, "barreiras[" + nome_id + "].pos_2", paredes[i].barreiras[j].p_inicial.coord );
		    }
        }
        
        for ( auto i : inimigos )
            i.mostrar_auxiliar( shader );
    }

    void loop ( unsigned int tempo )
    {
        bool perdeu = false;

        if ( !venceu ) {
            for ( int i = 0; i < inimigos.size(); i++ ) {
                perdeu = perdeu || inimigos[i].posicao_vista( heroi->posicao
                                                            , (Vec_2<T>*)paredes.data(), paredes.size() * 4 );
                if ( perdeu )
                    break;
                inimigos[i].loop( tempo );
            }

            if ( perdeu )
                restart( tempo );
            
            if ( norma( heroi->posicao - saida ) < dist_saida ) {
                venceu = true;
                std::cout << "Você ganhou!!!!!!! ^.^"
                          << std::endl
                          << "Aperte barra de espaço caso queira jogar novamente!"
                          << std::endl;
            }
        }
    }
};

#endif