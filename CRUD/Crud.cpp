#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_aux.dat";
int opc = 0;

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
//manejo de interfaz//
void Gotoxy(int x,int y);
void TextColor(int color);
//fin de manejo de interfaz//

void menu();
void crear();
void leer();
void actualizar();
void borrar();

main(){
system("mode con: cols=110 lines=35");	
menu();
}

void menu(){
	
	system("cls");
	
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(42,6);cout<<"CRUD DE ESTUDIANTES";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(42,21);cout<<"Design: Luis Toledo";
	Gotoxy(31,22);cout<<"----------------------------------------";
	
	Gotoxy(40,12);cout<<"1. Insertar estudiante"<<endl;
	Gotoxy(40,13);cout<<"2. Ver estudiantes"<<endl;
	Gotoxy(40,14);cout<<"3. Actualizar estudiante"<<endl;
	Gotoxy(40,15);cout<<"4. Eliminar estudiante"<<endl;
	Gotoxy(40,16);cout<<"5. Salir"<<endl<<endl;
	Gotoxy(40,11);cout<<"Digite su opcion: ";
	Gotoxy(58,11);cin>>opc; 
				
	system("cls");
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: borrar();	 			;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
		
}
void leer(){
	
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		
		Gotoxy(31,1);cout<<"----------------------------------------";
		Gotoxy(40,2);cout<<"Listado de estudiantes";
		Gotoxy(31,3);cout<<"----------------------------------------";
	
		Gotoxy(5,5);cout<<"Id";
		Gotoxy(15,5);cout<<"Codigo";
		Gotoxy(30,5);cout<<"Nombres";					
		Gotoxy(60,5);cout<<"Apellidos";		
		Gotoxy(90,5);cout<<"Telefono";	
				
		
		do{
		
		Gotoxy(5,6 + id);cout<<id;
		Gotoxy(15,6 + id);cout<<estudiante.codigo;
		Gotoxy(30,6 + id);cout<<estudiante.nombres;					
		Gotoxy(60,6 + id);cout<<estudiante.apellidos;		
		Gotoxy(90,6 + id);cout<<estudiante.telefono;	
					
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		
		id+=1;
			
		}while(feof(archivo)==0);
		
		fclose(archivo);	
		Gotoxy(30,34);system("pause");
		
		menu();
}
void actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;

	Gotoxy(31,1);cout<<"----------------------------------------";
	Gotoxy(33,2);cout<<"Ingrese el ID que desea Modificar: ";
	Gotoxy(31,3);cout<<"----------------------------------------";
	Gotoxy(67,2);cin>>id;
	
	
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
	Gotoxy(30,10);cout<<"Ingrese el Codigo: _______________________";
	Gotoxy(30,11);cout<<"Ingrese los Nombres: _____________________";
	Gotoxy(30,12);cout<<"Ingrese los Apellidos: ___________________";
	Gotoxy(30,13);cout<<"Ingrese el Telefono: _____________________";
	
	Gotoxy(49,10);cin>>estudiante.codigo;
	cin.ignore();
	Gotoxy(51,11);getline(cin,nombre);		
	Gotoxy(53,12);getline(cin,apellido);		
	Gotoxy(51,13);cin>>estudiante.telefono;
		
	strcpy(estudiante.nombres,nombre.c_str());
	strcpy(estudiante.apellidos,apellido.c_str());
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	Gotoxy(30,15);cout<<"Dese Agregar otro Estudiante (s/n):";
	//	Gotoxy(65,15);cin>>continuar;
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(36,6);cout<<"INGRESE LOS DATOS DEL EMPLEADOS";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
 	
 	//--Area de nombres de datos
 	


	//--Fin de impresion de encabezados
	
	do{
		
		fflush(stdin);
		
		TextColor(8);
	 	Gotoxy(30,10);cout<<"Ingrese el Codigo: _______________________";
		Gotoxy(30,11);cout<<"Ingrese los Nombres: _____________________";
		Gotoxy(30,12);cout<<"Ingrese los Apellidos: ___________________";
		Gotoxy(30,13);cout<<"Ingrese el Telefono: _____________________";
	
		TextColor(7);
		Gotoxy(49,10);cin>>estudiante.codigo;
		
		cin.ignore();
		
		Gotoxy(51,11);getline(cin,nombre);		
		Gotoxy(53,12);getline(cin,apellido);		
		Gotoxy(51,13);cin>>estudiante.telefono;
		
		strcpy(estudiante.nombres,nombre.c_str());
		strcpy(estudiante.apellidos,apellido.c_str());
	
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
		Gotoxy(30,15);cout<<"Dese Agregar otro Estudiante (s/n):     ";
		Gotoxy(65,15);cin>>continuar;
		
	
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void borrar(){
 	
FILE *archivo, *archivo_temp; //declaramos las variables donde tendremos el archivo principal y el archivo auxiliar para sobreescribir
int codigo; //declaramos un int para poder almacenar el codigo del estudiante
Estudiante estudiante; //declaramos la estructura de los estudiantes

archivo_temp=fopen(nombre_archivo_temp,"w+b"); //abrimos un archivo temporal para posteriormente escribir en el
archivo=fopen(nombre_archivo,"rb"); //abrimos el archivo principal para tener la informacion de el
                      	
	Gotoxy(31,12);cout<<"----------------------------------------";
	Gotoxy(33,13);cout<<"codigo del estudiante a eliminar: ";
	Gotoxy(31,14);cout<<"----------------------------------------";
	Gotoxy(67,13);cin>>codigo; //ingresamos el codigo del estudiante			                


                                                                                
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	//leemos el archivo para saber su contenido
		if (estudiante.codigo != codigo) //hacemos el if dentro del while para leer los registros del archivo menos el codigo escrito
		fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); //escribimos en el archivo auxiliar todo menos el codigo que se escribio
		}
                
	fclose(archivo_temp); //cerramos el archivo temporal
	fclose(archivo); //cerramos el archivo principal
                
	archivo_temp=fopen(nombre_archivo_temp,"rb"); //abrimos el archivo auxiliar
	archivo=fopen(nombre_archivo,"wb"); //abrimos el archivo principal
 
	while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ //recorremos el archivo temporal con su informacion
		fwrite(&estudiante,sizeof(Estudiante),1, archivo); //escribimos en el archivo principal todo el contenido del archivo temporal
	}
                
fclose(archivo_temp); //cerramos el archivo temporal
fclose(archivo); //cerramos el archivo principal

leer(); // mostramos los registros del archivo

}
void Gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
void TextColor(int color){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}          
            



