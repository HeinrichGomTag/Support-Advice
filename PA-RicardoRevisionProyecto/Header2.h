#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*----------------------------------------------------------------------------------*/
/*--------------------------------------INDICE--------------------------------------*/
/*----------------------------------------------------------------------------------*/
class IndiceEstudiante
{
public:
	IndiceEstudiante(int indice = 65536, const string& matricula = "1234567", const string& name = " ")
	{
		this->indice = indice;
		setMatricula(matricula);
		setName(name);
	}

	void setMatricula(const string& matricula)
	{
		size_t length{matricula.size()};
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0';
	}

	void setName(const string& name)
	{
		size_t length{name.size()};
		length = (length < 20 ? length : 19);
		name.copy(this->name, length);
		this->name[length] = '\0';
	}

	int getIndice() const { return indice; }
	string getMatricula() const { return matricula; }
	string getName() const { return name; }


private:
	int indice;
	char matricula[8];
	char name[20];
};

/*----------------------------------------------------------------------------------*/
/*----------------------------------CALIFICACIONES----------------------------------*/
/*----------------------------------------------------------------------------------*/
class Materias
{
public:
	Materias(int indice = 65536, const string& matricula = "1234567", const double pa = 0.0, const double poo = 0.0,
	         const double pys = 0.0, const double al = 0.0)
	{
		this->indice = indice;
		setMatricula(matricula);
		calif1 = pa;
		calif2 = poo;
		calif3 = pys;
		calif4 = al;
	}

	void setMatricula(const string& matricula)
	{
		size_t length{matricula.size()};
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0';
	}

	int getIndice() const { return indice; }
	string getMatricula() const { return matricula; }
	double getCalif1() const { return calif1; }
	double getCalif2() const { return calif2; }
	double getCalif3() const { return calif3; }
	double getCalif4() const { return calif4; }

private:
	int indice;
	char matricula[8];
	char c1[4] = "PA1";
	double calif1;
	char c2[4] = "POO";
	double calif2;
	char c3[4] = "PYS";
	double calif3;
	char c4[4] = "AL";
	double calif4;
};

/*----------------------------------------------------------------------------------*/
/*----------------------------------CODIGO MATERIA----------------------------------*/
/*----------------------------------------------------------------------------------*/
class codigo_materia
{
public:
	codigo_materia(int indice = 65536, const string& id = "NON", const string& name = "NONE")
	{
		this->indice = indice;
		setClave(id);
		setNombre(name);
	}

	void setClave(const string& clave)
	{
		size_t length{clave.size()};
		length = (length < 4 ? length : 3);
		clave.copy(this->clave, length);
		this->clave[length] = '\0';
	}

	void setNombre(const string& nombre)
	{
		size_t length{nombre.size()};
		length = (length < 15 ? length : 14);
		nombre.copy(this->nombre, length);
		this->nombre[length] = '\0';
	}

	int getIndice() const { return indice; }

private:
	int indice;
	char clave[4];
	char nombre[15];
};
