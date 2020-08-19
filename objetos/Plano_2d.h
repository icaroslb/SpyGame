#ifndef PLANO_2D_H
#define PLANO_2D_H

#include "../algebra/include_algebra.h"
#include "../engines/Engine_OpenGl.h"
#include "../shaders/Shader.h"

template< class T >
class Plano_2d {
public:
    union
    {
        Vec_2<T> vertices[4];
        struct {
            Vec_2<T> _s_e;
            Vec_2<T> _i_e;
            Vec_2<T> _i_d;
            Vec_2<T> _s_d;
        };
    };

    unsigned int VAO;
    unsigned int EBO;

    Plano_2d ( Vec_2<T> s_e, Vec_2<T> i_e, Vec_2<T> i_d, Vec_2<T> s_d )
    : _s_e( s_e )
    , _i_e( i_e )
    , _i_d( i_d )
    , _s_d( s_d )
    {
        unsigned int ordem_print[6] = { 0, 1, 2,
                                        2, 3, 0 };
        
        VAO = criar_vertice_buffer( vertices, sizeof(float), 2, 8, 1 );
	    EBO = criar_element_buffer( ordem_print, 6 );
    }

    void mostrar ()
    {
        usar_vertice_buffer( VAO );
		usar_element_buffer( EBO );

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0 );
    }
};

#endif