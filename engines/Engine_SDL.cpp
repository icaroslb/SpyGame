#include "Engine_SDL.h"

Engine_SDL::Engine_SDL (char *nomeTela, int largura, int altura, int posicao_x, int posicao_y) :
largura( largura ),
altura( altura ) {
	bool sucesso = true;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Não foi possível inicializar o SDL! SDL Erro: " << SDL_GetError() << std::endl;
		sucesso = false;
	} else {
		window = SDL_CreateWindow(nomeTela, posicao_x, posicao_y, largura, altura, SDL_WINDOW_OPENGL);
	
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		
		if (window == nullptr) {
			std::cout << "Não foi possível criar a tela! SDL Erro: " << SDL_GetError() << std::endl;
			sucesso = false;
		} else {
			contextoGL = SDL_GL_CreateContext(window);
			
			if (contextoGL == nullptr) {
				std::cout << "Não foi possível criar o contexto do OpenGl! SDL Erro: " << SDL_GetError() << std::endl;
				sucesso = false;
			} else {
				if (SDL_GL_SetSwapInterval(1) < 0) {
					std::cout << "Atenção: Não foi possível ativar o VSync! SDL Erro: " << SDL_GetError() << std::endl;
				}
				
				glewInit();
			}
		}
	}
}
/*===============================================================================================================================*/
void Engine_SDL::swap_tela () {
	SDL_GL_SwapWindow(window);
}
/*===============================================================================================================================*/
const GLubyte* Engine_SDL::obter_versao_opengl () {
	return glGetString(GL_VERSION);
}
/*===============================================================================================================================*/
Engine_SDL::~Engine_SDL () {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
/*===============================================================================================================================*/
