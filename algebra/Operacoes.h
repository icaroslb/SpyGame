#ifndef OPERACOES_H
#define OPERACOES_H

#include "Matriz_4.h"

template <class T>
Matriz_4<T> transladar ( T x, T y, T z )
{
    Matriz_4<T> m( Matriz_tipo::IDENTIDADE );

    m( 0, 3 ) = x;
    m( 1, 3 ) = y;
    m( 2, 3 ) = z;

    return m;
}

template <class T>
Matriz_4<T> escalar ( T x, T y, T z )
{
    Matriz_4<T> m( Matriz_tipo::IDENTIDADE );

    m( 0, 0 ) = x;
    m( 1, 1 ) = y;
    m( 2, 2 ) = z;

    return m;
}

template <class T>
Matriz_4<T> rotacionar ( Ori_transf tipo, T ang )
{
    Matriz_4<T> m( Matriz_tipo::IDENTIDADE );
    
    switch ( tipo )
    {
    case Ori_transf::xy:
        m( 0, 0 ) =  cos( ang ); m( 0, 1 ) =  sin( ang );
        m( 1, 0 ) = -sin( ang ); m( 1, 1 ) =  cos( ang );
    break;
    case Ori_transf::yz:
        m( 1, 1 ) =  cos( ang ); m( 1, 2 ) = -sin( ang );
        m( 2, 1 ) =  sin( ang ); m( 2, 2 ) =  cos( ang );
    break;
    case Ori_transf::zx:
        m( 0, 0 ) =  cos( ang ); m( 0, 2 ) = -sin( ang );
        m( 2, 0 ) =  sin( ang ); m( 2, 2 ) =  cos( ang );
    break;
    }

    return m;
}

#endif
