#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Palabra
{
	string dato;
	bool par;
	Palabra* siguiente;
};

class ListaCircular
{
public:
	ListaCircular();
	~ListaCircular();
	void InsertarFinal(string);
    void InsertarInicio(string);
	void Extraer(string);
    void ExtraerImpares();
	bool Buscar(string);
    void enumerar();
	void Mostrar();
    int imprimirNumNodos();
private:
	Palabra* Cabecera, * Final, * Nodo, * Revisado, * Anterior;
    int numNodos;
};
