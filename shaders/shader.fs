#version 430 core

struct Barreira {
	vec2 pos_1;
	vec2 pos_2;
};

out vec4 FragColor;

in vec2 posicao_pixel;

uniform vec2 posicao_objeto;
uniform vec2 direcao;
uniform float raio;
uniform float abertura;

uniform int qtd_barreiras;
uniform Barreira barreiras[1024];

bool colisao ( vec2 p_inicial, vec2 p_fim, vec2 p_1, vec2 p_2 );

void main () {
	vec4 luz = vec4( 0.6, 0.6, 0.6, 0.0 );
	vec2 dist = posicao_pixel - posicao_objeto;
	
	float raio_quadrado = raio * raio;
	float dist_quadrada = dot( dist, dist );
	//float fator = ( raio_quadrado - dist_quadrada ) / raio_quadrado;
	
	bool houve_colisao = false;
	bool teste_colisao = false;
	
	if ( raio_quadrado <= raio_quadrado
	&&   dot( normalize( dist ), direcao ) > abertura ) {
		for ( int i = 0; i < qtd_barreiras; ++i ) {
			teste_colisao = colisao( posicao_objeto, posicao_pixel,
			                    //     barreiras[(i*2)], barreiras[(i*2)+1] );
								     barreiras[i].pos_1, barreiras[i].pos_2 );
			if ( teste_colisao ) {
				houve_colisao = true;
				break;
			}
		}

		if ( !houve_colisao )
			luz.w = ( raio_quadrado - dist_quadrada ) / raio_quadrado;
	}
	

	FragColor = vec4( 0.0, 0.0, 0.0, 0.0 ) + luz;
}

bool colisao ( vec2 p_inicial, vec2 p_fim, vec2 p_1, vec2 p_2 )
{
	vec3 linha_1 = vec3( p_2 - p_1, 0.0 );
	vec3 linha_2 = vec3( p_fim - p_inicial, 0.0 );
	
	vec3 col_1 = cross( linha_1, vec3( p_inicial - p_1, 0.0)  ) * cross( linha_1, vec3( p_fim - p_1, 0.0)  );
	vec3 col_2 = cross( linha_2, vec3( p_1 - p_inicial, 0.0)  ) * cross( linha_2, vec3( p_2 - p_inicial, 0.0)  );

	if ( col_1.z < 0.0 && col_2.z < 0.0 )
		return true;
	else
		return false;
}
