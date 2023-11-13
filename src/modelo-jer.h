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
    Helice();

};

class Barra : public NodoGrafoEscena
{
public:
    Barra();

};

class Pata : public NodoGrafoEscena
{
public:
    Pata();

};

class Cola : public NodoGrafoEscena
{
public:
    Cola(glm::mat4 *&movimiento1, glm::mat4 *&movimiento2);

};

#endif