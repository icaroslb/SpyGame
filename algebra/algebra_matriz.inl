template <class T>
T determinante ( const Matriz_2<T> &m )
{
	return ( m._val[0] * m._val[3] ) - ( m._val[1] * m._val[2] );
}
/*===============================================================================================================================*/
template <class T>
T determinante ( const Matriz_3<T> &m )
{
	return   ( m._val[0] * m._val[4] * m._val[8] )
	       + ( m._val[3] * m._val[7] * m._val[2] )
	       + ( m._val[6] * m._val[1] * m._val[5] )
	       - ( m._val[6] * m._val[4] * m._val[2] )
	       - ( m._val[0] * m._val[7] * m._val[5] )
	       - ( m._val[3] * m._val[1] * m._val[8] );
}
/*===============================================================================================================================*/
template <class T>
T determinante ( const Matriz_4<T> &m )
{
	return ;
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T> transposta ( const Matriz_2<T> &m ) {
	Matriz_2<T> trasnpo;
	
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			trasnpo._val[( i * 2 ) + j] = m._val[i + ( j * 2 )];
		}
	}
	
	return trasnpo;
}
/*===============================================================================================================================*/
template <class T>
Matriz_3<T> transposta ( const Matriz_3<T> &m )
{
	Matriz_3<T> trasnpo;
	
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			trasnpo._val[( i * 3 ) + j] = m._val[i + ( j * 3 )];
		}
	}
	
	return trasnpo;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> transposta ( const Matriz_4<T> &m )
{
	Matriz_4<T> trasnpo;
	
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			trasnpo._val[( i * 4 ) + j] = m._val[i + ( j * 4 )];
		}
	}
	
	return trasnpo;
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T> co_fatores ( const Matriz_2<T> &m, size_t i, size_t j ) {
	( ( i % 2 ) == 0 ) ? i++ : i-- ;
	( ( j % 2 ) == 0 ) ? j++ : j-- ;
	
	return ( ( ( i + j ) % 2 ) == 0 ) ? +m._val[i + ( j * 2 )] : -m._val[i + ( j * 2 )];
}
/*===============================================================================================================================*/
template <class T>
T co_fator ( const Matriz_3<T> &m, size_t i, size_t j )
{
	
}
/*===============================================================================================================================*/
template <class T>
T co_fator ( const Matriz_4<T> &m, size_t i, size_t j )
{

}
/*===============================================================================================================================*/
template <class T>
T co_fator ( const Matriz_2<T> &m, size_t id )
{
	switch ( id ) {
		case 0:
			return +m._val[3];
		break;
		case 1:
			return -m._val[2];
		break;
		case 2:
			return -m._val[1];
		break;
		case 3:
			return +m._val[0];
		break;
		default: break;
	}
	
	return T(0);
}
/*===============================================================================================================================*/
template <class T>
T co_fator ( const Matriz_3<T> &m, size_t id )
{
	switch ( id ) {
		case 0:
			return +determinante( Matriz_2<T>( m._val[4], m._val[5],
			                                   m._val[7], m._val[8] ) );
		break;
		case 1:
			return -determinante( Matriz_2<T>( m._val[3], m._val[5],
			                                   m._val[6], m._val[8] ) );
		break;
		case 2:
			return +determinante( Matriz_2<T>( m._val[3], m._val[4],
			                                   m._val[6], m._val[7] ) );
		break;
		case 3:
			return -determinante( Matriz_2<T>( m._val[1], m._val[2],
			                                   m._val[7], m._val[8] ) );
		break;
		case 4:
			return +determinante( Matriz_2<T>( m._val[0], m._val[2],
			                                   m._val[6], m._val[8] ) );
		break;
		case 5:
			return -determinante( Matriz_2<T>( m._val[0], m._val[1],
			                                   m._val[6], m._val[7] ) );
		break;
		case 6:
			return +determinante( Matriz_2<T>( m._val[1], m._val[2],
			                                   m._val[4], m._val[5] ) );
		break;
		case 7:
			return -determinante( Matriz_2<T>( m._val[0], m._val[2],
			                                   m._val[3], m._val[5] ) );
		break;
		case 8:
			return +determinante( Matriz_2<T>( m._val[0], m._val[1],
			                                   m._val[3], m._val[4] ) );
		break;
		default: break;
	}
	
	return T(0);
}
/*===============================================================================================================================*/
template <class T>
T co_fator ( const Matriz_4<T> &m, size_t id )
{
	switch ( id ) {
		case 0:
			return +determinante( Matriz_3<T>( m._val[5],  m._val[6],  m._val[7],
			                                   m._val[9],  m._val[10], m._val[11],
			                                   m._val[13], m._val[14], m._val[15] ) );
		break;
		case 1:
			return -determinante( Matriz_3<T>( m._val[4],  m._val[6],  m._val[7],
			                                   m._val[8],  m._val[10], m._val[11],
			                                   m._val[12], m._val[14], m._val[15] ) );
		break;
		case 2:
			return +determinante( Matriz_3<T>( m._val[4],  m._val[5],  m._val[7],
			                                   m._val[8],  m._val[9],  m._val[11],
			                                   m._val[12], m._val[13], m._val[15] ) );
		break;
		case 3:
			return -determinante( Matriz_3<T>( m._val[4],  m._val[5],  m._val[6],
			                                   m._val[8],  m._val[9],  m._val[10],
			                                   m._val[12], m._val[13], m._val[14] ) );
		break;
		case 4:
			return -determinante( Matriz_3<T>( m._val[1],  m._val[2],  m._val[3],
			                                   m._val[9],  m._val[10], m._val[11],
			                                   m._val[13], m._val[14], m._val[15] ) );
		break;
		case 5:
			return +determinante( Matriz_3<T>( m._val[0],  m._val[2],  m._val[3],
			                                   m._val[8],  m._val[10], m._val[11],
			                                   m._val[12], m._val[14], m._val[15] ) );
		break;
		case 6:
			return -determinante( Matriz_3<T>( m._val[0],  m._val[1],  m._val[3],
			                                m._val[8],  m._val[9],  m._val[11],
			                                m._val[12], m._val[13], m._val[15] ) );
		break;
		case 7:
			return +determinante( Matriz_3<T>( m._val[0],  m._val[1],  m._val[2],
			                                   m._val[8],  m._val[9],  m._val[10],
			                                   m._val[12], m._val[13], m._val[14] ) );
		break;
		case 8:
			return +determinante( Matriz_3<T>( m._val[1],  m._val[2],  m._val[3],
			                                   m._val[5],  m._val[6],  m._val[7],
			                                   m._val[13], m._val[14], m._val[15] ) );
		break;
		case 9:
			return -determinante( Matriz_3<T>( m._val[0],  m._val[2],  m._val[3],
			                                   m._val[4],  m._val[6],  m._val[7],
			                                   m._val[12], m._val[14], m._val[15] ) );
		break;
		case 10:
			return +determinante( Matriz_3<T>( m._val[0],  m._val[1],  m._val[3],
			                                   m._val[4],  m._val[5],  m._val[7],
			                                   m._val[12], m._val[13], m._val[15] ) );
		break;
		case 11:
			return -determinante( Matriz_3<T>( m._val[0],  m._val[1],  m._val[2],
			                                m._val[4],  m._val[5],  m._val[6],
			                                m._val[12], m._val[13], m._val[14] ) );
		break;
		case 12:
			return -determinante( Matriz_3<T>( m._val[1], m._val[2],  m._val[3],
			                                m._val[5], m._val[6],  m._val[7],
			                                m._val[9], m._val[10], m._val[11] ) );
		break;
		case 13:
			return +determinante( Matriz_3<T>( m._val[0], m._val[2],  m._val[3],
			                                   m._val[4], m._val[6],  m._val[7],
			                                   m._val[8], m._val[10], m._val[11] ) );
		break;
		case 14:
			return -determinante( Matriz_3<T>( m._val[0], m._val[1], m._val[3],
			                                   m._val[4], m._val[5], m._val[7],
			                                   m._val[8], m._val[9], m._val[11] ) );
		break;
		case 15:
			return +determinante( Matriz_3<T>( m._val[0], m._val[1], m._val[2],
			                                   m._val[4], m._val[5], m._val[6],
			                                   m._val[8], m._val[9], m._val[10] ) );
		break;
		default: break;
	}
	
	return T(0);
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T> inversa ( const Matriz_2<T> &m )
{
	Matriz_2<T> inver;
	T constante;
	
	if ( ( constante = determinante( m ) ) != T(0) ) {
		constante = T(1) / constante;
		
		inver._val[0] = constante *  m._val[3];
		inver._val[1] = constante * -m._val[1];
		inver._val[2] = constante * -m._val[2];
		inver._val[3] = constante *  m._val[0];
	}
	
	return inver;
}
/*===============================================================================================================================*/
template <class T>
Matriz_3<T> inversa ( const Matriz_3<T> &m )
{
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> inversa ( const Matriz_4<T> &m )
{
}
/*===============================================================================================================================*/
