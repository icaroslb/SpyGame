#ifndef TECLADO_H
#define TECLADO_H

#include <map>
#include <stdexcept>
#include <SDL2/SDL.h>

class Teclado {
public:
	std::map< SDL_Keycode, bool > teclas;
	
	Teclado ();
	
	bool& obter_estado ( SDL_Keycode tecla );
	bool& mudar_estado ( SDL_Keycode tecla );
};

#endif