#include "Teclado.h"

Teclado::Teclado ()
{}

bool& Teclado::obter_estado ( SDL_Keycode tecla )
{
	 try {
	 	return teclas.at( tecla );
	 } catch ( const std::out_of_range &oor ) {
	 	return teclas[tecla] = false;
	 }
}

bool& Teclado::mudar_estado ( SDL_Keycode tecla )
{
	try {
	 	return teclas.at( tecla ) ^= true;
	 } catch ( const std::out_of_range &oor ) {
	 	return teclas[tecla] = true;
	 }
}