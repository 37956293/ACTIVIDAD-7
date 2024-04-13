#include <iostream>
using namespace std;

const char *nombre_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellidos[50];
	int telefono;
};

void leer();
void crear();

int main(){
	leer();
	//crear();
	cin.get(); // Pausa la ejecución hasta que se presione Enter
	return 0; // Indica que la función main ha terminado correctamente
}

void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________"<<endl;
	cout<<"id"<<"|"<<"codigo"<<"|"<<"Nombre"<<"|"<<"apellidos"<<"|"<<"telefono"<<endl;
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(!feof(archivo));
	fclose(archivo);
}

void crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese código: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombre,50);
		
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
			
		cout<<"Ingrese teléfono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout <<"¿Desea ingresar otro estudiante? (S/N): ";
		cin >>res;
	}while(res=='S' || res=='s');
	
	fclose(archivo);
}

