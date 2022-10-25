/*
Construye una aplicación con C++ que genere una lista circular de nombres y:
a)   Inserte tantos nombres como el usuario quiera
b)   Informe cuantos nodos tiene
c)   Extraiga e informe los nodos impares, reiteradamente, hasta que quede vacía
d)   Opción para mostrar la lista completa en cualquier momento
*/

#include "listaEnlazadaCircular.h"

int main(){
    int opc;
    string nombre;
    ListaCircular lista;
    do{
        cout << "1. Insertar nombre" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Extraer impares" << endl;
        cout << "4. Ver numero de nodos" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "Nombre: ";
                cin >> nombre;
                lista.InsertarFinal(nombre);
                break;
            case 2:
                lista.Mostrar();
                break;
            case 3:
                lista.ExtraerImpares();
                break;
            case 4:
                cout << "Numero de nodos: " << lista.imprimirNumNodos() << endl;
                break;
            case 5:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opc != 5);
}