
#include<string.h>
#include <iostream>
#include<mysql.h>
#include"ConexionBD.h"
#include"Estudiante.h"


int x = 0;
using namespace std;
int main()
{   

    int op;
    bool ciclo = true;
    string nombre="", apellido="", fecha_nacimiento="", carnet="", direccion="", email="";
    bool genero=0;
    int telefono=0;

    do{
        Estudiante obj = Estudiante(nombre, apellido, direccion, fecha_nacimiento, telefono, genero, carnet, email);
        cout << "ingrese una opcion" << endl;
        cout << "1 crear" << endl;
        cout << "2 leer" << endl;
        cout << "3 actualizar" << endl;
        cout << "4 eliminar" << endl;
        cout << "5 salir" << endl;
        cout << "ELIJA !" << endl;
        cin >> op;
        switch (op) {

            {
        case 1:
            cout << "ingrese carnet" << endl;
            cin >> carnet;
            cin.ignore();
            cout << "ingrese nombre" << endl;
            getline(cin, nombre);
           
            cout << " apellido" << endl;
            getline(cin, apellido);
         
            cout << "ingrese direccion" << endl;
            getline(cin, direccion);
            cout << "ingrese telefono" << endl;
            cin >> telefono;
            cout << "ingrese genero (1/0)" << endl;
            cin >> genero;
            cout << "fecha nacimiento" << endl;
            cin >> fecha_nacimiento;
            cout << "ingrese email" << endl;
            cin >> email;
            obj.setNombre(nombre);
            obj.setApellido(apellido);
            obj.setCarnet(carnet);
            obj.setDireccion(direccion);
            obj.setEmail(email);
            obj.setFechaN(fecha_nacimiento);
            obj.setGen(genero);
            obj.setTel(telefono);
            obj.crear();
            

            break;
            }

            {
            case 2:

                system("cls");
                obj.leer();
                break;
            
                

            }

            {
            case 3:
                cout << "actualizar" << endl;

                break;

            }

            {
            case 4:
                cout << "eliminar" << endl;
                int op3 = 0;
                cout << "ingrese registro a eliminar" << endl;
                cin >> x;
                obj.leer(x);

                cout << "desea eliminar? (1/0)" << endl;
                cin >> op3;

                if (op3 == 1)
                    obj.eliminar(x);
                else {
                    cout << "no se elimino" << endl;
                }
                break;
            }

            {
            case 5:
                ciclo = false;
                break;
            }
            
        }
    } while (ciclo!=0);
  
    
    cout << "Hello World!\n";
    system("pause");

}

