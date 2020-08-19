#ifndef CANVAS_H
#define CANVAS_H

#include "../algebra/include_algebra.h"
#include "../engines/Engine_OpenGl.h"
#include "../shaders/Shader.h"

template <class T>
class Pixel {
public:
    union {
        T coord[3];
        struct {
            T r;
            T g;
            T b;
        };
    };

    Pixel ( T r = T(1), T g= T(1), T b= T(1) )
    : r( r )
    , g( g )
    , b( b ) {}

    Pixel<T>& operator = ( Pixel<T> cores ) {
        memcpy( coord, cores.coord, 3 * sizeof(T) );
        return (*this);
    }
    Pixel<T>& operator = ( Vec_3<T> cores ) {
        memcpy( coord, cores.coord, 3 * sizeof(T) );
        return (*this);
    }

    Pixel<T>& operator + ( Pixel<T> cores ) {
        Pixel<T> soma;
        
        for ( size_t i = 0; i < 3; i++ )
            soma[i] = coord[i] + cores.coord[i];
        return soma;
    }
    Pixel<T>& operator + ( Vec_3<T> cores ) {
        Pixel<T> soma;
        
        for ( size_t i = 0; i < 3; i++ )
            soma[i] = coord[i] + cores.coord[i];
        return soma;
    }

    Pixel<T>& operator - ( Pixel<T> cores ) {
        Pixel<T> sub;
        
        for ( size_t i = 0; i < 3; i++ )
            sub[i] = coord[i] - cores.coord[i];
        return sub;
    }
    Pixel<T>& operator - ( Vec_3<T> cores ) {
        Pixel<T> sub;
        
        for ( size_t i = 0; i < 3; i++ )
            sub[i] = coord[i] - cores.coord[i];
        return sub;
    }

    Pixel<T>& operator * ( Pixel<T> cores ) {
        Pixel<T> mult;
        
        for ( size_t i = 0; i < 3; i++ )
            mult[i] = coord[i] * cores.coord[i];
        return mult;
    }
    Pixel<T>& operator * ( Vec_3<T> cores ) {
        Pixel<T> mult;
        
        for ( size_t i = 0; i < 3; i++ )
            mult[i] = coord[i] * cores.coord[i];
        return mult;
    }

    
    Pixel<T>& operator += ( Pixel<T> cores ) {       
        for ( size_t i = 0; i < 3; i++ )
            coord[i] += cores.coord[i];
        return (*this);
    }
    Pixel<T>& operator += ( Vec_3<T> cores ) {
        for ( size_t i = 0; i < 3; i++ )
            coord[i] += cores.coord[i];
        return (*this);
    }

    Pixel<T>& operator -= ( Pixel<T> cores ) {
        for ( size_t i = 0; i < 3; i++ )
            coord[i] -= cores.coord[i];
        return (*this);
    }
    Pixel<T>& operator -= ( Vec_3<T> cores ) {
        for ( size_t i = 0; i < 3; i++ )
            coord[i] -= cores.coord[i];
        return (*this);
    }

    Pixel<T>& operator *= ( Pixel<T> cores ) {
        for ( size_t i = 0; i < 3; i++ )
            coord[i] *= cores.coord[i];
        return (*this);
    }
    Pixel<T>& operator *= ( Vec_3<T> cores ) {
        for ( size_t i = 0; i < 3; i++ )
            coord[i] *= cores.coord[i];
        return (*this);
    }
};



template <class T>
class Canvas {
public:
    Pixel<T> *pixels;
    int largura;
    int altura;
    unsigned int id_canvas;
    unsigned int VAO;
    unsigned int EBO;

    Engine_OpenGl *engine;


    /*! Canvas
    **  Entrada: A largura e a altura do canvas e o engine do OpenGl
    **  Saída:
    **  Cria uma textura e o vetor que será guardado os valores da textura
    */
    Canvas ( int largura, int altura, Engine_OpenGl &opengl )
    : largura( largura )
    , altura( altura )
    , engine( &opengl ) {
        pixels = new Pixel<T>[largura * altura];

        glGenTextures( 1, &id_canvas );
        glBindTexture( GL_TEXTURE_2D, id_canvas );
	
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );	
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, largura, altura, 0, GL_RGB, GL_FLOAT, pixels );

        T vertices_img[] = { T(-1.0), T(-1.0), T(0.0), T(0.0),
	                         T( 1.0), T(-1.0), T(1.0), T(0.0),
	                         T( 1.0), T( 1.0), T(1.0), T(1.0),
	                         T(-1.0), T( 1.0), T(0.0), T(1.0) };
        unsigned int indices_img[] = { 0, 1, 3,
	                                   1, 2, 3 };
        int divisoes_img[] = { 2, 2 };
        
        VAO = opengl.criar_vertice_buffer( vertices_img, sizeof(T), 4, 16, 2, divisoes_img );
	    EBO = opengl.criar_element_buffer( indices_img, 6 );
    }

    /*! operator ()
    **  Entrada: Posição x e y desejada
    **  Saída:   O Pixel referente as posições
    **  A função acha o Pixel referente aos x e y passados. Como a textura é carregada
    **  iniciando pelo ponto inferior esquerdo, fazemos a troca das ordens das colunas
    */
    Pixel<T>& operator () ( size_t x, size_t y ) {
        return pixels[ ((altura - x - 1) * largura) + y ];
    }

     /*! atualizar
    **  Entrada: 
    **  Saída:
    **  Atualiza os valores da textura
    */
    void atualizar () {
        glBindTexture( GL_TEXTURE_2D, id_canvas );

        glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, largura, altura, GL_RGB, GL_FLOAT, pixels );
    }

    /*! printar
    **  Entrada: O shader utilizado
    **  Saída:
    **  Printa a textura em um plano cobrindo a tela nos valores de -1 a 1
    */
    void printar ( Shader &shader ) {
        engine->usar_vertice_buffer( VAO );
		engine->usar_element_buffer( EBO );

        shader.usar();

        glBindTexture( GL_TEXTURE_2D, id_canvas );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }

    ~Canvas ()
    {
        delete [] pixels;
    }
};

#endif
