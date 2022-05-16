#include <algorithm>

#include "Header2.h"

int Archivo_vacio_indice();
int Archivo_primer();

int Archivo_vacio_indice_materias();
int Archivo_segundo(vector<Materias>& list2);

int Archivo_vacio_codigo_materias();
int Archivo_tercer();

void buscar_alumno_para_calificaciones(vector<Materias> list2);

/*------------------------------------------------------------------------*/
/*----------------------------------MENU----------------------------------*/
/*------------------------------------------------------------------------*/

void buscar_alumno_para_promedio(vector<Materias> list2);

void imprime_mas_altas(vector<Materias> list2);


void menu()
{
	int opcion = 0;
	int seguro = 0;
	int bandera = 0;
	bool sale = true;
	vector<Materias> list2;

	do
	{
		cout << "\n________________Menu________________" << endl;
		cout << "1).Crear los tres archivos" << endl;
		cout << "2).Calificaciones individuales" << endl;
		cout << "3).Promedio de calificaciones por estudiante" << endl;
		cout << "4).Calificaciones mas alta por materia" << endl;
		cout << "5).END" << endl;

		cout << "\nEscoge una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			Archivo_vacio_indice();
			Archivo_primer();
			Archivo_vacio_indice_materias();
			Archivo_segundo(list2);
			Archivo_vacio_codigo_materias();
			Archivo_tercer();
			cout << "\nSe crearon los tres archivos" << endl;
			bandera = 1;
			break;
		case 2:
			{
				if (bandera == 1)
				{
					cout << "\nCalificaciones individuales" << endl;
					// Buscas ID y imprimes todas las calificaciones de ese objeto
					buscar_alumno_para_calificaciones(list2);
					break;
				}
				cout << "\nCrea primero los archivos" << endl;
				break;
			}
		case 3:
			{
				if (bandera == 1)
				{
					cout << "\nPromedio de calificaciones por estudiante" << endl;
					// Buscas ID y usas todas las calificaciones de ese objeto para hacer un promedio
					buscar_alumno_para_promedio(list2);
					break;
				}
				cout << "\nCrea primero los archivos" << endl;
				break;
			}
		case 4:
			{
				if (bandera == 1)
				{
					cout << "\nCalificaciones mas alta por materia" << endl;
					// Calificación más alta para cada atributo del registro
					imprime_mas_altas(list2);
					break;
				}
				cout << "\nCrea primero los archivos" << endl;
				break;
			}
		case 5:
			cout << "\nSeguro que quieres salir ?" << endl;
			cout << "1. Si" << endl;
			cout << "2. No" << endl;
			cout << "Decide: ";
			cin >> seguro;
			if (seguro == 1)
			{
				cout << "\nPrograma terminado" << endl;
				sale = false;
			}
			break;
		}
	}
	while (sale == true);
}

/*------------------------------------------------------------------------*/
/*--------------------------------Indice--------------------------------*/
/*------------------------------------------------------------------------*/

int Archivo_vacio_indice()
{
	ofstream file{
		"primer_archivo.dat", ios::out | ios::binary
	};

	if (!file)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	IndiceEstudiante out;

	for (int i = 0; i < 100; ++i)
	{
		file.write(reinterpret_cast<const char*>(&out), sizeof(IndiceEstudiante));
	}
	return 0;
}

