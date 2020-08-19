#ifndef MATRIZ_3_H
#define MATRIZ_3_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "matriz_enum.h"
#include "Vec_3.h"

template <class T>
class Matriz_3 {
public:
	T _val[9];

	Matriz_3<T> ( T valor = 0 );
	Matriz_3<T> ( const Matriz_tipo &tipo );
	Matriz_3<T> ( T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8 );
	Matriz_3<T> ( const T *valor );
	
	T&          operator () ( const size_t linha, const size_t coluna );
	
	Matriz_3<T>  operator  + ( const Matriz_3<T> &m );
	Matriz_3<T>  operator  - ( const Matriz_3<T> &m );
	Matriz_3<T>  operator  * ( const Matriz_3<T> &m );
	Vec_3<T>     operator  * ( const Vec_3<T> &v );
	Matriz_3<T>  operator  + ( T c );
	Matriz_3<T>  operator  - ( T c );
	Matriz_3<T>  operator  * ( T c );
	Matriz_3<T>  operator  / ( T c );
	
	Matriz_3<T>& operator  = ( const Matriz_3<T> &m );
	Matriz_3<T>& operator += ( const Matriz_3<T> &m );
	Matriz_3<T>& operator -= ( const Matriz_3<T> &m );
	Matriz_3<T>& operator *= ( const Matriz_3<T> &m );
	Matriz_3<T>& operator += ( T c );
	Matriz_3<T>& operator -= ( T c );
	Matriz_3<T>& operator *= ( T c );
	Matriz_3<T>& operator /= ( T c );
	
	Matriz_3<T> transposta ();
};

typedef Matriz_3<float>  Matriz_3f;
typedef Matriz_3<double> Matriz_3d;

template <class T> Matriz_3<T>  operator + ( T c , const Matriz_3<T> &mat );
template <class T> Matriz_3<T>  operator - ( T c , const Matriz_3<T> &mat );
template <class T> Matriz_3<T>  operator * ( T c , const Matriz_3<T> &mat );

template <class T> Matriz_3<T>& operator << ( Matriz_3<T> &mat, T dado );
template <class T> Matriz_3<T>& operator ,  ( Matriz_3<T> &mat, T dado );
template <class T> std::ostream& operator << ( std::ostream &out, const Matriz_3<T> &mat );
template <class T> Matriz_3<T> translacao ( T x, T y, T z );

#include "Matriz_3.inl"

#endif
