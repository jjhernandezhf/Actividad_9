#include <iostream>
using namespace std;

int main()
{
    int opcion;
    cout << "MENU " << endl;
    cout << "1. NOTA PROGRAMA 1 ARREGLOS" << endl;
    cout << "2. NOTA PROGRAMA 2 PUNTEROS Y ESTRUCTURAS" << endl;
    cout << "3.SALIR" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion)
    {
        case 1:
        {
            int n;
            cout << "Ingrese la cantidad de estudiantes: ";
            cin >> n;
            int id[n];
            string nombres[n];
            string apellidos[n];
            float notas[4][n];
            float promedios[n];
            for(int i=0; i<n; i++)
            {
                cout << "Ingrese el id del estudiante " << i+1 << ": ";
                cin >> id[i];
                cin.ignore();
                cout << "Ingrese el nombre del estudiante " << i+1 << ": ";
                getline(cin, nombres[i]);
                cout << "Ingrese el apellido del estudiante " << i+1 << ": ";
                getline(cin, apellidos[i]);
                for(int j=0; j<4; j++)
                {
                    cout << "Ingrese la nota " << j+1 << " del estudiante " << i+1 << ": ";
                    cin >> notas[j][i];
                }
                promedios[i] = (notas[0][i] + notas[1][i] + notas[2][i] + notas[3][i]) / 4;
            }
            cout << "Resultados:" << endl;
            for(int i=0; i<n; i++)
            {
                cout << "Id: " << id[i] << endl;
                cout << "Nombre: " << nombres[i] << endl;
                cout << "Apellido: " << apellidos[i] << endl;
                cout << "Notas: ";
                for(int j=0; j<4; j++)
                {
                    cout << notas[j][i] << " ";
                }
                cout << endl;
                cout << "Promedio: " << promedios[i] << endl;
                if(promedios[i] >= 60)
                {
                    cout << "Estado: Aprobado" << endl;
                }
                else
                {
                    cout << "Estado: Reprobado" << endl;
                }
                cout << endl;
            }
            break;
        }
        
        case 2:
            cout << "NOTA PROGRAMA 2" << endl;
            {
            int n;
            cout << "Ingrese la cantidad de estudiantes: ";
            cin >> n;
            struct Estudiante {
            int id;
           string nombres;
           string apellidos;
            float notas[4];
            float promedio;
            bool aprobado;
     };
     Estudiante* estudiantes = new Estudiante[n];
     for(int i=0; i<n; i++)
     {
        cout << "Ingrese el id del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].id;
        cin.ignore();

        cout << "Ingrese el nombre del estudiante " << i+1 << ": ";
        getline(cin, estudiantes[i].nombres);

        cout << "Ingrese el apellido del estudiante " << i+1 << ": ";
        getline(cin, estudiantes[i].apellidos);

        for(int j=0; j<4; j++)
        {
            cout << "Ingrese la nota " << j+1 << " del estudiante " << i+1 << ": ";
            cin >> estudiantes[i].notas[j];
        }

        estudiantes[i].promedio = (estudiantes[i].notas[0] + estudiantes[i].notas[1] + estudiantes[i].notas[2] + estudiantes[i].notas[3]) / 4;
        estudiantes[i].aprobado = estudiantes[i].promedio >= 60;
     }
     cout << "Resultados:" << endl;
     for(int i=0; i<n; i++)
     {
        cout << "Id: " << estudiantes[i].id << endl;
        cout << "Nombre: " << estudiantes[i].nombres << endl;
        cout << "Apellido: " << estudiantes[i].apellidos << endl;
        cout << "Notas: ";
        for(int j=0; j<4; j++)
        {
            cout << estudiantes[i].notas[j] << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if(estudiantes[i].aprobado)
        {
            cout << "Estado: Aprobado" << endl;
        }
        else
        {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
     }

     delete[] estudiantes;
     break;
	 }  
    case 3:
            cout << "SALIR" << endl;
            cout << "YA NO HAY MAS PROGRAMAS QUE MOSTRAR" << endl;
            break;
        default:
            cout << "El valor ingresado no esta en el menu" << endl;
            break;
    }

    cin.ignore();
    return 0;
}
