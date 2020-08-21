#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <vector>
#include <string>
#include "../algebra/algebra_vetor.h"
#include "../shaders/Shader.h"
#include "../leitor_imagem/Leitor_imagem.h"
#include "../engines/Engine_OpenGl.h"

template <class T>
class Personagem {
public:
    Vec_2<T> posicao;

    unsigned int VAO;
    unsigned int EBO;
    
    Personagem ()
    : VAO( 0 )
    , EBO( 0 )
    {}

    Personagem ( const Vec_2<T> &posicao, unsigned int VAO, unsigned int EBO )
    : posicao( posicao )
    , VAO( VAO )
    , EBO( EBO )
    {}

    virtual void mover ( const Vec_2<T> &direcao, T magnitude ) = 0;

    virtual void mostrar_personagem ( const Shader &shader ) = 0;
    
    virtual void mostrar_auxiliar ( const Shader &shader ) = 0;
    
};

#endif