#version 430 core

layout ( location = 0 ) in vec2 aPos;

uniform vec2 posicao;
uniform vec2 dimen;

out vec2 posicao_pixel;
out vec2 posicao_objeto;

void main () {
	posicao_pixel = ( aPos * dimen ) + posicao;
	gl_Position = vec4( posicao_pixel, 0.0, 1.0 );
	posicao_objeto = posicao;
}