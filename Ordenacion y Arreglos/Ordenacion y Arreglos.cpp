#include <iostream>
using namespace std;

class Animal
{
	int placa;
	string nombre;
	float estatura;
};

int main()
{
	int v[10] = {3, 34, 1, 53, 15, 6, 8, 5, 6, 4};

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << "Elemento en la posicion: " << i << " es: " << v[i] << endl;
	}
}
