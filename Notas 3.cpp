#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Estudiante{
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
    char resultado[10];
};
int main(){
    int n;
    Estudiante *estudiantes;
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;
    estudiantes = new Estudiante[n];
    for(int i=0; i<n; i++){
        cout<<"\nIngrese los datos del estudiante "<<i+1<<":\n";
        cout<<"ID: ";
        cin>>estudiantes[i].id;
        cout<<"Nombres: ";
        cin.ignore();
        cin.getline(estudiantes[i].nombres, 50);
        cout<<"Apellidos: ";
        cin.getline(estudiantes[i].apellidos, 50);
        cout<<"Nota 1: ";
        cin>>estudiantes[i].notas[0];
        cout<<"Nota 2: ";
        cin>>estudiantes[i].notas[1];
        cout<<"Nota 3: ";
        cin>>estudiantes[i].notas[2];
        cout<<"Nota 4: ";
        cin>>estudiantes[i].notas[3];
        estudiantes[i].promedio = (estudiantes[i].notas[0] + estudiantes[i].notas[1] + estudiantes[i].notas[2] + estudiantes[i].notas[3])/4;
        if(estudiantes[i].promedio >= 60){
            strcpy(estudiantes[i].resultado, "APROBADO");
        }
        else{
            strcpy(estudiantes[i].resultado, "REPROBADO");
        }
    }
    ofstream archivo("notas.dat", ios::binary);
    if(archivo){
        archivo.write(reinterpret_cast<char *>(estudiantes), n*sizeof(Estudiante));
        archivo.close();
    }
    else{
        cout<<"Error al abrir el archivo para escritura\n";
    }
    ifstream archivo2("notas.dat", ios::binary);
    if(archivo2){
        Estudiante est;
        cout<<"\nDatos de los estudiantes:\n";
        while(archivo2.read(reinterpret_cast<char *>(&est), sizeof(Estudiante))){
            cout<<"\nID: "<<est.id<<"\n";
            cout<<"Nombres: "<<est.nombres<<"\n";
            cout<<"Apellidos: "<<est.apellidos<<"\n";
            cout<<"Notas: "<<est.notas[0]<<" "<<est.notas[1]<<" "<<est.notas[2]<<" "<<est.notas[3]<<"\n";
            cout<<"Promedio: "<<est.promedio<<"\n";
            cout<<"Resultado: "<<est.resultado<<"\n";
        }
        archivo2.close();
    }
    else{
        cout<<"Error al abrir el archivo para lectura\n";
    }

    delete[] estudiantes;
    return 0;
}
