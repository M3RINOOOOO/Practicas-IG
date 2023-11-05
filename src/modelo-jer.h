#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP

#include "grafo-escena.h"
#include "ig-aux.h"

class Helicoptero : public NodoGrafoEscena
{
public:
    Helicoptero();

};


class Cuerpo : public NodoGrafoEscena
{
public:
    Cuerpo();

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
    Cola();

};

#endif