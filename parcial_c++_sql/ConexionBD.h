#pragma once
#include <iostream>
#include <mysql.h>
#include <string.h>

class ConexionBD
{
private:
	MYSQL* conectar;

public:
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empres@123", "colegio", 3306, NULL, 0);
	}

	MYSQL* get_conectar() {
		return conectar;
	}

	void cerrar_conexion() {
		mysql_close(conectar);
	}
};

