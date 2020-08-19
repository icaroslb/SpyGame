#ifndef INIMIGO_H
#define INIMIGO_H

#include <vector>
#include "Personagem.h"

template <class T>
class Inimigo : public Personagem<T> {
public:
    Vec_2<T> direcao;
    T tamanho;
    T angulo;
    T tempo_caminho;
    T tempo_espera;
    std::vector<Vec_2<T>> caminho;
    int estado;
    
    Inimigo ( const Vec_2<T> &posicao, Vec_2<T> direcao, T tamanho, T angulo, unsigned int VAO, unsigned int EBO )
    : Personagem<T>( posicao, VAO, EBO )
    , direcao( unitario( direcao ) )
    , tamanho( tamanho )
    , angulo( cos( angulo ) )
    {}

    void determinar_caminho ( const std::vector<Vec_2<T>> &novo_caminho, T novo_tempo_caminho, T novo_tempo_espera )
    {
        caminho = novo_caminho;
        tempo_caminho = novo_tempo_caminho;
        tempo_espera = novo_tempo_espera;
    }

    void mover ( const Vec_2<T> &direcao, T magnitude )
    {
        Personagem<T>::posicao += direcao * magnitude;
    }

    void loop ( T tempo )
    {
        if ( estado % 2 ) {

        } else {

        }
    }
};

#endif