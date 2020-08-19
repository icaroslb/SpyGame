#include <iostream>
#include "camera/Camera.h"
#include "engines/Engine_OpenGl.h"
#include "engines/Engine_SDL.h"
#include "shaders/Shader.h"

#include "fisica/fisica_vetor.h"
#include "objetos/Barreira_2d.h"

#include "io/Teclado.h"

#include "objetos/Plano_2d.h"
#include "personagens/Heroi.h"

int main (int argc, char *argv[]) {
    Camera<float> camera( Vec_3f(  0.0f,  0.0f,  0.0f ), // Posição
	                      Vec_3f(  0.0f,  0.0f,  1.0f ), // Look at
	                      Vec_3f(  0.0f,  1.0f,  0.0f ), // View up
	                      -5.0f, 5.0f,                   // Esquerda e direita
	                      -5.0f, 5.0f,                   // Baixo e cima
	                      -1.0f, 1.0f, ORTHO );          // Near, far e o tipo de visão*
    
    Engine_SDL tela( "Projeto", 500, 500 );
	Engine_OpenGl opengl;
	Shader shader( "shaders/shader.vs", "shaders/shader.fs" );
	Shader textura_shader( "shaders/textura_shader.vs", "shaders/textura_shader.fs" );
	
	SDL_Event evento;
	bool loop = true;

	unsigned int velho_tempo = 0;
	unsigned int novo_tempo = 0;
	const Uint8 *estado_teclado;

	float fator_tempo = 0.0f;

	printf( "Versão do OpenGl: %s\n", tela.obter_versao_opengl() );

	Plano_2d<float> fundo( Vec_2f(  1.0f,  1.0f )
	                     , Vec_2f(  1.0f, -1.0f )
						 , Vec_2f( -1.0f, -1.0f )
						 , Vec_2f( -1.0f,  1.0f )
						 );

	Vec_2f posicao;
	Vec_2f direcao;
	float t = 0;

	float distancia_colisao;
	float distancia_colisao_aux;
	size_t menor_distancia_colisao_id;

	Barreira_2d<float> barreiras[4];
	
	Teclado teclado;

	Heroi<float> heroi( Vec_2f(0.0f, 0.0f), 0.05f, 0.05f, "modelos/Heroi.png" );

	barreiras[0] = Barreira_2d<float>( Vec_2f( -0.2f,  0.2f ), Vec_2f(  0.2f,  0.2f ) );
	barreiras[1] = Barreira_2d<float>( Vec_2f(  0.2f,  0.2f ), Vec_2f(  0.2f, -0.2f ) );
	barreiras[2] = Barreira_2d<float>( Vec_2f(  0.2f, -0.2f ), Vec_2f( -0.2f, -0.2f ) );
	barreiras[3] = Barreira_2d<float>( Vec_2f( -0.2f, -0.2f ), Vec_2f( -0.2f,  0.2f ) );
	
	while ( loop ) {

		while ( SDL_PollEvent( &evento ) ) {

			if ( evento.type == SDL_QUIT ) {
				loop = false;
			} else {
				if ( evento.key.state == SDL_PRESSED ) {
					if ( !teclado.obter_estado( evento.key.keysym.sym ) )
						teclado.mudar_estado( evento.key.keysym.sym );
				}
				if ( evento.key.state == SDL_RELEASED ) {
					teclado.mudar_estado( evento.key.keysym.sym );
				}
			}
		}

		/********************************TECLADO********************************/
		velho_tempo = novo_tempo;
		novo_tempo = SDL_GetTicks();
		fator_tempo = float( novo_tempo - velho_tempo ) * 0.0005f;
		
		Vec_2f direcao;
		Vec_2f pos_aux;
		bool colidiu;

		SDL_PumpEvents();
		estado_teclado = SDL_GetKeyboardState( NULL );

		if ( estado_teclado[SDL_SCANCODE_W] )
			direcao += Vec_2f( 0.0f, 1.0f );

		if ( estado_teclado[SDL_SCANCODE_A] )
			direcao += Vec_2f( -1.0f, 0.0f );

		if ( estado_teclado[SDL_SCANCODE_S] )
			direcao += Vec_2f( 0.0f, -1.0f );
			
		if ( estado_teclado[SDL_SCANCODE_D] )
			direcao += Vec_2f( 1.0f, 0.0f );
			
		direcao = unitario( direcao );
		pos_aux = heroi.posicao + ( direcao * fator_tempo );
		do {
			colidiu = false;

			distancia_colisao = std::numeric_limits<float>::infinity();
			distancia_colisao_aux = 0.0f;

			for ( size_t i = 0; i < 4; i++ ) {
				if ( teste_colisao( heroi.posicao, pos_aux
				                  , barreiras[i].p_inicial, barreiras[i].p_final
								  , barreiras[i].normal, distancia_colisao_aux ) ) {		
					
					if ( distancia_colisao > distancia_colisao_aux
					&&   distancia_colisao_aux > 1.0e-3f ) {
						distancia_colisao = distancia_colisao_aux;
						menor_distancia_colisao_id = i;
					}
					colidiu = true;
				}
			}

			if ( colidiu ) {
				
				if ( !isinf( distancia_colisao ) )
					pos_aux = heroi.posicao + ( direcao * distancia_colisao * 0.99f );
				else
					pos_aux = heroi.posicao;
				direcao = colisao( direcao, barreiras[menor_distancia_colisao_id].normal, 1.0f, 0.0f );
			}

		} while ( colidiu );
		heroi.posicao = pos_aux;

		/***********************************************************************/
		/*********************************PRINT*********************************/

		glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		textura_shader.usar();

		heroi.mostrar( textura_shader );
		
		shader.usar();

		direcao._x = float( cos(t) * 0.5 );
		direcao._y = float( sin(t) * 0.5 );

		direcao = unitario( direcao );

		mudarVec2_fv( shader, "posicao_objeto", posicao.coord );
		mudarVec2_fv( shader, "direcao", unitario( direcao ).coord );
		mudar_f( shader, "raio", 0.5f );
		mudar_f( shader, "abertura", cos( M_PI_4 * 0.25 ) );

		
		mudarVec2_fv( shader, "barreiras[0].pos_1", barreiras[0].p_inicial.coord );
		mudarVec2_fv( shader, "barreiras[0].pos_2", barreiras[0].p_final.coord );
		mudarVec2_fv( shader, "barreiras[1].pos_1", barreiras[1].p_inicial.coord );
		mudarVec2_fv( shader, "barreiras[1].pos_2", barreiras[1].p_final.coord );
		mudarVec2_fv( shader, "barreiras[2].pos_1", barreiras[2].p_inicial.coord );
		mudarVec2_fv( shader, "barreiras[2].pos_2", barreiras[2].p_final.coord );
		mudarVec2_fv( shader, "barreiras[3].pos_1", barreiras[3].p_inicial.coord );
		mudarVec2_fv( shader, "barreiras[3].pos_2", barreiras[3].p_final.coord );

		
		fundo.mostrar();

		tela.swap_tela();

		t += 0.01f;
	}

    return 0;
}