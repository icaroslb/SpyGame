#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "../algebra/include_algebra.h"

enum{ ORTHO, FRUSTUM };

template <class T>
class Camera {
public:
	Vec_3<T> camera_posicao,
	          look_at,
	          view_up;
	Matriz_4<T> projecao;
	T velocidade_camera,
	  esq,
	  dir,
	  baixo,
	  cima,
	  near,
	  far;
	int tipo;
	static Camera<T> *instancia;
	
	 Camera ( Vec_3<T> posicao, Vec_3<T> lookAt, Vec_3<T> viewUp,
	          T esq,   T dir,
	          T baixo, T cima,
	          T near,  T far,
	          int   tipo,  T velocidade = 1.0f );
	
	Matriz_4<T> gerar_matriz_camera ();
	Matriz_4<T> obter_matriz_projecao ();
	Vec_3<T> obter_posicao_camera ();
	
	void andar_frente ();
	void andar_tras ();
	void andar_direita ();
	void andar_esquerda ();
	
	static Camera<T>* obter_instancia ();
	void atualizar_matriz ( int tipo );
	void redmensionar_camera ( const Vec_2<T> &vetor_distancia, T valor_distancia );
	
	/*void rodar ( Vec_3f ponto_rotacao, Vec_3f vetor, float angulo );
	void rodar ( Vec_3f ponto_rotacao, float x, float y, float angulo );
	void rodar ( Vec_3f vetor, float angulo, float distancia = 1.0f );
	void rodar ( float x, float y, float angulo, float distancia = 1.0f );*/
	
	Vec_2<T> pick ( T x, T y, T janela_largura, T janela_altura );
	Vec_2<T> relative_pick ( T x, T y, T janela_largura, T janela_altura );
};

template <class T>
Matriz_4<T> look_at ( const Vec_3<T> &pos, const Vec_3<T> &olha, const Vec_3<T> &cima )
{
	Matriz_4<T> matriz_info( Matriz_tipo::IDENTIDADE );
	Matriz_4<T> matriz_movimento( Matriz_tipo::IDENTIDADE );
	
	const Vec_3<T> vetor_f    = ( pos - olha ),
	               unita_f    = unitario( vetor_f ),
	               unita_cima = unitario( cima ),
	               direita    = produto_vetorial( unita_f, unita_cima ),
	               vetor_cima = produto_vetorial( unitario( direita ), unita_f );
	
	matriz_movimento( 0, 0 ) =  direita.x();
	matriz_movimento( 0, 1 ) =  direita.y();
	matriz_movimento( 0, 2 ) =  direita.z();
	
	matriz_movimento( 1, 0 ) =  vetor_cima.x();
	matriz_movimento( 1, 1 ) =  vetor_cima.y();
	matriz_movimento( 1, 2 ) =  vetor_cima.z();
	
	matriz_movimento( 2, 0 ) = -unita_f.x();
	matriz_movimento( 2, 1 ) = -unita_f.y();
	matriz_movimento( 2, 2 ) = -unita_f.z();
	
	matriz_info( 0, 3 ) = -olha.x();
	matriz_info( 1, 3 ) = -olha.y();
	matriz_info( 2, 3 ) = -olha.z();
	
	return matriz_movimento * matriz_info;
}

#include "Camera.inl"

#endif
