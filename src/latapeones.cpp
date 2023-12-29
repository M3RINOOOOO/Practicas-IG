#include "latapeones.h"

using namespace std;
using namespace glm;

Peon::Peon(int nperfiles) : MallaRevolPLY("peon.ply", nperfiles) {}

Lata::Lata() {
    NodoGrafoEscena* actual = new NodoGrafoEscena();

    unsigned identTapa = 0;
    unsigned identBase = 1;
    unsigned identCara = 2;

    Textura* cocacola = new Textura("lata-coke.jpg");
    Material* materialLata = new Material(cocacola, 0.75, 0.65, 0.25, 50.0);
    Material* materialBases = new Material(0.35, 0.45, 0.25, 50.0);

    NodoGrafoEscena* base = new NodoGrafoEscena();
    NodoGrafoEscena* cara = new NodoGrafoEscena();
    NodoGrafoEscena* tapa = new NodoGrafoEscena();

    base->agregar(materialBases);
    base->agregar(new MallaRevolPLY("lata-pinf.ply", 32));
    tapa->agregar(materialBases);
    tapa->agregar(new MallaRevolPLY("lata-psup.ply", 32));

    cara->agregar(materialLata);
    cara->agregar(new MallaRevolPLY("lata-pcue.ply", 32));

    actual->agregar(base);
    actual->agregar(cara);
    actual->agregar(tapa);

    agregar(actual);
}

LataPeones::LataPeones() {
    NodoGrafoEscena* actual = new NodoGrafoEscena();

    unsigned identPeonMadera = 0;
    unsigned identPeonBlanco = 1;
    unsigned identPeonNegro = 2;
    unsigned identLata = 3;

    TexturaXY* texturaXY_madera = new TexturaXY("text-madera.jpg");
    Material* materialPeonMadera = new Material(texturaXY_madera, 0.5, 0.6, 0.5, 50.0);
    Material* materialPeonBlanco = new Material(0.5, 0.2, 0.5, 5.0);
    Material* materialPeonNegro = new Material(0.01, 0.2, 0.5, 50.0);

    NodoGrafoEscena* peonMadera = new NodoGrafoEscena();
    NodoGrafoEscena* peonNegro = new NodoGrafoEscena();
    NodoGrafoEscena* peonBlanco = new NodoGrafoEscena();

    Lata* lata = new Lata();

    peonMadera->agregar(translate(vec3(0.0, 0.4, 0.7)));
    peonMadera->agregar(scale(vec3(0.25, 0.25, 0.25)));
    peonMadera->agregar(materialPeonMadera);
    peonMadera->agregar(new Peon(32));

    peonNegro->agregar(translate(vec3(0.6, 0.4, 0.7)));
    peonNegro->agregar(scale(vec3(0.25, 0.25, 0.25)));
    peonNegro->agregar(materialPeonNegro);
    peonNegro->agregar(new Peon(32));

    peonBlanco->agregar(translate(vec3(1.2, 0.4, 0.7)));
    peonBlanco->agregar(scale(vec3(0.25, 0.25, 0.25)));
    peonBlanco->agregar(materialPeonBlanco);
    peonBlanco->agregar(new Peon(32));


    actual->agregar(peonMadera);
    actual->agregar(peonBlanco);
    actual->agregar(peonNegro);

    actual->agregar(lata);


    agregar(actual);
}
