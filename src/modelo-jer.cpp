#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"

using namespace glm;

Helicoptero::Helicoptero()
{
    agregar(new Cuerpo());
    agregar(translate( glm::vec3( 0.0, 0.0, -2) ));
    agregar(new Cola());
    agregar(scale( glm::vec3( 0.3, 0.3, 0.3) ));
    agregar(scale( glm::vec3( -1.0, 1.0, 1.0) ));
    agregar(translate( glm::vec3( -2.5, -6.75, 20) ));
    agregar(new Pata());    
    agregar(translate( glm::vec3( 5, 0, 0) ));
    agregar(new Pata());
}

Cuerpo::Cuerpo()
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
    agregar(new Helice());
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
    agregar(scale( glm::vec3( 0.5, 0.5, 2) ));
    agregar(new Cubo());
    ponerColor({1, 1, 0});
}

Cola::Cola()
{
    agregar(new Barra());
    agregar(rotate( float(3*M_PI/2), glm::vec3( 0.0, 1.0, 0.0) ));
    agregar(translate( glm::vec3( -2, 0.5, -0.5) ));
    agregar(new Cunia_hel());
    agregar(translate ( glm::vec3( 0.35, 0.5, -0.5) ));
    agregar(new Helice());
}

Pata::Pata()
{
    agregar(scale( glm::vec3( 1, 1, 4) ));
    agregar(new Barra());
    agregar(scale( glm::vec3( 1, 0.85, 1) ));
    agregar(rotate( float(M_PI/2), glm::vec3( 1.0, 0.0, 0.0) ));
    agregar(translate( glm::vec3( 0.0, 0.0, -2.55) ));
    agregar(new Barra());
    
}