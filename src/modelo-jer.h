#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP

#include "grafo-escena.h"


class Helicoptero : public NodoGrafoEscena
{
public:
    Helicoptero();
    unsigned leerNumParametros() const;
    void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

protected:
    glm::mat4 *rot_helice1 = nullptr;
    glm::mat4 *rot_helice2 = nullptr;
    glm::mat4 *tras_helicoptero = nullptr; 
    glm::mat4 *rot_cola = nullptr; 
};


class Cuerpo : public NodoGrafoEscena
{
public:
    Cuerpo(glm::mat4 *&movimiento);

};

class Aspa : public NodoGrafoEscena
{
public:
    Aspa();

};

class Helice : public NodoGrafoEscena
{
public:
    Helice(int n);

};

class Barra : public NodoGrafoEscena
{
public:
    Barra();

};

class Pata : public NodoGrafoEscena
{
public:
    Pata(int n);

};

class Cola : public NodoGrafoEscena
{
public:
    Cola(glm::mat4 *&movimiento1, glm::mat4 *&movimiento2);

};

class Triangulo_hel : public MallaInd
{
   public:
      Triangulo_hel();
};


class Parte_base_hel : public MallaInd
{
   public:
      Parte_base_hel();
};


class Cunia_hel : public MallaInd
{
   public:
      Cunia_hel();
};

class Nodo_cunia : public NodoGrafoEscena
{
    public:
    Nodo_cunia();

};

class Nodo_base_hel : public NodoGrafoEscena
{
    public:
    Nodo_base_hel();

};

#endif