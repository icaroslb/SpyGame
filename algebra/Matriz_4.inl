template <class T>
Matriz_4<T>::Matriz_4 ( T valor )
{
	std::fill( _val, ( _val + 16 ), valor );
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T>::Matriz_4 ( const Matriz_tipo &tipo )
{
	switch ( tipo ) {
		case Matriz_tipo::IDENTIDADE :
			std::fill( _val, ( _val + 16 ), 0 );
			_val[0] = 1;
			_val[5] = 1;
			_val[10] = 1;
			_val[15] = 1;
		break;
		case Matriz_tipo::ZEROS :
			std::fill( _val, ( _val + 16 ), 0 );
		break;
		case Matriz_tipo::UMS :
			std::fill( _val, ( _val + 16 ), 1 );
		break;
		default: break;
	}
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T>::Matriz_4 ( T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15 )
{
	_val[0]  = v0;
	_val[1]  = v1;
	_val[2]  = v2;
	_val[3]  = v3;
	_val[4]  = v4;
	_val[5]  = v5;
	_val[6]  = v6;
	_val[7]  = v7;
	_val[8]  = v8;
	_val[9]  = v9;
	_val[10] = v10;
	_val[11] = v11;
	_val[12] = v12;
	_val[13] = v13;
	_val[14] = v14;
	_val[15] = v15;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T>::Matriz_4( const T *valor )
{
	memcpy( _val, valor, sizeof(T) * 16 );
}
/*===============================================================================================================================*/
template <class T>
T& Matriz_4<T>::operator () ( const size_t linha,  const size_t coluna )
{
	if ( coluna < 4 && linha < 4 )
		return _val[ ( linha * 4 ) + coluna ];
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Matriz_4<T>::operator + ( const Matriz_4<T> &m ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 16; i++ ) {
		mat._val[i] = _val[i] + m._val[i];
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Matriz_4<T>::operator - ( const Matriz_4<T> &m ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 16; i++ ) {
		mat._val[i] = _val[i] - m._val[i];
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> Matriz_4<T>::operator * ( const Matriz_4<T> &m ) {
	Matriz_4<T> mat( Matriz_tipo::ZEROS );
	
	for ( size_t i = 0; i < 4; i++ ) {
		for ( size_t j = 0; j < 4; j++ ) {
			for ( size_t k = 0; k < 4; k++ ) {
				mat._val[ ( i * 4 ) + j ] += _val [ ( i * 4 ) + k ] * m._val[ j + ( k * 4 ) ];
			}
		}
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Vec_4<T> Matriz_4<T>::operator * ( const Vec_4<T> &v ) {
	Vec_4<T> vet;
	
	vet._x = ( _val[ 0  ] * v._x ) + ( _val[ 1  ] * v._y ) + ( _val[ 2  ] * v._z ) + ( _val[ 3  ] * v._w );
	vet._y = ( _val[ 4  ] * v._x ) + ( _val[ 5  ] * v._y ) + ( _val[ 6  ] * v._z ) + ( _val[ 7  ] * v._w );
	vet._z = ( _val[ 8  ] * v._x ) + ( _val[ 9  ] * v._y ) + ( _val[ 10 ] * v._z ) + ( _val[ 11 ] * v._w );
	vet._w = ( _val[ 12 ] * v._x ) + ( _val[ 13 ] * v._y ) + ( _val[ 14 ] * v._z ) + ( _val[ 15 ] * v._w );
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>	
Vec_3<T> Matriz_4<T>::operator * ( const Vec_3<T> &v ) {
	Vec_3<T> vet;
	
	vet._x = ( _val[ 0 ] * v._x ) + ( _val[ 1 ] * v._y ) + ( _val[ 2  ] * v._z );
	vet._y = ( _val[ 4 ] * v._x ) + ( _val[ 5 ] * v._y ) + ( _val[ 6  ] * v._z );
	vet._z = ( _val[ 8 ] * v._x ) + ( _val[ 9 ] * v._y ) + ( _val[ 10 ] * v._z );
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> Matriz_4<T>::operator + ( T c ) {
	Matriz_4<T> mat( _val );
	
	for ( size_t i = 0; i < 16; i += 5) {
		mat._val[i] = _val[i] + c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> Matriz_4<T>::operator - ( T c ) {
	Matriz_4<T> mat( _val );
	
	for ( size_t i = 0; i < 16; i += 5 ) {
		mat._val[i] = _val[i] - c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> Matriz_4<T>::operator * ( T c ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 16; i++ ) {
		mat._val[i] = _val[i] * c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> Matriz_4<T>::operator / ( T c ) {
	Matriz_4<T> mat;
	
	c = T(1) / c;
	
	for ( size_t i = 0; i < 16; i++ ) {
		mat._val[i] = _val[i] * c;
	}
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator = ( const Matriz_4<T> &m ) {
	memcpy( _val, m._val, sizeof(T) * 16 );
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator += ( const Matriz_4<T> &m ) {
	for ( size_t i = 0; i < 16; i += 5 ) {
		_val[i] += m._val[i];
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator -= ( const Matriz_4<T> &m ) {
	for ( size_t i = 0; i < 16; i += 5 ) {
		_val[i] -= m._val[i];
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator *= ( const Matriz_4<T> &m ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 4; i++ ) {
		for ( size_t j = 0; j < 4; j++ ) {
			for ( size_t k = 0; k < 4; k++ ) {
				mat._val[ ( i * 4 ) + j ] += _val[ ( i * 4 ) + k ] * m._val[ j + ( k * 4 ) ];
			}
		}
	}
	
	*this = mat;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator += ( T c ) {
	for ( size_t i = 0; i < 16; i += 5 ) {
		_val[i] += c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator -= ( T c ) {
	for ( size_t i = 0; i < 16; i += 5 ) {
		_val[i] -= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator *= ( T c ) {
	for ( size_t i = 0; i < 16; i++ ) {
		_val[i] *= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& Matriz_4<T>::operator /= ( T c ) {
	c = T(1) / c;
	
	for ( size_t i = 0; i < 16; i++ ) {
		_val[i] *= c;
	}
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Matriz_4<T>::transposta () {
	Matriz_4<T> t;
	
	for ( size_t i = 0; i < 4; i++ ) {
		for ( size_t j = 0; j < 4; j++ ) {
			t._val[( i * 4 ) + j] = _val[i + ( j * 4 )];
		}
	}
	
	return transposta;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> operator + ( T c , const Matriz_4<T> &m ) {
	Matriz_4<T> mat( m._val );

	for ( size_t i = 0; i < 16; i += 5 )
		mat._val[i] = c + m._val[i];
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> operator - ( T c , const Matriz_4<T> &m ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 16; i++ )
		mat._val[i] = -m._val[i];

	for ( size_t i = 0; i < 16; i += 5 )
		mat._val[i] += c;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T> operator * ( T c , const Matriz_4<T> &m ) {
	Matriz_4<T> mat;
	
	for ( size_t i = 0; i < 16; i++ )
		mat._val[i] = c * m._val[i];
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& operator << ( Matriz_4<T> &mat, T dado ) {
	
	mat._val[0] = dado;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
Matriz_4<T>& operator , ( Matriz_4<T> &mat, T dado ) {
	static size_t indice = 1;
	static auto   id_matriz  = &mat;
	
	if ( id_matriz != &mat ) {
		indice = 1;
		id_matriz  = &mat;
	}
	
	mat._val[indice] = dado;
	
	indice++;
	indice = indice % 16;
	
	return mat;
}
/*===============================================================================================================================*/
template <class T>	
std::ostream& operator << ( std::ostream &out, const Matriz_4<T> &mat ) {
	out << std::endl;
	for ( size_t i = 0; i < 4; i++ ) {
		out << "[ " << mat._val[(i * 4)];
		for ( size_t j = 1; j < 4; j++ ) {
			out << ", " << mat._val[(i * 4) + j];
		}
		out << " ]" << std::endl;
	}
	
	return out;
}
/*===============================================================================================================================*/
