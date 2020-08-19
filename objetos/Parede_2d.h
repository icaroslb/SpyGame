#ifndef PAREDE_2D_H
#define PAREDE_2D_H

#include "Barreira_2d.h"

template <class T>
class Parede_2d {
public:
    Barreira_2d<T> barreiras[4];

    Parede_2d () {}
    Parede_2d ( const Vec_2<T> &ponto_inf_esq, T largura, T altura )
    {
        barreiras[0] = Barreira_2d<T>( ponto_inf_esq, ponto_inf_esq + Vec_2<T>( largura, T(0) ) );
        barreiras[1] = Barreira_2d<T>( barreiras[0].p_final, barreiras[0].p_final + Vec_2<T>( T(0), altura ) );
        barreiras[2] = Barreira_2d<T>( barreiras[1].p_final, barreiras[1].p_final + Vec_2<T>( -largura, T(0) ) );
        barreiras[3] = Barreira_2d<T>( barreiras[2].p_final, ponto_inf_esq );
    }

    Parede_2d ( const Vec_2<T> &p_1, const Vec_2<T> &p_2, const Vec_2<T> &p_3, const Vec_2<T> &p_4 )
    {
        barreiras[0] = Barreira_2d<T>( p_1, p_2 );
        barreiras[1] = Barreira_2d<T>( p_2, p_3 );
        barreiras[2] = Barreira_2d<T>( p_3, p_4 );
        barreiras[3] = Barreira_2d<T>( p_4, p_1 );
    }

    bool testar_colisao ( const Vec_2<T> &p_1, const Vec_2<T> &p_2, Vec_2<T> &normal,  T &dist )
    {
        T teste_dist;
        T menor_dist = std::numeric_limits<T>::infinity();
        bool colidiu = false;
        int id_menor;
        
        for ( int i = 0; i < 4; i++ ) {
            
            if ( teste_colisao( p_1, p_2
               , barreiras[i].p_inicial, barreiras[i].p_final
               , barreiras[i].normal, teste_dist ) ) {
            
                if ( menor_dist > teste_dist
                && teste_dist > T(1.0e-3) ) {
                    id_menor = i;
                    menor_dist = teste_dist;
                }

                colidiu = true;
            }
        }

        if ( colidiu ) {
            normal = barreiras[id_menor].normal;
            dist = menor_dist;
        }

        return colidiu;
    }
};

#endif