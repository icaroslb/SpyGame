template <class T> Camera<T>* Camera<T>::instancia = nullptr;

template <class T>
Camera<T>::Camera ( Vec_3<T> posicao, Vec_3<T> lookAt, Vec_3<T> viewUp, T esq, T dir, T baixo, T cima, T near, T far, int tipo,  T velocidade )
: camera_posicao( posicao )
, look_at( lookAt )
, view_up( viewUp )
, projecao( Matriz_tipo::ZEROS )
, velocidade_camera( velocidade )
, dir( dir )
, esq( esq )
, baixo( baixo )
, cima( cima )
, near( near )
, far( far )
, tipo( tipo )
{
	atualizar_matriz ( tipo );
	
	instancia = this;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Camera<T>::gerar_matriz_camera ()
{
	return look_at( camera_posicao, ( look_at + camera_posicao ), view_up );
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Camera<T>::obter_matriz_projecao ()
{
	return projecao;
}
/*===============================================================================================================================*/
template <class T>
Vec_3<T> Camera<T>::obter_posicao_camera ()
{
	return camera_posicao;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_frente ()
{
	camera_posicao += look_at * velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_tras ()
{
	camera_posicao -= look_at * velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_direita ()
{
	camera_posicao += unitario( produto_vetorial( look_at, view_up ) ) * velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_esquerda ()
{
	camera_posicao -= unitario( produto_vetorial( look_at, view_up ) ) * velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
Camera<T>* Camera<T>::obter_instancia ()
{
	return instancia;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::atualizar_matriz ( int tipo )
{
	switch (tipo) {
	case ORTHO:
		projecao( 0, 0 ) =   T(2.0) / ( dir - esq );
		projecao( 1, 1 ) =   T(2.0) / ( cima- baixo );
		projecao( 2, 2 ) = - T(2.0) / ( far - near );
		projecao( 3, 0 ) = - ( dir + esq ) / ( dir - esq );
		projecao( 3, 1 ) = - ( cima + baixo ) / ( cima - baixo );
		projecao( 3, 2 ) = - ( far + near ) / ( far - near );
		projecao( 3, 3 ) =   T(1);
	break;
	case FRUSTUM:
		projecao( 0, 0 ) =   ( T(2.0) * near ) / ( dir - esq );
		projecao( 1, 1 ) =   ( T(2.0) * near ) / ( cima- baixo );
		projecao( 2, 0 ) =   ( dir + esq ) / ( dir - esq );
		projecao( 2, 1 ) =   ( cima + baixo ) / ( cima - baixo );
		projecao( 2, 2 ) = - ( far + near ) / ( far - near );
		projecao( 2, 3 ) = - T(1);
		projecao( 3, 2 ) = - ( T(2.0) * far * near ) / ( far - near );
	break;
	}
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::redmensionar_camera ( const Vec_2<T> &vetor_distancia, T valor_distancia )
{
	Vec_2<T> vetor_valor_distancia = unitario( vetor_distancia ) * valor_distancia;
	
	
	if ( std::abs( vetor_valor_distancia._x ) > T(0) ) {
		T horizontal = dir - esq,
		  vertical = cima - baixo,
		  //prop_horizontal = horizontal / vetor_distancia._x,
		  nova_horizontal = ( horizontal * valor_distancia ) / norma( vetor_distancia ),
		  nova_vertical = ( vertical * valor_distancia ) / norma( vetor_distancia );
		
		dir = nova_horizontal / 2;
		esq = -dir;
		cima = nova_vertical / 2;
		baixo = -cima;
	} else if ( std::abs( vetor_valor_distancia._y ) > T(0) ) {
		T horizontal = dir - esq,
		  vertical = cima - baixo,
		  prop_vertical = vertical / vetor_distancia._y,
		  nova_vertical = prop_vertical * vetor_valor_distancia._y,
		  nova_horizontal = ( horizontal / vertical ) * prop_vertical;
		
		dir = nova_horizontal / 2;
		esq = -dir;
		cima = nova_vertical / 2;
		baixo = -cima;
	}

	  atualizar_matriz( tipo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 ponto_rotacao, glm::vec3 vetor, float angulo )
{
	vetor = glm::normalize( vetor );
	glm::tquat<float> quaternio = glm::angleAxis( angulo, vetor ),
	          conjugado = glm::conjugate( quaternio );
	camera_posicao = ( quaternio * glm::vec4( ( camera_posicao - ponto_rotacao ), 1.0 ) * conjugado ) + glm::vec4( ponto_rotacao, 1.0 );
	look_at = quaternio * glm::vec4( look_at, 0.0f ) * conjugado;
	view_up = quaternio * glm::vec4( view_up, 0.0f ) * conjugado;
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 ponto_rotacao, float x, float y, float angulo )
{
	rodar( ponto_rotacao, ( view_up * x ) + ( glm::cross( look_at, view_up ) * y ), angulo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 vetor, float angulo, float distancia )
{
	rodar( ( look_at * distancia ) + camera_posicao, vetor, angulo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( float x, float y, float angulo, float distancia )
{
	rodar( ( look_at * distancia ) + camera_posicao, ( view_up * x ) + ( glm::cross( look_at, view_up ) * y ), angulo );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Camera<T>::pick ( T x, T y, T janela_largura, T janela_altura )
{
	Vec_2<T> coord_camera;
	
	T tam_pix_x = ( dir - esq ) / janela_largura,
	  tam_pix_y = ( cima - baixo ) / janela_altura;
	
	y = janela_altura - y;
	
	coord_camera.x() = ( esq + camera_posicao.x() )   + ( tam_pix_x / T(2) ) + ( tam_pix_x * x );
	coord_camera.y() = ( baixo + camera_posicao.y() ) + ( tam_pix_y / T(2) ) + ( tam_pix_y * y );
	
	return coord_camera;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Camera<T>::relative_pick ( T x, T y, T janela_largura, T janela_altura )
{
	Vec_2<T> coord_camera;
	
	T tam_pix_x = ( dir - esq ) / janela_largura,
	  tam_pix_y = ( cima - baixo ) / janela_altura;
	
	coord_camera.x() = tam_pix_x *  x;
	coord_camera.y() = tam_pix_y * -y;
	
	return coord_camera;
}
/*===============================================================================================================================*/
