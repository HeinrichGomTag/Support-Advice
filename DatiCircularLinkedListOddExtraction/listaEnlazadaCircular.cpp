#include "listaEnlazadaCircular.h"

ListaCircular::ListaCircular()
{
	setlocale(LC_ALL, "");
	Cabecera = Final = nullptr;
	Revisado = Anterior = nullptr;
	Nodo = nullptr;
	numNodos = 0;
}

ListaCircular::~ListaCircular()
{
}

void ListaCircular::InsertarInicio(string nva)
{
	Nodo = new Palabra();
	Nodo->dato = nva;
	if (!Cabecera)
	{
		Cabecera = Nodo;
		Final = Nodo;
		Revisado = Nodo;
	}
	Nodo->siguiente = Cabecera;
	Final->siguiente = Nodo;
	Cabecera = Nodo;
	Revisado = Nodo;
	numNodos++;
}

void ListaCircular::InsertarFinal(string nva)
{
	if (!Cabecera)
	{
		InsertarInicio(nva);
		return;
	}
	Nodo = new Palabra;
	Nodo->dato = nva;
	Final->siguiente = Nodo;
	Nodo->siguiente = Cabecera;
	Final = Nodo;
	numNodos++;
}

void ListaCircular::Extraer(string extraer)
{
	if (!Cabecera)
	{
		cout << "Lista vacia" << endl;
		return;
	}
	if (Cabecera == Final)
	{
		delete Cabecera;
		Cabecera = Final = nullptr; //Regresa a su estado inicial
		return;
	}
	if (extraer == Cabecera->dato)
	{
		//Si el dato a extraer es el primero
		cout << "Extraer: " << Cabecera->dato << endl;
		Nodo = Cabecera;
		Cabecera = Cabecera->siguiente; //El nuevo inicio es el siguiente
		Final->siguiente = Cabecera; //El final apunta al nuevo inicio
		delete Nodo;
		numNodos--;
		return;
	}
	Revisado = Cabecera;
	while (Revisado->siguiente != Cabecera)
	{
		//Recorre la lista
		if (Revisado->siguiente->dato == extraer)
		{
			//Si el siguiente es el dato a extraer
			Nodo = Revisado->siguiente;
			Revisado->siguiente = Nodo->siguiente;
			delete Nodo;
			numNodos--;
			return;
		}
		Revisado = Revisado->siguiente;
	}
}

bool ListaCircular::Buscar(string buscada)
{
	if (!Cabecera)
		return false;
	if (Revisado == nullptr)
	{
		Revisado = Cabecera;
		Anterior = Final;
	}

	Nodo = Revisado;
	do
	{
		if (Nodo->dato == buscada)
		{
			Revisado = Nodo;
			return true;
		}
		Anterior = Nodo;
		Nodo = Nodo->siguiente;
	}
	while (Nodo != Revisado);

	return false;
}

void ListaCircular::Mostrar()
{
	if (!Cabecera)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	Nodo = Cabecera;
	cout << "\nLISTA:" << endl;
	do
	{
		cout << "\t" << Nodo->dato;
		if (Nodo == Cabecera)
			cout << "\t<-- Cabecera";
		if (Nodo == Final)
			cout << "\t<-- Final";
		cout << endl;
		Nodo = Nodo->siguiente;
	}
	while (Nodo != Cabecera);
}

void ListaCircular::enumerar()
{
	Nodo = Cabecera;
	bool wat = false;
	do
	{
		if (wat == false)
		{
			Nodo->par = false;
			wat = true;
		}
		else
		{
			Nodo->par = true;
			wat = false;
		}
		Nodo = Nodo->siguiente;
	}
	while (Nodo != Cabecera);
}

void ListaCircular::ExtraerImpares()
{
	if (!Cabecera)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	enumerar();
	string extraida;
	Nodo = Cabecera;
	do
	{
		if (Cabecera == Final)
		{
			delete Cabecera;
			Cabecera = Final = nullptr; //Regresa a su estado inicial
			return;
		}
		extraida = Nodo->dato;
		Extraer(extraida);
		Nodo = Nodo->siguiente;
	}
	while (numNodos != 1);
	cout << "Se han eliminado los impares" << endl;
	Mostrar();
}

int ListaCircular::imprimirNumNodos()
{
	return numNodos;
}
