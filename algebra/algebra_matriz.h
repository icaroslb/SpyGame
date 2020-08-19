#ifndef ALGEBRA_MATRIZ_H
#define ALGEBRA_MATRIZ_H

#include <cmath>

#include "Matriz_2.h"
#include "Matriz_3.h"
#include "Matriz_4.h"

template <class T> T determinante ( const Matriz_2<T> &m );
template <class T> T determinante ( const Matriz_3<T> &m );
template <class T> T determinante ( const Matriz_4<T> &m );

template <class T> Matriz_2<T> transposta ( const Matriz_2<T> &m );
template <class T> Matriz_3<T> transposta ( const Matriz_3<T> &m );
template <class T> Matriz_4<T> transposta ( const Matriz_4<T> &m );

template <class T> T co_fator ( const Matriz_2<T> &m, size_t i, size_t j );
template <class T> T co_fator ( const Matriz_3<T> &m, size_t i, size_t j );
template <class T> T co_fator ( const Matriz_4<T> &m, size_t i, size_t j );

template <class T> T co_fator ( const Matriz_2<T> &m, size_t id );
template <class T> T co_fator ( const Matriz_3<T> &m, size_t id );
template <class T> T co_fator ( const Matriz_4<T> &m, size_t id );

template <class T> Matriz_2<T> inversa ( const Matriz_2<T> &m );
template <class T> Matriz_3<T> inversa ( const Matriz_3<T> &m );
template <class T> Matriz_4<T> inversa ( const Matriz_4<T> &m );

#include "algebra_matriz.inl"

#endif
