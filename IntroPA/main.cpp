#include <iostream>

using namespace std;

struct Estudiante
{
	int id;
	string nombre;
	string carrera;
	int semestre;
	float promedio;
};


int main()
{
	Estudiante Demian;
	Demian.id = 1;
	Demian.nombre = "Demian";

	cout << "ID: " << Demian.id << endl;
	cout << "Nombre: " << Demian.nombre << endl;

	/*cout << Demian << end;*/
}


// FUNCION SE USA CUANDO QUIERO CAMBIAR ALGUN DATO, Y REGRESARLO A LA FUNCION PRINCIPAL
// METODO SE USA CUANDO SOLO NECESITO HACER CAMBIOS EN LAS VARIABLES (TEMPORALES)


void suma2(int a, int b)
{
	cout << "SUMA METODO" << endl;
	int c = a + b;
	cout << "La suma es: " << c << endl;
	int resultado2 = 100;
	cout << "Resultado2: " << resultado2 << endl;
}


enum Modo_Menu
{
	principal,
	// 0
	altaProducto // 1
};


void suma2(int a, int b); // FUNCION NO TIENE REGRESO Y NO ESPECIFICAMOS TIPO DE DATO

int suma(int a, int b) // FUNCION TIENE REGRESO Y ESPECIFICAMOS TIPO DE DATO
{
	cout << "SUMA FUNCION" << endl;
	return a + b;
}


//cout << "Funciones y Metodos" << endl;
//int resultado = suma(5, 6);
//resultado = resultado + 9;
//cout << "La suma es: " << resultado << endl; /*(20)*/

//int resultado2 = 0;
//suma2(resultado2, 10);
//cout << "Resultado2: " << resultado2 << endl;
//int numero;
//cout << "Ingrese un numero: ";
//cin >> numero;
//cout << "El numero es: " << numero << endl;
