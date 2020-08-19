#ifndef VEC_4_H
#define VEC_4_H

#include <iostream>
#include <cstring>

#include "Vec_3.h"

template <class T>
class Vec_4 {
public:
	
	union
	{
		T coord[4];
		struct { T _x, _y, _z, _w; };
	};
	
	Vec_4<T> ( T x = 0, T y = 0, T z = 0, T w = 0 );
	
	T& x ();
	const T& x () const;
	T& y ();
	const T& y () const;
	T& z ();
	const T& z () const;
	T& w ();
	const T& w () const;
	
	T&       operator [] ( int i );
	const T& operator [] ( int i ) const;
	
	Vec_4<T>  operator + ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator - ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator * ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator + ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator - ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator * ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator + ( T c ) const;
	Vec_4<T>  operator - ( T c ) const;
	Vec_4<T>  operator * ( T c ) const;
	Vec_4<T>  operator / ( T c ) const;
	
	Vec_4<T>  operator  * ( const Vec_4<T> &v );
	
	Vec_4<T>& operator  = ( const Vec_4<T> &v );
	Vec_4<T>& operator += ( const Vec_4<T> &v );
	Vec_4<T>& operator -= ( const Vec_4<T> &v );
	Vec_4<T>& operator *= ( const Vec_4<T> &v );
	Vec_4<T>& operator += ( T c );
	Vec_4<T>& operator -= ( T c );
	Vec_4<T>& operator *= ( T c );
	Vec_4<T>& operator /= ( T c );

	operator Vec_3<T> () { return Vec_3<T>( _x, _y, _z ); }
	operator Vec_3<T> () const { return Vec_3<T>( _x, _y, _z ); }

};

typedef Vec_4<float>  Vec_4f;
typedef Vec_4<double> Vec_4d;

template <class T> Vec_4<T> operator + ( const Vec_4<T> &v );
template <class T> Vec_4<T> operator - ( const Vec_4<T> &v );
template <class T> Vec_4<T> operator * ( T c, const Vec_4<T> &v );
template <class T> Vec_4<T>& operator << ( Vec_4<T> &vet, T dado );
template <class T> Vec_4<T>& operator ,  ( Vec_4<T> &vet, T dado );
template <class T> std::ostream& operator << ( std::ostream &os, const Vec_4<T> &v );

template <class T> Vec_4<T>  operator + ( const Vec_3<T> &v3, const Vec_4<T> &v4 );
template <class T> Vec_4<T>  operator - ( const Vec_3<T> &v3, const Vec_4<T> &v4 );
template <class T> Vec_4<T>  operator * ( const Vec_3<T> &v3, const Vec_4<T> &v4 );

#include "Vec_4.inl"

#endif
