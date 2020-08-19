#ifndef ENGINE_SDL_H
#define ENGINE_SDL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Engine_SDL {
public:
	SDL_Window *window;
	SDL_GLContext contextoGL;
	
	int largura, altura;

	Engine_SDL (char *nomeTela, int largura, int altura, int posicao_x = SDL_WINDOWPOS_UNDEFINED, int posicao_y = SDL_WINDOWPOS_UNDEFINED);
	void swap_tela ();
	const GLubyte* obter_versao_opengl ();
	~Engine_SDL ();
};

#endif
