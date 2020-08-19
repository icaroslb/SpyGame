#ifndef VEC_3_H
#define VEC_3_H

#include <iostream>

template <class T>
class Vec_4;

template <class T>
class Vec_3 {
public:
	
	union
	{
		T coord[3];
		struct { T _x, _y, _z; };
	};

	Vec_3<T> ( T x = 0, T y = 0, T z = 0 );
	
	T&       x ();
	const T& x () const;
	T&       y ();
	const T& y () const;
	T&       z ();
	const T& z () const;
	
	T&       operator [] ( int i );
	const T& operator [] ( int i ) const;
	
	Vec_3<T>  operator + ( const Vec_3<T> &v ) const;
	Vec_3<T>  operator - ( const Vec_3<T> &v ) const;
	Vec_3<T>  operator * ( const Vec_3<T> &v ) const;
	Vec_3<T>  operator + ( T c ) const;
	Vec_3<T>  operator - ( T c ) const;
	Vec_3<T>  operator * ( T c ) const;
	Vec_3<T>  operator / ( T c ) const;
	
	Vec_3<T>& operator  = ( const Vec_3<T> &v );
	Vec_3<T>& operator += ( const Vec_3<T> &v );
	Vec_3<T>& operator -= ( const Vec_3<T> &v );
	Vec_3<T>& operator *= ( const Vec_3<T> &v );
	Vec_3<T>& operator += ( T c );
	Vec_3<T>& operator -= ( T c );
	Vec_3<T>& operator *= ( T c );
	Vec_3<T>& operator /= ( T c );
};

typedef Vec_3<float>  Vec_3f;
typedef Vec_3<double> Vec_3d;

template <class T> Vec_3<T> operator + ( const Vec_3<T> &v );
template <class T> Vec_3<T> operator - ( const Vec_3<T> &v );
template <class T> Vec_3<T> operator * ( T c, const Vec_3<T> &v );
template <class T> Vec_2<T>& operator << ( Vec_2<T> &vet, T dado );
template <class T> Vec_2<T>& operator ,  ( Vec_2<T> &vet, T dado );
template <class T> std::ostream& operator << ( std::ostream &os, const Vec_3<T> &v );

#include "Vec_3.inl"

#endif
