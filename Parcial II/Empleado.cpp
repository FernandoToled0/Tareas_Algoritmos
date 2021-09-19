#include<iostream>
#include <windows.h>
using namespace std;
//variables globales
int opc=0,totalEmpleados = 0;
//------Menu----------//
void menu();
//--------------------//
//------Controles-------//
void Cls();
void Gotoxy(int x,int y);
void TextColor(int color);
//-----------------------//
//--------------------metodos-------------------------//
void insert_employe();
int update_employe(int codigoEmpleado);
void select_employe();
int search_employe(int codigoEmpleado);
int dato_employe(int i);
int funcion_calcular_sueldo(float num1, float num2);
//----------------------------------------------------//
//Estructura
struct Empleado{
		
	int *codigo;	
	string *nombre;
	string *apellido;	
	string *Puesto;
	float *Sueldo_Base;
	float *Bonificacion;
	
};

Empleado empleado;

int main(){
	system("mode con: cols=110 lines=35");	
	
	empleado.codigo = new int [totalEmpleados];
	empleado.nombre = new string [150];
	empleado.apellido = new string [150];
	empleado.Puesto = new string [150];
	empleado.Sueldo_Base = new float [totalEmpleados];
	empleado.Bonificacion = new float [totalEmpleados];
			
	menu();
	
	system("PAUSE");
	return 0;
}
void menu(){
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(36,6);cout<<"INGRESO Y EDICION DE EMPLEADOS";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(42,21);cout<<"Design: Luis Toledo";
	Gotoxy(31,22);cout<<"----------------------------------------";
	
	Gotoxy(40,12);cout<<"1. Insertar empleado"<<endl;
	Gotoxy(40,13);cout<<"2. Editar empleado"<<endl;
	Gotoxy(40,14);cout<<"3. Buscar empleado"<<endl;
	Gotoxy(40,15);cout<<"4. Ver todos los empleados"<<endl;
	Gotoxy(40,16);cout<<"5. Salir"<<endl<<endl;
	Gotoxy(40,11);cout<<"Digite su opcion: ";
	Gotoxy(58,11);cin>>opc; 
			
	Cls();
	
	switch(opc)
	{
		case 1: insert_employe() 		;break;
 		case 2: update_employe(0) 		;break;
 		case 3: search_employe(0) 		;break;
 		case 4: select_employe() 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
 
system("pause");
Cls();
menu();

}
void insert_employe(){
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(36,6);cout<<"INGRESE LOS DATOS DEL EMPLEADOS";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
 	
 	//--Area de nombres de datos
 	TextColor(8);
 	Gotoxy(30,10);cout<<"Codigo del empleado: _____________________";
	Gotoxy(30,11);cout<<"Nombres del empleado: ____________________";
	Gotoxy(30,12);cout<<"Apellidos del empleado: __________________";
	Gotoxy(30,13);cout<<"Puesto: __________________________________";
	Gotoxy(30,14);cout<<"Sueldo base: _____________________________";
	Gotoxy(30,15);cout<<"Bonificacion: ____________________________";
	//--Fin de impresion de encabezados
	
	TextColor(7);
	Gotoxy(51,10);cin>>empleado.codigo[totalEmpleados];
		
	if(empleado.codigo[totalEmpleados]==0){
	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(37,21);cout<<"El codigo no puede ser 0";
	Gotoxy(31,22);cout<<"----------------------------------------";
	Gotoxy(30,18);system("pause");
	Cls();
	insert_employe();
	}
	
	cin.ignore();
	
	Gotoxy(52,11);getline(cin,empleado.nombre[totalEmpleados]);
	Gotoxy(54,12);getline(cin,empleado.apellido[totalEmpleados]);	
	Gotoxy(38,13);getline(cin,empleado.Puesto[totalEmpleados]);
	Gotoxy(43,14);cin>>empleado.Sueldo_Base[totalEmpleados];	
	Gotoxy(44,15);cin>>empleado.Bonificacion[totalEmpleados];		
			
	totalEmpleados++;

	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(37,21);cout<<"Empleado agregado con exito";
	Gotoxy(31,22);cout<<"----------------------------------------";
	Gotoxy(30,18);system("pause");
	
	Cls();
	menu();	

}
int update_employe(int codigoEmpleado){
	int id_registro, opc=0;
	string nombre, apellidos, puesto;
	float sueldo, bonificacion;
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(40,6);cout<<"Codigo del empleado: ";
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	if(codigoEmpleado==0){		
	Gotoxy(61,6);cin>>codigoEmpleado;
	}	
	
	for (int i = 0; i < totalEmpleados; i++)
		{
			if(empleado.codigo[i]==codigoEmpleado){	
			TextColor(8);
			Gotoxy(30,10);cout<<"Codigo del empleado: _____________________"; 
			Gotoxy(30,11);cout<<"Nombres del empleado: ____________________"; 
			Gotoxy(30,12);cout<<"Apellidos del empleado: __________________"; 
			Gotoxy(30,13);cout<<"Puesto: __________________________________"; 
			Gotoxy(30,14);cout<<"Sueldo base: _____________________________"; 
			Gotoxy(30,15);cout<<"Bonificacion: ____________________________"; 
			Gotoxy(30,16);cout<<"Sueldo total: ____________________________"; 
			
			TextColor(7);
			Gotoxy(51,10);cout<<empleado.codigo[i];
			Gotoxy(52,11);cout<<empleado.nombre[i];
			Gotoxy(54,12);cout<<empleado.apellido[i];
			Gotoxy(38,13);cout<<empleado.Puesto[i];	
			Gotoxy(43,14);cout<<empleado.Sueldo_Base[i];
			Gotoxy(44,15);cout<<empleado.Bonificacion[i];
			Gotoxy(44,16);cout<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i]);
			
			id_registro=i;
		}			
	}	
	
	Gotoxy(5,25);cout<<"1. Editar Nombres";
	Gotoxy(35,25);cout<<"2. Editar Apellidos";
	Gotoxy(75,25);cout<<"3. Editar Puesto";
	Gotoxy(5,26);cout<<"4. Editar Sueldo";
	Gotoxy(35,26);cout<<"5. Editar Bonificacion";
	Gotoxy(75,26);cout<<"6. Seleccionar otro registro";
	Gotoxy(35,27);cout<<"7. Regresar";
	
	Gotoxy(35,23);cout<<"Digite su opcion: ";
	Gotoxy(53,23);cin>>opc; 
		
	switch(opc)
	{
	case 1: 
	
	 	Gotoxy(30,11);cout<<"Nombres del empleado: ____________________"; 
		Gotoxy(52,11);cin>>nombre;
		empleado.nombre[id_registro]=nombre;
		Cls();	
		update_employe(codigoEmpleado);
		
	break;
 	case 2:
 		
 		Gotoxy(30,12);cout<<"Apellidos del empleado: __________________"; 	 	
		Gotoxy(54,12);cin>>apellidos;
		empleado.apellido[id_registro]=apellidos;
		Cls();	
		update_employe(codigoEmpleado);
				  
	break;
 	case 3:
 			 
		Gotoxy(30,13);cout<<"Puesto: __________________________________";	  	
		Gotoxy(38,13);cin>>puesto;
		empleado.Puesto[id_registro]=puesto;
		Cls();	
		update_employe(codigoEmpleado);
		
	break;
 	case 4: 
	 	
	 	Gotoxy(30,14);cout<<"Sueldo base: _____________________________";
		Gotoxy(43,14);cin>>sueldo;
		empleado.Sueldo_Base[id_registro]=sueldo;
		Cls();	
		update_employe(codigoEmpleado);
		
	break;
 	case 5:
	 	
	 	Gotoxy(30,15);cout<<"Bonificacion: ____________________________";
		Gotoxy(44,15);cin>>bonificacion;
		empleado.Bonificacion[id_registro]=bonificacion;
		Cls();	
		update_employe(codigoEmpleado);
		
	break;
	case 6:
		
		update_employe(0);
		
	break;
	case 7:
		
		Cls();
		menu();	
		
	break;
	default:cout<<"Opcion no valida";  
	}													
}
void select_employe(){
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(40,6);cout<<"Empleados encontrados:"<<totalEmpleados;
	Gotoxy(31,7);cout<<"----------------------------------------";
	
	if (totalEmpleados==0){	
		
	Gotoxy(31,20);cout<<"----------------------------------------";
	Gotoxy(40,21);cout<<"No hay datos de empleados";
	Gotoxy(31,22);cout<<"----------------------------------------";
	
	}else{
		for (int i = 0; i < totalEmpleados; i++)		
		{	
		dato_employe(i);		
		}
	}
	
	Gotoxy(30,34);
		
}
int search_employe(int codigoEmpleado){
	
	Gotoxy(31,5);cout<<"----------------------------------------";
	Gotoxy(40,6);cout<<"Codigo del empleado: ";
	Gotoxy(31,7);cout<<"----------------------------------------";
	if(codigoEmpleado==0){		
	Gotoxy(61,6);cin>>codigoEmpleado;
	}
		
	for (int i = 0; i < totalEmpleados; i++)
	{
		if(empleado.codigo[i]==codigoEmpleado)
		{			
		dato_employe(i);
		}			
	}
	Gotoxy(30,34);	
}
int dato_employe(int i){
		Gotoxy(1,9);cout<<"|Codigo";
		Gotoxy(9,9);cout<<"|Nombres";
		Gotoxy(26,9);cout<<"|Apellidos";					
		Gotoxy(47,9);cout<<"|Puesto";		
		Gotoxy(67,9);cout<<"|Sueldo base";	
		Gotoxy(81,9);cout<<"|Bonificacion";	
		Gotoxy(96,9);cout<<"|Sueldo Total";
		
		Gotoxy(4,10+i);cout<<empleado.codigo[i]<<endl;	
		Gotoxy(10,10+i);cout<<empleado.nombre[i]<<endl;	
		Gotoxy(27,10+i);cout<<empleado.apellido[i]<<endl;
		Gotoxy(48,10+i);cout<<empleado.Puesto[i]<<endl;
		Gotoxy(70,10+i);cout<<"Q."<<empleado.Sueldo_Base[i]<<endl;
		Gotoxy(86,10+i);cout<<"Q."<<empleado.Bonificacion[i]<<endl;	
		Gotoxy(99,10+i);cout<<"Q."<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;
}
int funcion_calcular_sueldo(float num1, float num2){
	float suma=0;	
	suma = num1+num2;
	return suma;
}
void Cls(){
	system("cls");
	
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

