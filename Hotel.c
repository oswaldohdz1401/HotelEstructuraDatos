#include "Listas.h"
#include "imprimeInfomacion.h"
#include "cabeceras.h"
#include "registros.h"
#include <stdio.h>
#include <string.h>
main(){
	bienvenida ();
	Lista Hotel;
	inicializa(&Hotel);
	selecionOperacion(&Hotel);
}
void selecionOperacion(Lista *A){
	int op;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1: registro(A);
					break;
			case 2: elimina(A);
					break;
			case 3: busqueda(*A);
					break;
			case 4: generalistado(*A);
					break;
			case 5: exit(0);
			default: system("cls");printf("\n\tAdios ;)\n");
		}
	}while(op>=1 && op<=5);
}
void registro(Lista *A){
	int optipohabitacion;
	idCuarto++;
	menuRegistro();
	scanf("%d", &optipohabitacion);
	switch(optipohabitacion){
		case 1: registroSencilla(A);
				break;
		case 2: registroDoble(A);
				break;
		case 3: registroTriple(A);
				break;
		case 4: informacionDeRegistro();
		default: printf("opcion de habitacion invalida\n");	
	}	
}
void elimina(Lista *A){
	if(esVacia(*A) == 0){
		Nodo *eliminado;
		Cuarto cEliminado;
		int numCuarto=0;
		Dato aBuscar;
		imprimeInfomacionEliminacion();
		Persona *cliente  =(Persona *)malloc(sizeof(Persona));
		setInfocliente(cliente);
		aBuscar = (Dato)(cliente);
		Nodo *aux;
		Dato dCuarto;
		Cuarto cAnalizar;
		Lista lHuepedes;
		aux = A->inicio;
		while(aux != NULL){
			dCuarto = aux->contenido;
			cAnalizar = (*(Cuarto*)(dCuarto));
			lHuepedes = (*(Lista*)(cAnalizar.huespedes));
			if(busquedaDeLista(lHuepedes,aBuscar,0) >= 0){
				printf("\n\nEl cuarto eliminado fue: \n");
				printf("\n+++++++++++++++++++++++++++++++++++++\n");
				eliminado = eliminaPoPos(A,numCuarto);
				imprimeCuartos(eliminado->contenido,1,NULL);
				printf("\n+++++++++++++++++++++++++++++++++++++\n");
			}
			aux = aux->sig;
			numCuarto++;
		}
		system("pause");
	}else{printf("\nLista vacia\n");system("pause");}
}
void busqueda(Lista A){
	if(esVacia(A) == 0){
		int numCuarto=0;
		Dato aBuscar;
		imprimeInfomacionBusqueda();
			Persona *cliente  =(Persona *)malloc(sizeof(Persona));
			setInfocliente(cliente);
			aBuscar = (Dato)(cliente);
		Nodo *aux;
		Dato dCuarto;
		Cuarto cAnalizar;
		Lista lHuepedes;
		aux = A.inicio;
		while(aux != NULL){
			dCuarto = aux->contenido;
			cAnalizar = (*(Cuarto*)(dCuarto));
			lHuepedes = (*(Lista*)(cAnalizar.huespedes));
			if(busquedaDeLista(lHuepedes,aBuscar,0) >= 0){
				printf("\n\nEl cuarto buscado es: \n");
				printf("\n+++++++++++++++++++++++++++++++++++++\n");
				imprimeCuartos(dCuarto,1,NULL);
				printf("\n+++++++++++++++++++++++++++++++++++++\n");
			}
			aux = aux->sig;
			numCuarto++;
		}
		system("pause");
	}else{printf("\nLista vacia\n");system("pause");}
}
void generalistado(Lista A){
	int op = 0;
	op = menuGeneralLista();
	imprimeListaHotel(A,op);
}
void imprimeCuartos(Dato consultando, int op, FILE* archivo){
	Lista *huespedes;
	Cuarto a_imprimir=(*(Cuarto *)(consultando));
	imprimeDatoCuarto(a_imprimir,op,archivo);
	huespedes=    ((Lista*)a_imprimir.huespedes);
	imprimeListaHuespedes(*huespedes,op,archivo);
	
}
void imprimeListaHotel(Lista A, int op){
	Dato  aimprimir;
	Nodo * aux;
	//-------------
	FILE *archivo;
	char  *file="baseHotel";
	//-------------
	if(op==2){
		archivo = fopen(file,"w+");
	}
	if(esVacia(A)==0){
		aux= A.inicio;
		while(aux!=NULL){
			printf("\n+++++++++++++++++++++++++++++++++++++\n");
			if(op == 2){
				fprintf(archivo,"+++++++++++++++++++++++++++++++++++++\n"); 
			}
			aimprimir=(aux->contenido);
			imprimeCuartos(aimprimir,op,archivo);
			aux= aux->sig;
		}
	}else{
		 printf("Lista vacia\n");
	}
	system("pause");
}
/*---------------------------------------------------------------------*/
int busquedaDeLista(Lista A, Dato buscado){
    int pos=0; 
    Persona * pBuscada = (Persona*)buscado;
    Nodo *aux= A.inicio;
    while(aux!=NULL){
    	Persona * enLista = (Persona*)aux->contenido;
    	if(!strcmp(pBuscada->nombre,enLista->nombre)&&(pBuscada->edad == enLista->edad)){
			return pos;
		}
		aux= aux->sig;
        pos++;
    }
    if(aux==NULL){
		return -1;
    }
}
