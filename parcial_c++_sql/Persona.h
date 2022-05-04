#pragma once
#include<iostream>

using namespace std;

class Persona
{
protected:
	string nombre, apellido, direccion, fecha_nacimiento;
	int telefono=0;
	bool genero=0;

protected:
	Persona() {
	};
	Persona(string nom, string ape, string dir, string fn, int tel, bool gen) {
		nombre = nom;
		apellido = ape;
		direccion = dir;
		fecha_nacimiento = fn;
		telefono = tel;
		genero = gen;
	}

};

