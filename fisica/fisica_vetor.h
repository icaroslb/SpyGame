#ifndef FISICA_VETOR_H
#define FISICA_VETOR_H

#include <cmath>

#include "../algebra/Vec_2.h"
#include "../algebra/Vec_3.h"
#include "../algebra/Vec_4.h"

template <class T> bool teste_colisao ( const Vec_2<T> &p_1_1, const Vec_2<T> &p_1_2
                                      , const Vec_2<T> &p_2_1, const Vec_2<T> &p_2_2
                                      , const Vec_2<T> &normal, T &dist );

template <class T> Vec_2<T> colisao ( const Vec_2<T> &v, const Vec_2<T> &normal, T alfa, T beta );
template <class T> Vec_3<T> colisao ( const Vec_3<T> &v, const Vec_3<T> &normal, T alfa, T beta );
template <class T> Vec_4<T> colisao ( const Vec_4<T> &v, const Vec_4<T> &normal, T alfa, T beta );

#include "fisica_vetor.inl"

#endif
