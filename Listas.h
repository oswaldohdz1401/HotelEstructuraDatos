#include  "dato.h"
#include <stdlib.h>
#include <string.h>
typedef struct Nodo Nodo;
typedef struct Lista Lista;
struct Nodo{
	Dato contenido;
	Nodo * sig;
};
struct Lista{
	int tam;
	Nodo * inicio;
	Nodo * fin;
}; 


void inicializa(Lista * A){
	A->tam=0;
	A->inicio=NULL;
	A->fin= NULL;
}


int tamLista(Lista A){
	return A.tam;
}
/*
	Si la lista no tiene ningun nodo regresa 1
	Si la lista SI tiene ALGUN nodo regresa 0
*/
int esVacia(Lista A){
	if(A.inicio==NULL && A.fin==NULL && A.tam==0){
		return 1;
	}
	return 0;
}
Nodo* creaNodo(Dato nuevo){
	  Nodo * aux;
	  aux = (Nodo*) malloc(1*sizeof(Nodo));
	  aux->contenido = nuevo;
	  aux->sig=NULL;
	  return aux;
}




void insertaInicio(Lista* A, Dato nuevo){
	Nodo *porinsertar =creaNodo(nuevo);
		if (esVacia(*A)==1){
		 A->fin= porinsertar;
		 A->inicio=porinsertar;

	}else{
	     porinsertar->sig=A->inicio;
	     A->inicio=porinsertar;

	}
	A->tam++;


}



void insertaFinal(Lista *l, Dato elemento){
   Nodo* nuevo;
   nuevo=creaNodo(elemento);
   if(esVacia(*l)==1){
	l->inicio=nuevo;
   }
   l->fin->sig=nuevo;
   l->fin=nuevo;
   l->tam++; 
}

void imprimeListaHuespedes(Lista A, int op, FILE * archivo){
	printf("Imprimiendo lista del cuarto: \n");
	Persona cliente;
	Nodo * aux;
	if(esVacia(A)==0){
		aux= A.inicio;
		while(aux!=NULL){
			cliente=*((Persona *)(aux->contenido));
			imprimeInfoHuesped(cliente,op,archivo);
			aux= aux->sig;
		}
	}else{
		 printf("Lista vacia");
	}
}
//-----------------------------------------------------------------

Nodo *eliminaFinal(Lista *A){
     int pos;
     Nodo *aux=A->inicio;
     for(pos=0;pos<tamLista(*A)-2;pos++){
        aux=aux->sig;
     }
     A->fin=aux;
     aux=aux->sig;
     A->fin->sig=NULL; //Verificar porque no deja acceder al miembro con el punto
     A->tam--;
     return aux;
}

Nodo *eliminaInicio(Lista *A){
     Nodo *aux=A->inicio;
     if(esVacia(*A)!=1 && A->inicio==A->fin){
        A->inicio=NULL;
        A->fin=NULL;
        }else{
        A->inicio=aux->sig;
        }
     A->tam--;
     return aux;
}

Nodo *eliminaPoPos(Lista *A,int k){
     Nodo *aux=NULL;
     Nodo *aux1=NULL;
     int i=0;
     if(esVacia(*A)==0 && k==0){
     aux=eliminaInicio(A);
     }else{
           if(k==tamLista(*A)-1){
           aux=eliminaFinal(A);
           }else{
                 if(k>0 && k<tamLista(*A)-1){
                 aux1=A->inicio;
                   for(i=0;i<k-1;i++){
                   aux1=aux1->sig;
                   }
                 aux=aux1->sig;
                 aux1->sig=aux->sig;
                 aux->sig=NULL;
                 }
           A->tam--;
     }
     }
     return aux;
}