int Archivo_primer()
{
	fstream outFile{
		"primer_archivo.dat", ios::in | ios::out | ios::binary
	};

	if (!outFile)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	//vector<IndiceEstudiante> list;
	//
	//map<int, string> indice;
	//map<int, string>::iterator i;


	IndiceEstudiante est1(1, "0203401", "Juan Pablo Cantu Rubio");
	IndiceEstudiante est2(4, "0231637", "Luis Rodrigo Consuelos Figueroa");
	IndiceEstudiante est3(6, "0234800", "Regina Dehesa Trujillo");
	IndiceEstudiante est4(10, "0247877", "Angel Esqueda Ochoa");
	IndiceEstudiante est5(23, "0199032", "Giovanni Medellin Ortega");
	IndiceEstudiante est6(34, "02411718", "Emiliano Montes Gomez");
	IndiceEstudiante est7(38, "0243057", "Alex Orihuela Ocampo");
	IndiceEstudiante est8(46, "0241528", "Ricrado Paredes Garcia");
	IndiceEstudiante est9(50, "0246723", "Ariana Rodriguez Castañeda");
	IndiceEstudiante est10(61, "0243165", "Lizbeth Trujillo Salgado");
	IndiceEstudiante est11(68, "0231584", "Carlos Santiago Villalobos Rubio");
	IndiceEstudiante est12(72, "0234313", "Ana Zazueta Hernandez");


	//vector<IndiceEstudiante> list = { est1, est2 };
	vector<IndiceEstudiante> list = {est1, est2, est3, est4, est5, est6, est7, est8, est9, est10, est11, est12};

	for (auto i : list)
	{
		outFile.seekp((i.getIndice() - 1) * sizeof(IndiceEstudiante));
		outFile.write(reinterpret_cast<const char*>(&i), sizeof(IndiceEstudiante));
	}

	return 0;
}

/*------------------------------------------------------------------------*/
/*--------------------------------MATERIAS--------------------------------*/
/*------------------------------------------------------------------------*/

int Archivo_vacio_indice_materias()
{
	ofstream file{"segundo_archivo.dat", ios::out | ios::binary};

	if (!file)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	IndiceEstudiante out;

	for (int i = 0; i < 100; ++i)
	{
		file.write(reinterpret_cast<const char*>(&out), sizeof(IndiceEstudiante));
	}
	return 0;
}

int Archivo_segundo(vector<Materias>& list2)
{
	ofstream file{
		"segundo_archivo.dat", ios::out | ios::binary
	};

	if (!file)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	Materias calif1(1, "0203401", 6.5, 7.6, 6, 7);
	Materias calif2(4, "0231637", 6.5, 4, 7, 9.4);
	Materias calif3(6, "0234800", 6.9, 7.0, 9.4, 10);
	Materias calif4(10, "0247877", 10, 9.8, 8.0, 7.6);
	Materias calif5(23, "0199032", 9.4, 7.2, 6.9, 10);
	Materias calif6(34, "02411718", 8.6, 8.0, 9.5, 7);
	Materias calif7(38, "0243057", 6.4, 7.6, 9.1, 8.6);
	Materias calif8(46, "0241528", 6.1, 9.1, 10, 9.8);
	Materias calif9(50, "0246723", 7.2, 6.9, 9.3, 10);
	Materias calif10(61, "0243165", 9.5, 6.4, 7.3, 6.8);
	Materias calif11(68, "0231584", 9.5, 7, 6.8, 7.6);
	Materias calif12(72, "0234313", 9.1, 10, 8.6, 9.5);

	list2 = {
		calif1, calif2, calif3, calif4, calif5, calif6, calif7, calif8, calif9, calif10, calif11, calif12
	};

	for (auto i : list2)
	{
		file.seekp((i.getIndice() - 1) * sizeof(Materias));
		file.write(reinterpret_cast<const char*>(&i), sizeof(Materias));
	}

	return 0;
}

/*------------------------------------------------------------------------*/
/*--------------------------SIGNIFICADOS CODIGOS--------------------------*/
/*------------------------------------------------------------------------*/

int Archivo_vacio_codigo_materias()
{
	ofstream file{
		"tercer_archivo.dat", ios::out | ios::binary
	};

	if (!file)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	codigo_materia out;

	for (int i = 0; i < 4; ++i)
	{
		file.write(reinterpret_cast<const char*>(&out), sizeof(codigo_materia));
	}
	return 0;
}

int Archivo_tercer()
{
	ofstream file{
		"tercer_archivo.dat", ios::out | ios::binary
	};

	if (!file)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	codigo_materia codig_materi1(1, "POO", "Programacion Orientada a Objeto");
	codigo_materia codig_materi2(2, "PA", "Programacion Avanzada");
	codigo_materia codig_materi3(3, "PYS", "Persona y Sociedad");
	codigo_materia codig_materi4(4, "AL", "Algenra Lineal");

	vector<codigo_materia> lista2 = {codig_materi1, codig_materi2, codig_materi3, codig_materi4};
	for (auto i : lista2)
	{
		file.seekp((i.getIndice() - 1) * sizeof(codigo_materia));
		file.write(reinterpret_cast<const char*>(&i), sizeof(codigo_materia));
	}
}

