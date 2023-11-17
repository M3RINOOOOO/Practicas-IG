#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"
using namespace glm;

Helicoptero::Helicoptero()
{
    ponerNombre("Helicoptero");
    
    unsigned ind = agregar(translate(glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(new Cuerpo(rot_helice1));
    agregar(translate( glm::vec3( 0.0, 0.0, -1) ));
    agregar(new Cola(rot_helice2,rot_cola));
    agregar(scale( glm::vec3( -0.3, 0.3, 0.3) ));
    agregar(translate( glm::vec3( -2.5, -6.75, 18) ));
    agregar(new Pata());    
    agregar(translate( glm::vec3( 5, 0, 0) ));
    agregar(new Pata());
    tras_helicoptero = leerPtrMatriz(ind);
}

unsigned Helicoptero::leerNumParametros() const
{
    return 4;
}

void Helicoptero::actualizarEstadoParametro(const unsigned iParam, const float t_sec)
{
    assert(iParam < leerNumParametros());
    float v;
    switch(iParam)
    {
        case 0:
            {
                v = 0 + 2*sin( 2*M_PI * 0.2 * t_sec);
                *tras_helicoptero = translate( glm::vec3( 0.0, v, 0.0));
            }
            break;
        case 1:
            {
                //Para que gire en ambos sentidos
                //v = 2 + 2 * sin( M_PI * 0.2 * t_sec*2);
                //*rot_helice1 = rotate( float(M_PI/2) * v, glm::vec3( 0.0, 0.0, 1.0));   

                //Para que gire indefinidamente      
                v = 0 + 2*M_PI*1.225*t_sec;   
                *rot_helice1 = rotate( v, glm::vec3( 0.0, 0.0, 1.0));
            }
            break;
        case 2: 
            {
                //Para que gire en ambos sentidos
                //v = 2 + 2 * sin( M_PI * 0.2 * t_sec*2);
                //*rot_helice2 = rotate( float(M_PI/2) * v, glm::vec3( 0.0, 0.0, 1.0));   

                //Para que gire indefinidamente        
                v = 0 + 2*M_PI*2.5*t_sec;  
                *rot_helice2 = rotate( v, glm::vec3( 0.0, 0.0, 1.0));
            }
            break;
        case 3:
            {
                v = 0 + M_PI/5 * sin( 2*M_PI * 0.2 * t_sec);
                *rot_cola = rotate( v, glm::vec3( 0.0, 1.0, 0.0));

            }
    }        
}

Cuerpo::Cuerpo(glm::mat4 *&movimiento)
{
    agregar(new Parte_base_hel());
    agregar(scale( glm::vec3( 1.0, -1.0, 1.0) ));
    agregar(new Parte_base_hel());
    agregar(scale( glm::vec3( -1.0, 1.0, 1.0) ));
    agregar(new Parte_base_hel());
    agregar(scale( glm::vec3( 1.0, -1.0, 1.0) ));
    agregar(new Parte_base_hel());
    agregar(translate( glm::vec3( 0.0, 2.5, 4.5) ));
    agregar(scale( glm::vec3( 3.0, 2.0, 3.0) ));
    agregar(rotate( float(M_PI/2), glm::vec3( 1.0, 0.0, 0.0) ));
    unsigned ind = agregar(rotate(0.0f, glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(new Helice());
    movimiento = leerPtrMatriz(ind);
}

Aspa::Aspa()
{
    agregar(new Triangulo_hel());
    agregar(scale( glm::vec3( 1.0, -1.0, 1.0) ));
    agregar(new Triangulo_hel());
}

Helice::Helice()
{
    agregar(new Aspa());
    agregar(rotate( float(M_PI/2), glm::vec3( 0.0, 0.0, 1.0) ));
    agregar(new Aspa());
    agregar(rotate( float(M_PI/2), glm::vec3( 0.0, 0.0, 1.0) ));
    agregar(new Aspa());
    agregar(rotate( float(M_PI/2), glm::vec3( 0.0, 0.0, 1.0) ));
    agregar(new Aspa());
    agregar(scale( glm::vec3( 0.1, 0.1, 0.5) ));
    agregar(rotate( float(M_PI/2), glm::vec3( 1.0, 0.0, 0.0) ));
    agregar(new Cilindro(8,40));
}

Barra::Barra()
{
    agregar(scale( glm::vec3( 0.5, 0.5, 1) ));
    agregar(new Cubo());
    ponerColor({1, 1, 0});
}

Cola::Cola(glm::mat4 *&movimiento1,glm::mat4 *&movimiento2)
{
    agregar(new Barra());
    unsigned ind2 = agregar(rotate(0.0f, glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(translate( glm::vec3( 0.0, 0.0, -1.8) ));
    agregar(new Barra());
    agregar(rotate( float(3*M_PI/2), glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(translate( glm::vec3( -1, 0.5, -0.5) ));
    agregar(new Cunia_hel());
    agregar(translate ( glm::vec3( 0.35, 0.5, -0.5) ));
    unsigned ind1 = agregar(rotate(0.0f, glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(new Helice());
    movimiento1 = leerPtrMatriz(ind1);
    movimiento2 = leerPtrMatriz(ind2);
}

Pata::Pata()
{
    agregar(scale( glm::vec3( 1, 1, 6) ));
    agregar(new Barra());
    agregar(scale( glm::vec3( 1, 2, 1) ));
    agregar(rotate( float(M_PI/2), glm::vec3( 1.0, 0.0, 0.0) ));
    agregar(translate( glm::vec3( 0.0, 0.0, -1.25) ));
    agregar(new Barra());
    
}