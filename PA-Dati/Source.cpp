//Hacer un programa en C++ que lea n números y determine cuál es el mayor,
//el menor y la media de los números leídos.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numeros;
	setlocale(LC_ALL, "spanish");
	int tam;
	cout << "¿Cuántos números?: ";
	cin >> tam;

	double media = 0;
	for (int i = 0; i < tam; i++)
	{
		int num;
		cout << "Introduce un número: ";
		cin >> num;
		numeros.push_back(num);
		media += num;
	}

	// Bubble sort
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam - 1; j++)
		{
			if (numeros[j] > numeros[j + 1])
			{
				int aux = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = aux;
			}
		}
	}
	media /= tam;

	for (int i = 0; i < tam; i++)
	{
		cout << numeros[i] << " ";
	}

	cout << "\nEl mayor número es: " << numeros[tam - 1] << endl;
	cout << "El menor número es: " << numeros[0] << endl;
	cout << "La media es: " << media << endl;
	return 0;
}
