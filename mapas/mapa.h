#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "../personagens/Heroi.h"
#include "../personagens/Inimigo.h"
#include "../objetos/Barreira_2d.h"

template <class T>
class Mapa {
public:
    std::vector<Barreira_2d<T>> barreiras;

    Heroi<T> *heroi;

    Mapa ( const std::vector<Barreira_2d<T>> &barreiras
         , Heroi<T> *heroi )
    : barreiras( barreiras )
    , heroi( heroi )
    {}
};

#endif