void buscar_alumno_para_calificaciones(const vector<Materias> list2)
{
	string id;
	cin >> id;
	cin.ignore();
	for (int i = 0; i < list2.size(); i++)
	{
		if (id == list2[i].getMatricula())
		{
			cout << "PA: " << list2[i].getCalif1() << endl;
			cout << "POO: " << list2[i].getCalif2() << endl;
			cout << "PYS: " << list2[i].getCalif3() << endl;
			cout << "AL: " << list2[i].getCalif4() << endl;
		}
	}
}

void buscar_alumno_para_promedio(const vector<Materias> list2)
{
	double promedio = 0;
	string id;
	cin >> id;
	cin.ignore();
	for (int i = 0; i < list2.size(); i++)
	{
		if (id == list2[i].getMatricula())
		{
			promedio += list2[i].getCalif1();
			promedio += list2[i].getCalif2();
			promedio += list2[i].getCalif3();
			promedio += list2[i].getCalif4();
		}
	}
	promedio = promedio / 4;
	cout << "Promedio: " << promedio << endl;
}

void imprime_mas_altas(const vector<Materias> list2)
{
	vector<double> poo;
	vector<double> pa;
	vector<double> pys;
	vector<double> al;

	double calif_poo = 0.0f;
	double calif_pa = 0.0f;
	double calif_pys = 0.0f;
	double calif_al = 0.0f;


	for (int i = 0; i < list2.size(); i++)
	{
		calif_pa = list2[i].getCalif1();
		calif_poo = list2[i].getCalif2();
		calif_pys = list2[i].getCalif3();
		calif_al = list2[i].getCalif4();

		// Append each calif to the corresponding vector
		poo.push_back(calif_poo);
		pa.push_back(calif_pa);
		pys.push_back(calif_pys);
		al.push_back(calif_al);
	}

	// Search the highest calif in each vector
	double max_poo = *max_element(poo.begin(), poo.end());
	double max_pa = *max_element(pa.begin(), pa.end());
	double max_pys = *max_element(pys.begin(), pys.end());
	double max_al = *max_element(al.begin(), al.end());

	vector<string> lista_matricula_poo, lista_matricula_pa, lista_matricula_pys, lista_matricula_al;

	// Search for the students with the highest califs in each field
	for (int i = 0; i < list2.size(); i++)
	{
		if (max_pa == list2[i].getCalif1())
		{
			lista_matricula_pa.push_back(list2[i].getMatricula());
		}
	}

	for (int i = 0; i < list2.size(); i++)
	{
		if (max_poo == list2[i].getCalif2())
		{
			lista_matricula_poo.push_back(list2[i].getMatricula());
		}
	}

	for (int i = 0; i < list2.size(); i++)
	{
		if (max_pys == list2[i].getCalif3())
		{
			lista_matricula_pys.push_back(list2[i].getMatricula());
		}
	}

	for (int i = 0; i < list2.size(); i++)
	{
		if (max_al == list2[i].getCalif4())
		{
			lista_matricula_al.push_back(list2[i].getMatricula());
		}
	}

	cout << "PA: " << max_pa;
	for (int i = 0; i < lista_matricula_pa.size(); i++)
	{
		cout << " " << lista_matricula_pa[i];
	}
	cout << endl;

	cout << "POO: " << max_poo;
	for (int i = 0; i < lista_matricula_poo.size(); i++)
	{
		cout << " " << lista_matricula_poo[i];
	}
	cout << endl;

	cout << "PYS: " << max_pys;
	for (int i = 0; i < lista_matricula_pys.size(); i++)
	{
		cout << " " << lista_matricula_pys[i];
	}
	cout << endl;

	cout << "AL: " << max_al;
	for (int i = 0; i < lista_matricula_al.size(); i++)
	{
		cout << " " << lista_matricula_al[i];
	}
	cout << endl;
}
