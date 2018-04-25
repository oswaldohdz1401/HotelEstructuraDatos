#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

void bienvenida(){
	printf("\t\t\t[WELLCOME]\n\n");
	printf(" Programa, que realiza el registro de un hotel con listas ligadas\tUACM\n\n");
	printf(" Nombre:\tHernandez Juarez Oswaldo Josue\n");
	printf(" Matricula:\t14-003-1338\n");
	printf(" Asignatura:\tEstructura de Datos\n\n");
	system("pause");
}
void menu(){
	system("cls");
	printf("\n\n\n\t\t1)Registro\n\t\t2)Eliminacion\n\t\t3)Busqueda por nombre del cliente\n\t\t4)Generacion de listado\n");
	printf("\n\n\n\t\tPresiona [0] para salir");
	printf("\n\n\n\t\tElija una opcion: ");
}

void menuRegistro(){
	system("cls");
	printf("\n\n\n\t\tQue tipo de habitacion desea?\n\t\t1)Sencillo\n\t\t2)Doble\n\t\t3)Triple\n\t\t4)Informacion de Registro\n\t\tElija una opcion:\n\t\t");
}
void informacionDeRegistro(){
	system("cls");
	printf("\nHabitacion [Sensilla]\n");
	printf("\t[1] Cama Individual\n");
	printf("\t\t-Capacidad de huespedes [1]\n");
	printf("\nHabitacion [Doble]\n");
	printf("\t[2] Camas invidibiduales\n");
	printf("\t\t-Capacidad de huespedes [2]\n");
	printf("\t[2] Camas matrimoniales\n");
	printf("\t\t-Capacidad de huespedes [4]\n");
	printf("\nHabitacion [Triple]\n");
	printf("\t[1] Cama Individual + [1] Cama Matrimonial\n");
	printf("\t\t-Capacidad de huespedes [3]\n");
	printf("\t[3] Camas Individuales\n");
	printf("\t\t-Capacidad de huespedes [3]\n");
	system("pause");
}
int menuRegistroDoble(){
	int op;
	printf("\t1) [2] Camas invidibiduales\n");
	printf("\t\t-Capacidad de huespedes [2]\n");
	printf("\t2) [2] Camas matrimoniales\n");
	printf("\t\t-Capacidad de huespedes [4]\n");
	printf("\nElige una opcion: ");
	scanf("%d", &op);
	if (op<1 || op>2){
		printf("No se pudo completar la operacion . . .");
		return 0;
	}
	return op;
}
void imprimeInfomacionEliminacion(){
	system("cls");
	printf("Se realiza la iliminacion de la infomacion de un cuarto, ingresando los datos de un huesped del hotel.\n");
}
void imprimeInfomacionBusqueda(){
	system("cls");
	printf("Buscara un cliente hospedado en hotel\nMostrando los datos de todo el cuarto\n");
}
int menuGeneralLista(){
	int op = 0;
	system("cls");
	printf("\tImprimiedo Listas de el hotel\nLa generaciion de listado no solo se imprime en panlla \nsino tambien en un archivo baseHotel.txt\n\n");
	printf("\nElige una opcion: ");
	scanf("%d", &op);
	if (op<1 || op>2){
		printf("No se pudo completar la operacion . . .");
		return 0;
	}
	return op;
}
