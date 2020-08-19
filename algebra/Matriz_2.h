#ifndef MATRIZ_2_H
#define MATRIZ_2_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "matriz_enum.h"
#include "Vec_2.h"

template <class T>
class Matriz_2 {
public:
	T _val[4];

	Matriz_2<T> ( T valor = 0 );
	Matriz_2<T> ( const Matriz_tipo &tipo );
	Matriz_2<T> ( T v0, T v1, T v2, T v3 );
	Matriz_2<T> ( const T *valor );
	
	T&          operator () ( const size_t linha, const size_t coluna );
	
	Matriz_2<T>  operator  + ( const Matriz_2<T> &m );
	Matriz_2<T>  operator  - ( const Matriz_2<T> &m );
	Matriz_2<T>  operator  * ( const Matriz_2<T> &m );
	Vec_2<T>     operator  * ( const Vec_2<T> &v );
	Matriz_2<T>  operator  + ( T c );
	Matriz_2<T>  operator  - ( T c );
	Matriz_2<T>  operator  * ( T c );
	Matriz_2<T>  operator  / ( T c );
	
	Matriz_2<T>& operator  = ( const Matriz_2<T> &m );
	Matriz_2<T>& operator += ( const Matriz_2<T> &m );
	Matriz_2<T>& operator -= ( const Matriz_2<T> &m );
	Matriz_2<T>& operator *= ( const Matriz_2<T> &m );
	Matriz_2<T>& operator += ( T c );
	Matriz_2<T>& operator -= ( T c );
	Matriz_2<T>& operator *= ( T c );
	Matriz_2<T>& operator /= ( T c );
};

typedef Matriz_2<float>  Matriz_2f;
typedef Matriz_2<double> Matriz_2d;

template <class T> Matriz_2<T>  operator + ( T c , const Matriz_2<T> &mat );
template <class T> Matriz_2<T>  operator - ( T c , const Matriz_2<T> &mat );
template <class T> Matriz_2<T>  operator * ( T c , const Matriz_2<T> &mat );

template <class T> Matriz_2<T>& operator << ( Matriz_2<T> &mat, T dado );
template <class T> Matriz_2<T>& operator ,  ( Matriz_2<T> &mat, T dado );
template <class T> std::ostream& operator << ( std::ostream &out, const Matriz_2<T> &mat );
template <class T> Matriz_2<T> translacao ( T x, T y, T z );

#include "Matriz_2.inl"

#endif
