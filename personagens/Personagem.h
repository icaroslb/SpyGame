#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../algebra/algebra_vetor.h"
#include "../shaders/Shader.h"

template <class T>
class Personagem {
public:
    Vec_2<T> posicao;

    unsigned int VAO;
    unsigned int EBO;
    
    Personagem ( const Vec_2<T> &posicao, unsigned int VAO, unsigned int EBO )
    : posicao( posicao )
    , VAO( VAO )
    , EBO( EBO )
    {}

    virtual void mover ( const Vec_2<T> &direcao, T magnitude ) = 0;

    virtual void mostrar ( const Shader &shader ) = 0;
    
};

#endif