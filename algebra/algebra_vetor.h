#ifndef ALGEBRA_VETOR_H
#define ALGEBRA_VETOR_H

#include <cmath>

#include "Vec_2.h"
#include "Vec_3.h"
#include "Vec_4.h"

template <class T> T produto_escalar ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
template <class T> T produto_escalar ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
template <class T> T produto_escalar ( const Vec_4<T> &v1, const Vec_4<T> &v2 );

template <class T> T        produto_vetorial ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
template <class T> Vec_3<T> produto_vetorial ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
template <class T> Vec_4<T> produto_vetorial ( const Vec_4<T> &v1, const Vec_4<T> &v2 );

template <class T> T norma_quadrada ( const Vec_2<T> &v );
template <class T> T norma_quadrada ( const Vec_3<T> &v );
template <class T> T norma_quadrada ( const Vec_4<T> &v );

template <class T> T norma ( const Vec_2<T> &v );
template <class T> T norma ( const Vec_3<T> &v );
template <class T> T norma ( const Vec_4<T> &v );

template <class T> Vec_2<T> unitario ( const Vec_2<T> &v );
template <class T> Vec_3<T> unitario ( const Vec_3<T> &v );
template <class T> Vec_4<T> unitario ( const Vec_4<T> &v );

template <class T> Vec_2<T> projecao ( const Vec_2<T> &v, const Vec_2<T> &v_proje );
template <class T> Vec_3<T> projecao ( const Vec_3<T> &v, const Vec_3<T> &v_proje );
template <class T> Vec_4<T> projecao ( const Vec_4<T> &v, const Vec_4<T> &v_proje );

template <class T> Vec_2<T> projecao_unitario ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitario );
template <class T> Vec_3<T> projecao_unitario ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitario );
template <class T> Vec_4<T> projecao_unitario ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitario );

template <class T> Vec_2<T> projecao_inv ( const Vec_2<T> &v, const Vec_2<T> &v_proje );
template <class T> Vec_3<T> projecao_inv ( const Vec_3<T> &v, const Vec_3<T> &v_proje );
template <class T> Vec_4<T> projecao_inv ( const Vec_4<T> &v, const Vec_4<T> &v_proje );

template <class T> Vec_2<T> projecao_inv_unitario ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitario );
template <class T> Vec_3<T> projecao_inv_unitario ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitario );
template <class T> Vec_4<T> projecao_inv_unitario ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitario );

template <class T> T cos_entre_vetores ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
template <class T> T cos_entre_vetores ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
template <class T> T cos_entre_vetores ( const Vec_4<T> &v1, const Vec_4<T> &v2 );

template <class T> T sen_entre_vetores ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
template <class T> T sen_entre_vetores ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
template <class T> T sen_entre_vetores ( const Vec_4<T> &v1, const Vec_4<T> &v2 );

template <template <class> class T, class U> U angulo_cos ( const T<U> &v1, const T<U> &v2 );
template <template <class> class T, class U> U angulo_sen ( const T<U> &v1, const T<U> &v2 );

template <class T> T pseudoangulo ( const Vec_2<T> &v );
template <class T> T pseudoangulo ( const Vec_3<T> &v );
template <class T> T pseudoangulo ( const Vec_4<T> &v );


template <class T> T truncagem ( T valor );
template <class T> T truncagem ( T valor, T valor_max, T valor_min );

#include "algebra_vetor.inl"

#endif
