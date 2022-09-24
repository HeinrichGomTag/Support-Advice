
#include <iostream>
using namespace std;

int main()
{
    double sumar = 0;
    double promedio;
    double miarreglo[5] ={4,2,3,1,5};

    for(int i = 0; i < 5; i++){
        sumar = sumar + miarreglo[i];
    }
    promedio = sumar / 5;
    cout << "El promedio es: " << promedio << endl;


    //bubble sort
//    for(int i = 0; i < 5; i++){
//        for(int j = 0; j < 5; j++){
//            if(miarreglo[i] < miarreglo[j]){
//                double aux = miarreglo[i];
//                miarreglo[i] = miarreglo[j];
//                miarreglo[j] = aux;
//            }
//        }
//    }




    for (int i = 0; i < 5; ++i) {
        cout << miarreglo[i] << endl;
    }
}