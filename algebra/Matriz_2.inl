template <class T>
Matriz_2<T>::Matriz_2 ( T valor )
{
	std::fill( _val, ( _val + 4 ), valor );
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T>::Matriz_2 ( const Matriz_tipo &tipo )
{
	switch ( tipo ) {
		case Matriz_tipo::IDENTIDADE :
			std::fill( _val, ( _val + 4 ), 0 );
			_val[0] = 1;
			_val[3] = 1;
		break;
		case Matriz_tipo::ZEROS :
			std::fill( _val, ( _val + 4 ), 0 );
		break;
		case Matriz_tipo::UMS :
			std::fill( _val, ( _val + 4 ), 1 );
		break;
		default: break;
	}
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T>::Matriz_2 ( T v0, T v1, T v2, T v3 )
{
	_val[0]  = v0;
	_val[1]  = v1;
	_val[2]  = v2;
	_val[3]  = v3;
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T>::Matriz_2( const T *valor )
{
	memcpy( _val, valor, sizeof(T) * 4 );
}
/*===============================================================================================================================*/
template <class T>
T& Matriz_2<T>::operator () ( const size_t linha,  const size_t coluna )
{
	if ( coluna < 2 && linha < 2 )
		return _val[ ( linha * 2 ) + coluna ];
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T> Matriz_2<T>::operator + ( const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 4; i++ ) {
		mat._val[i] = _val[i] + m._val[i];
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>
Matriz_2<T> Matriz_2<T>::operator - ( const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 4; i++ ) {
		mat._val[i] = _val[i] - m._val[i];
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> Matriz_2<T>::operator * ( const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 2; i++ ) {
		for ( size_t j = 0; j < 2; j++ ) {
			for ( size_t k = 0; k < 2; k++ ) {
				mat._val[ ( i * 2 ) + j ] += _val [ ( i * 2 ) + k ] * m._val[ j + ( k * 2 ) ];
			}
		}
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Vec_2<T> Matriz_2<T>::operator * ( const Vec_2<T> &v ) {
	Vec_2<T> vet;
	
	vet._x = ( _val[ 0 ] * v._x ) + ( _val[ 1 ] * v._y );
	vet._y = ( _val[ 2 ] * v._x ) + ( _val[ 3 ] * v._y );
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> Matriz_2<T>::operator + ( T c ) {
	Matriz_2<T> mat( _val );
	
	for ( size_t i = 0; i < 4; i += 3 ) {
		mat._val[i] = _val[i] + c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> Matriz_2<T>::operator - ( T c ) {
	Matriz_2<T> mat( _val );
	
	for ( size_t i = 0; i < 4; i += 3 ) {
		mat._val[i] = _val[i] - c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> Matriz_2<T>::operator * ( T c ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 4; i++ ) {
		mat._val[i] = _val[i] * c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> Matriz_2<T>::operator / ( T c ) {
	Matriz_2<T> mat;
	
	c = T(1) / c;
	
	for ( size_t i = 0; i < 4; i++ ) {
		mat._val[i] = _val[i] * c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator = ( const Matriz_2<T> &m ) {
	memcpy( _val, m._val, sizeof(T) * 4);
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator += ( const Matriz_2<T> &m ) {
	for ( size_t i = 0; i < 4; i += 3 ) {
		_val[i] += m._val[i];
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator -= ( const Matriz_2<T> &m ) {
	for ( size_t i = 0; i < 4; i += 3 ) {
		_val[i] -= m._val[i];
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator *= ( const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 2; i++ ) {
		for ( size_t j = 0; j < 2; j++ ) {
			for ( size_t k = 0; k < 2; k++ ) {
				mat._val[ ( i * 2 ) + j ] += _val [ ( i * 2 ) + k ] * m._val[ j + ( k * 2 ) ];
			}
		}
	}
	
	*this = mat;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator += ( T c ) {
	for ( size_t i = 0; i < 4; i += 3 ) {
		_val[i] += c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator -= ( T c ) {
	for ( size_t i = 0; i < 4; i += 3 ) {
		_val[i] -= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator *= ( T c ) {
	for ( size_t i = 0; i < 4; i++ ) {
		_val[i] *= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& Matriz_2<T>::operator /= ( T c ) {
	c = T(1) / c;
	
	for ( size_t i = 0; i < 4; i++ ) {
		_val[i] *= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> operator + ( T c , const Matriz_2<T> &m ) {
	Matriz_2<T> mat( m._val );
	
	for ( size_t i = 0; i < 4; i += 3 )
		mat._val[i] = c + m._val[i];
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> operator - ( T c , const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 4; i++ )
		mat._val[i] = -m._val[i];

	for ( size_t i = 0; i < 4; i += 3 )
		mat._val[i] += c;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T> operator * ( T c , const Matriz_2<T> &m ) {
	Matriz_2<T> mat;
	
	for ( size_t i = 0; i < 4; i++ )
		mat._val[i] = c * m._val[i];
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& operator << ( Matriz_2<T> &mat, T dado ) {
	
	mat._val[0] = dado;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_2<T>& operator , ( Matriz_2<T> &mat, T dado ) {
	static size_t indice = 1;
	static auto   id_matriz = &mat;
	T aux;
	
	if ( id_matriz != &mat ) {
		indice = 1;
		id_matriz = &mat;
	}
	
	mat._val[indice] = dado;
	
	indice++;
	indice = indice % 4;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
std::ostream& operator << ( std::ostream &out, const Matriz_2<T> &mat ) {
	out << std::endl;
	for ( size_t i = 0; i < 2; i++ ) {
		out << "[ " << mat._val[i * 2];
		for ( size_t j = 1; j < 2; j++ ) {
			out << ", " << mat._val[( i * 2 ) + j];
		}
		out << " ]" << std::endl;
	}
	
	return out;
}
/*===============================================================================================================================*/
