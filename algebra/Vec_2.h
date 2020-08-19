#ifndef VEC_2_H
#define VEC_2_H

#include <iostream>
#include <cstring>

template <class T>
class Vec_2 {
public:

	union
	{
		T coord[2];
		struct { T _x, _y; };
	};
	
	Vec_2<T> ( T x = 0, T y = 0 );
	
	T&       x  ();
	const T& x  () const;
	T&       y  ();
	const T& y  () const;
	
	T&       operator [] ( int i );
	const T& operator [] ( int i ) const;
	
	Vec_2<T>  operator + ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator - ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator * ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator + ( T c ) const;
	Vec_2<T>  operator - ( T c ) const;
	Vec_2<T>  operator * ( T c ) const;
	Vec_2<T>  operator / ( T c ) const;
	
	Vec_2<T>& operator  = ( const Vec_2<T> &v );
	Vec_2<T>& operator += ( const Vec_2<T> &v );
	Vec_2<T>& operator -= ( const Vec_2<T> &v );
	Vec_2<T>& operator *= ( const Vec_2<T> &v );
	Vec_2<T>& operator += ( T c );
	Vec_2<T>& operator -= ( T c );
	Vec_2<T>& operator *= ( T c );
	Vec_2<T>& operator /= ( T c );
};

typedef Vec_2<float>  Vec_2f;
typedef Vec_2<double> Vec_2d;

template <class T> Vec_2<T> operator + ( const Vec_2<T> &v );
template <class T> Vec_2<T> operator - ( const Vec_2<T> &v );
template <class T> Vec_2<T> operator * ( T c, const Vec_2<T> &v );
template <class T> Vec_2<T>& operator << ( Vec_2<T> &vet, T dado );
template <class T> Vec_2<T>& operator ,  ( Vec_2<T> &vet, T dado );
template <class T> std::ostream& operator << ( std::ostream &os, const Vec_2<T> &v );

#include "Vec_2.inl"

#endif
