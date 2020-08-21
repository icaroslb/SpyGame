#version 430 core

layout ( location = 0 ) in vec2 aPos;
layout ( location = 1 ) in vec2 aTexCoord;

uniform vec2 posicao_objeto;
uniform vec2 dimen;

out vec2 TexCoord;

void main () {
	gl_Position = vec4( ( aPos * dimen ) + posicao_objeto, 0.0, 1.0 );
	TexCoord = aTexCoord;
}
