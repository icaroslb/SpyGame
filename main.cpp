#include <iostream>
#include <string>
#include "camera/Camera.h"
#include "engines/Engine_OpenGl.h"
#include "engines/Engine_SDL.h"
#include "shaders/Shader.h"

#include "fisica/fisica_vetor.h"
#include "objetos/Parede_2d.h"

#include "io/Teclado.h"

#include "objetos/Plano_2d.h"
#include "mapas/Mapa.h"

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
	Shader normal_shader( "shaders/normal_shader.vs", "shaders/normal_shader.fs" );
	
	SDL_Event evento;
	bool loop = true;

	unsigned int velho_tempo = 0;
	unsigned int novo_tempo = 0;
	const Uint8 *estado_teclado;

	float fator_tempo = 0.0f;

	printf( "Versão do OpenGl: %s\n", tela.obter_versao_opengl() );

	Vec_2f posicao;
	Vec_2f direcao;
	Vec_2f normal;
	Vec_2f normal_aux;
	float t = 0;

	float distancia_colisao;
	float distancia_colisao_aux;
	size_t menor_distancia_colisao_id;

	Parede_2d<float> parede( Vec_2f( -0.2f, -0.2f ), 0.4f, 0.4f );
	
	Teclado teclado;

	Heroi<float> heroi( Vec_2f(0.0f, 0.0f), 0.05f, 0.05f, "modelos/heroi.png" );

	Mapa<float> mapa( &heroi, "modelos/chao.png", "modelos/saida.png" );

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

				switch ( evento.key.keysym.sym )
				{
				case SDLK_SPACE:
					if ( mapa.venceu )
						mapa.restart( novo_tempo );
				break;
				
				default:
				break;
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

		if ( !mapa.venceu ) {
			mapa.loop( novo_tempo );

			if ( estado_teclado[SDL_SCANCODE_W] || estado_teclado[SDL_SCANCODE_UP] )
				direcao += Vec_2f( 0.0f, 1.0f );

			if ( estado_teclado[SDL_SCANCODE_A] || estado_teclado[SDL_SCANCODE_LEFT] )
				direcao += Vec_2f( -1.0f, 0.0f );

			if ( estado_teclado[SDL_SCANCODE_S] || estado_teclado[SDL_SCANCODE_DOWN] )
				direcao += Vec_2f( 0.0f, -1.0f );
			
			if ( estado_teclado[SDL_SCANCODE_D] || estado_teclado[SDL_SCANCODE_RIGHT] )
				direcao += Vec_2f( 1.0f, 0.0f );
			
			direcao = unitario( direcao ) * fator_tempo;
			pos_aux = heroi.posicao + direcao;
			do {
				colidiu = false;

				distancia_colisao = std::numeric_limits<float>::infinity();
				distancia_colisao_aux = 0.0f;

				for ( int i = 0; i < mapa.paredes.size(); i++ ) {
					colidiu = colidiu || mapa.paredes[i].testar_colisao( heroi.posicao, pos_aux, normal_aux, distancia_colisao_aux );
				
					if ( colidiu && distancia_colisao_aux < distancia_colisao ) {
						distancia_colisao = distancia_colisao_aux;
						normal = normal_aux;
					}
				}

				if ( colidiu ) {
					if ( isinf( distancia_colisao ) )
						heroi.posicao -= unitario( direcao ) * 0.01f;
				
					direcao = colisao( direcao, normal, 1.0f, 0.0f );
					pos_aux = heroi.posicao + direcao;
				}

			} while ( colidiu );
			heroi.posicao = pos_aux;

		}

		/***********************************************************************/
		/*********************************PRINT*********************************/

		glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		//Ambiente e personagens
		textura_shader.usar();
		
		mapa.mostrar_ambiente( textura_shader );

		mapa.mostrar_personagens( textura_shader );

		//Paredes
		normal_shader.usar();

		mapa.mostrar_paredes( normal_shader );

		//Auxiliares
		shader.usar();

		mapa.mostrar_auxiliares( shader );

		tela.swap_tela();

		t += 0.01f;
	}

    return 0;
}
