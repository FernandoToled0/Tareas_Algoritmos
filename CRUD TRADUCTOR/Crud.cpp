#include <iostream>
#include <string.h>
#include <windows.h>


using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_aux.dat";
int opc = 0;

struct palabra{
	char palabra[250];
	char significado[250];	
	char funcionabilidad[250];	
};
//manejo de interfaz//
void Gotoxy(int x,int y);
void TextColor(int color);
void AltEnter();
//fin de manejo de interfaz//

void menu();
void traducir();
void crear();
void leer();
void actualizar();
void borrar();

main(){
AltEnter();	
//system("mode con: cols=150");	
menu();
}

void menu(){
	
	system("cls");
	
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(42,6);cout<<"TRADUCTOR DE PALABRAS";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(42,21);cout<<"Design: Luis Toledo";
	Gotoxy(31,22);cout<<"----------------------------------------";
	
	Gotoxy(40,11);cout<<"1. Traducir programacion en C++"<<endl;
	Gotoxy(40,12);cout<<"2. Insertar palabra"<<endl;
	Gotoxy(40,13);cout<<"3. Ver palabras"<<endl;
	Gotoxy(40,14);cout<<"4. Actualizar palabra"<<endl;
	Gotoxy(40,15);cout<<"5. Eliminar palabra"<<endl;
	Gotoxy(40,16);cout<<"6. Salir"<<endl<<endl;
	Gotoxy(40,9);cout<<"Digite su opcion: ";
	Gotoxy(58,9);cin>>opc; 
				
	system("cls");
	
	switch(opc)
	{
		case 1: traducir();				;break;
		case 2: crear();		 		;break;
 		case 3: leer();					;break;
 		case 4: actualizar();	 		;break;
 		case 5: borrar();	 			;break;
 		case 6: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
		
}
void traducir(){
	
	FILE* archivo = fopen(nombre_archivo,"rb");
		
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		
	palabra Palabra;
		
	const int MAX = 2500;
	char traduccion[MAX];
	
	string palabraTraducida;	
	cout<<""<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Ingresa el texto a traducir finalizando con $"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	
	//cin.get(traduccion,MAX,'$'); //ingresamos lineas multiples hasta que encuentre el caracter en especial
	
	cin>>palabraTraducida;
	
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Traduccion del texto ingresado"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	
	//ingresar arreglo para poder validar palabra por palabra para luego escribirla (pendiente)
	
	while(fread(&Palabra,sizeof(palabra),1,archivo)){		
		std::string str= Palabra.palabra;
		int longitud = str.length();
		if (str.substr (0,longitud) == palabraTraducida) {
			cout<<Palabra.significado;				
		}
	}	
		
	Gotoxy(30,0);system("pause");		
	menu();
		
}

void leer(){
	
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		
		palabra Palabra;
		
		int id=0;	
	
		
		Gotoxy(31,1);cout<<"----------------------------------------";
		Gotoxy(40,2);cout<<"Listado de palabras";
		Gotoxy(31,3);cout<<"----------------------------------------";
	
		
		
						
				do{	
																												 	
					Gotoxy(5,5);cout<<"Id";
					Gotoxy(15,5);cout<<"Palabra";
					Gotoxy(40,5);cout<<"Significado";	
					Gotoxy(70,5);cout<<"Funcionabilidad";	
				
					Gotoxy(5,6 + id - 1);cout<<id;
					Gotoxy(15,6 + id - 1);cout<<Palabra.palabra;
					Gotoxy(40,6 + id - 1);cout<<Palabra.significado;		
					Gotoxy(70,6 + id - 1);cout<<Palabra.funcionabilidad;
								
					fread(&Palabra,sizeof(palabra),1,archivo);
					
					id+=1;
				
							
				}while(feof(archivo)==0);
				
		fclose(archivo);	
		Gotoxy(30,0);system("pause");
		
		menu();

}
void actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	palabra Palabra;
	string palabras,significados, funcionabilidades;

	Gotoxy(31,1);cout<<"----------------------------------------";
	Gotoxy(33,2);cout<<"Ingrese el ID que desea Modificar: ";
	Gotoxy(31,3);cout<<"----------------------------------------";
	Gotoxy(67,2);cin>>id;
		
	fseek(archivo,(id - 1) * sizeof(palabra),SEEK_SET);
	
	Gotoxy(30,10);cout<<"Ingrese la palabra: ";
	Gotoxy(30,11);cout<<"Ingrese el significado: ";	
	Gotoxy(30,12);cout<<"Ingrese la funcionabilidad: ";	
	Gotoxy(49,10);cin>>palabras;
	cin.ignore();
	Gotoxy(53,11);getline(cin,significados);
	Gotoxy(57,12);getline(cin,funcionabilidades);
			
	strcpy(Palabra.palabra,palabras.c_str());
	strcpy(Palabra.significado,significados.c_str());	
	strcpy(Palabra.funcionabilidad,funcionabilidades.c_str());	
	
	fwrite(&Palabra,sizeof(palabra),1,archivo);
	
	fclose(archivo);
	leer();

}
void crear(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	palabra Palabra;
	string significados, palabras, funcionabilidades;
	
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(36,6);cout<<"INGRESE LA PALABRA Y SU SIGNIFICADO";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	do{
		
		fflush(stdin);
		
		TextColor(8);
		
	 	Gotoxy(30,11);cout<<"Ingrese la palabra                                                                                                                 ";
		Gotoxy(30,12);cout<<"Ingrese el significado:                                                                                                                 ";
		Gotoxy(30,13);cout<<"Ingrese la funcionabilidad:                                                                                                             ";
		
		TextColor(7);

		Gotoxy(49,11);getline(cin,palabras);					
		Gotoxy(53,12);getline(cin,significados);	
		Gotoxy(57,13);getline(cin,funcionabilidades);			
		
		strcpy(Palabra.palabra,palabras.c_str());
		strcpy(Palabra.significado,significados.c_str());
		strcpy(Palabra.funcionabilidad,funcionabilidades.c_str());
	
		fwrite(&Palabra,sizeof(palabra),1,archivo);
			
		Gotoxy(30,15);cout<<"Dese Agregar otra palabra (s/n):     ";
		Gotoxy(65,15);cin>>continuar;
		
	
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void borrar(){
 	
FILE *archivo, *archivo_temp; //declaramos las variables donde tendremos el archivo principal y el archivo auxiliar para sobreescribir
string palabras; //declaramos un int para poder almacenar el codigo del estudiante
palabra Palabra; //declaramos la estructura de los estudiantes

archivo_temp=fopen(nombre_archivo_temp,"w+b"); //abrimos un archivo temporal para posteriormente escribir en el
archivo=fopen(nombre_archivo,"rb"); //abrimos el archivo principal para tener la informacion de el
                      	
	Gotoxy(31,12);cout<<"----------------------------------------";
	Gotoxy(33,13);cout<<"Ingrese la palabra a eliminar: ";
	Gotoxy(31,14);cout<<"----------------------------------------";
	Gotoxy(67,13);cin>>palabras; //ingresamos el codigo del estudiante			                


                                                                                
	while(fread(&Palabra,sizeof(palabra),1,archivo)){	//leemos el archivo para saber su contenido
		if (Palabra.palabra != palabras) //hacemos el if dentro del while para leer los registros del archivo menos el codigo escrito
		fwrite(&Palabra,sizeof(palabra),1,archivo_temp); //escribimos en el archivo auxiliar todo menos el codigo que se escribio
		}
                
	fclose(archivo_temp); //cerramos el archivo temporal
	fclose(archivo); //cerramos el archivo principal
                
	archivo_temp=fopen(nombre_archivo_temp,"rb"); //abrimos el archivo auxiliar
	archivo=fopen(nombre_archivo,"wb"); //abrimos el archivo principal
 
	while(fread(&Palabra,sizeof(palabra),1, archivo_temp)){ //recorremos el archivo temporal con su informacion
		fwrite(&Palabra,sizeof(palabra),1, archivo); //escribimos en el archivo principal todo el contenido del archivo temporal
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
void AltEnter(){
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}             



