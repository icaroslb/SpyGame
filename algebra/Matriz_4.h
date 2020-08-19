#ifndef MATRIZ_4_H
#define MATRIZ_4_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "matriz_enum.h"
#include "Vec_4.h"
#include "Vec_3.h"

template <class T>
class Matriz_4 {
public:
	T _val[16];

	Matriz_4<T> ( T valor = 0 );
	Matriz_4<T> ( const Matriz_tipo &tipo );
	Matriz_4<T> ( T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15 );
	Matriz_4<T> ( const T *valor );
	
	T&          operator () ( const size_t linha, const size_t coluna );
	
	Matriz_4<T>  operator  + ( const Matriz_4<T> &m );
	Matriz_4<T>  operator  - ( const Matriz_4<T> &m );
	Matriz_4<T>  operator  * ( const Matriz_4<T> &m );
	Vec_4<T>     operator  * ( const Vec_4<T> &v );
	Vec_3<T>     operator  * ( const Vec_3<T> &v );
	Matriz_4<T>  operator  + ( T c );
	Matriz_4<T>  operator  - ( T c );
	Matriz_4<T>  operator  * ( T c );
	Matriz_4<T>  operator  / ( T c );
	
	Matriz_4<T>& operator  = ( const Matriz_4<T> &m );
	Matriz_4<T>& operator += ( const Matriz_4<T> &m );
	Matriz_4<T>& operator -= ( const Matriz_4<T> &m );
	Matriz_4<T>& operator *= ( const Matriz_4<T> &m );
	Matriz_4<T>& operator += ( T c );
	Matriz_4<T>& operator -= ( T c );
	Matriz_4<T>& operator *= ( T c );
	Matriz_4<T>& operator /= ( T c );
	
	Matriz_4<T> transposta ();
};

typedef Matriz_4<float>  Matriz_4f;
typedef Matriz_4<double> Matriz_4d;

template <class T> Matriz_4<T>  operator + ( T c , const Matriz_4<T> &mat );
template <class T> Matriz_4<T>  operator - ( T c , const Matriz_4<T> &mat );
template <class T> Matriz_4<T>  operator * ( T c , const Matriz_4<T> &mat );

template <class T> Matriz_4<T>& operator << ( Matriz_4<T> &mat, T dado );
template <class T> Matriz_4<T>& operator ,  ( Matriz_4<T> &mat, T dado );
template <class T> std::ostream& operator << ( std::ostream &out, const Matriz_4<T> &mat );
template <class T> Matriz_4<T> translacao ( T x, T y, T z );

#include "Matriz_4.inl"

#endif
