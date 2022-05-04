#pragma once
#include "Persona.h"
#include <mysql.h>
#include <iostream>
#include <string.h>
#include <string>
#include "ConexionBD.h"

class Estudiante : Persona
{
private:
	string carnet, email;

public:
	Estudiante() {
	}

	Estudiante(string nom, string ape, string dir, string fn, int tel, bool gen, string carn, string emai) : Persona(nom, ape, dir, fn, tel, gen) {
		carnet = carn;
		email = emai;
	}

	void crear() {
		int q_estado;
		string aux = to_string(telefono);
		string aux2 = to_string(genero);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.get_conectar()) {
			string insert = "INSERT INTO estudiantes (carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES('"+ carnet +"','" + nombre + "','" + apellido + "','" + direccion + "'," + aux + "," + aux2 + ",'" + email + "','" + fecha_nacimiento + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.get_conectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso !!!" << endl;
			}
			else {
				cout << "xxx ERROR AL HACER INSERT xxx" << endl;
			}
		}
		else {
			cout << "xxx !!!!no se pudo conectar!!! xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.get_conectar()) {
			string select = "select *from estudiantes;";
			const char* mostrar = select.c_str();
			q_estado = mysql_query(cn.get_conectar(), mostrar);
			if (!q_estado) {
				cout << " id_Estudiante" << " | " << " CARNET " << " | " << " NOMBRE" << " | " << " APELLIDO " << " | " << " DIRECCION " << " | " << " TELEFONO " << " | " << " GENERO " << " | " << " EMAIL" << " | " << " F_NAC" << " | " << endl;
 				resultado = mysql_store_result(cn.get_conectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 8; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;
				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}
			
		}

		else {
			cout << "xxx error de conexion !!!xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string aux = to_string(telefono);
		string aux2 = to_string(genero);
		string aux3 = to_string(x);
		if (cn.get_conectar()) {
			string update = "UPDATE estudiantes SET carnet ='" + carnet + "',nombres ='" + nombre + "',apellidos ='" + apellido + "',direccion ='" + direccion + "',telefono =" + aux + ",genero =" + aux2 + ",email ='" + email + "',fecha_nacimiento ='" + fecha_nacimiento + "',WHERE id_estudiante = " + aux3 + ";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.get_conectar(), upda);
			if (!q_estado) {
				cout << " datos actualizados !!!" << endl;

			}
			else {
				cout << " sxxx error al hacer update xxxs" << endl;
			}
		}
		else {
			cout << " xxx error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string aux = to_string(x);
		if (cn.get_conectar()) {
			string eliminar = "delete from estudiantes where id_estudiante =" + aux + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.get_conectar(), eli);
			if (!q_estado) {
				cout << " fila borrada " << endl;
			}
			else {
				cout << "xxx  error al hacer delete xxx" << endl;
			}
		}
		else {
			cout << " xxx error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer(int x) {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string aux = to_string(x);
		cn.abrir_conexion();
		if (cn.get_conectar()) {
			string select = "select *from estudiantes where id_estudiante ="+aux+";";
			const char* mostrar = select.c_str();
			q_estado = mysql_query(cn.get_conectar(), mostrar);
			if (!q_estado) {
				cout << " id_Estudiante" << " | " << " CARNET " << " | " << " NOMBRE" << " | " << " APELLIDO " << " | " << " DIRECCION " << " | " << " TELEFONO " << " | " << " GENERO " << " | " << " EMAIL" << " | " << " F_NAC" << " | " << endl;
				resultado = mysql_store_result(cn.get_conectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 8; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;
				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}

		}

		else {
			cout << "xxx error de conexion !!!xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void setNombre(string nom) { nombre=nom; }
	void setApellido(string ape) { apellido = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setFechaN(string fn) { fecha_nacimiento = fn; }
	void setTel(int tel) { telefono = tel; }
	void setGen(bool gen) { genero=gen; }
	void setCarnet(string carn) { carnet = carn; }
	void setEmail(string emai) { email = emai; }
};

