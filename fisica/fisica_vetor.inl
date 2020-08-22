template <class T>
bool teste_colisao ( const Vec_2<T> &p_1_1, const Vec_2<T> &p_1_2
                   , const Vec_2<T> &p_2_1, const Vec_2<T> &p_2_2
                   , const Vec_2<T> &normal, T &dist )
{
	const Vec_2<T> v_1 = p_1_2 - p_1_1;
	const Vec_2<T> v_2 = p_2_2 - p_2_1;

	const T valor_1 = produto_vetorial( v_1, p_2_1 - p_1_1 ) * produto_vetorial( v_1, p_2_2 - p_1_1 );
	const T valor_2 = produto_vetorial( v_2, p_1_1 - p_2_1 ) * produto_vetorial( v_2, p_1_2 - p_2_1 );

	if ( valor_1 <= T(0) && valor_2 <= T(0) ){
		dist = produto_escalar( p_2_1 - p_1_1, normal ) / produto_escalar( v_1, normal );

		return true;
	} else {
		return false;
	}
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> colisao ( const Vec_2<T> &v, const Vec_2<T> &normal, T alfa, T beta )
{
	const Vec_2<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
template <class T>
Vec_3<T> colisao ( const Vec_3<T> &v, const Vec_3<T> &normal, T alfa, T beta )
{
	const Vec_3<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> colisao ( const Vec_4<T> &v, const Vec_4<T> &normal, T alfa, T beta )
{
	const Vec_4<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
