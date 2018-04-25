#include<string.h>
#include<stdio.h>
typedef struct cuarto Cuarto;
typedef struct tipocama Tipocamas;
typedef struct persona Persona;
typedef void* Dato;
struct persona{
	char nombre[50];
	int edad;
};
struct tipocama{
	int numcamaMatri;
	int numcamaIndiv;
};
struct cuarto{
 	int numCuarto;
 	int numCamas;
 	Tipocamas camas;
 	int capacidad;
	void* huespedes;
};
Dato creaDato(void *a){
	Dato nuevo;
	nuevo= a;
	return nuevo;
}
Dato creaDatoCuarto(int id, int numbeds, Tipocamas beds, int cap, void* huespedes,  Cuarto * nuevo){
	nuevo->numCuarto=id;
	nuevo->numCamas= numbeds;
	nuevo->camas= beds;
	nuevo->capacidad=cap;
	nuevo->huespedes= huespedes;
	return  (Dato)nuevo;
}
Dato creaDatoPersona(char * nom, int age, Persona * nuevo){
	strcpy(nuevo->nombre, nom);
	nuevo->edad= age;
	return (Dato)nuevo;
}
void imprimeInfoTipoCamas(Tipocamas camas,int op, FILE * archivo){
	if(op == 2){
		fprintf(archivo,"\tNumero de  camas Matrimoniales: %d\n", camas.numcamaMatri);
		fprintf(archivo,"\tNumero de  camas Individuales: %d\n", camas.numcamaIndiv);
	}
	printf("\tNumero de  camas Matrimoniales: %d\n", camas.numcamaMatri);
	printf("\tNumero de  camas Individuales: %d\n", camas.numcamaIndiv);
}
void imprimeDatoCuarto(Cuarto  consulta, int op, FILE * archivo){
	if(op == 2){
		fprintf(archivo,"NumCuarto: [%d]\n",consulta.numCuarto);
		fprintf(archivo,"\tNumCamas: %d\n", consulta.numCamas);
		fprintf(archivo,"\tNumero de huespedes en la habitacion: %d\n", consulta.capacidad);
	}
	printf("NumCuarto: [%d]\n",consulta.numCuarto);
	printf("\tNumCamas: %d\n", consulta.numCamas);
	imprimeInfoTipoCamas(consulta.camas,op,archivo);
	printf("\tNumero de huespedes en la habitacion: %d\n", consulta.capacidad);
}
void inicializaTipoCamas(Tipocamas * camas, int numIndividuales, int numMatrimoniales){
	camas->numcamaMatri=numMatrimoniales ;
	camas->numcamaIndiv=numIndividuales;	
}
void imprimeInfoHuesped(Persona cliente,int op, FILE * archivo){
	if(op == 2){
		fprintf(archivo," Nombre: %s  Edad: %d\n", cliente.nombre, cliente.edad);
	}
	printf(" Nombre: %s  Edad: %d\n", cliente.nombre, cliente.edad);
}
