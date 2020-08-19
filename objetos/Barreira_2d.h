#ifndef BARREIRA_2D_H
#define BARREIRA_2D_H

#include "../algebra/include_algebra.h"

template <class T>
class Barreira_2d {
public:
    Vec_2<T> p_inicial;
    Vec_2<T> p_final;
    Vec_2<T> normal;

    Barreira_2d ()
    {}

    Barreira_2d ( const Vec_2<T> &p_inicial, const Vec_2<T> &p_final )
    : p_inicial( p_inicial )
    , p_final( p_final )
    {
        Vec_2<T> vetor_barreira = p_final - p_inicial;

        normal = unitario( Vec_2<T>( -vetor_barreira._y, vetor_barreira._x ) );
    }

    Barreira_2d<T>& operator = ( const Barreira_2d<T> &n_barreira )
    {
        p_inicial = n_barreira.p_inicial;
        p_final = n_barreira.p_final;
        normal = n_barreira.normal;

        return *(this);
    }
};

#endif