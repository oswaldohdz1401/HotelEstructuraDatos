#include<stdio.h>
#include<stdlib.h>

typedef int Dato;

typedef struct Nodo{
        
    Dato contenido;
	struct Nodo *sig;
}Nodo;

typedef struct{
        
	int tam;
	Nodo *inicio;
	Nodo *fin;
}Lista;


Nodo *creaNodo(Dato nuevo){
	 Nodo * aux;
	  
	aux = (Nodo*) malloc(1*sizeof(Nodo));
	aux->contenido = nuevo;
	aux->sig=NULL;
	return aux;
	
}

Dato creaDato(int a){
	Dato nuevo;
	nuevo= a;
	return nuevo;
}

void inicializa(Lista *A){
	A->tam=0;
	A->inicio=NULL;
	A->fin=NULL;
}

int esVacia(Lista A){
	if(A.fin==NULL && A.inicio==NULL){
		return 1;
	}
	return 0;
}

int tamLista(Lista A){
	return A.tam;
}

void imprimeDato(Dato a){
	printf("%d ", a);
}

void imprimeLista(Lista A){
Nodo * aux;
	if(esVacia(A)==0){
		aux= A.inicio;
		while(aux!=NULL){
			imprimeDato(aux->contenido);
			aux= aux->sig;
		}

	}else{
		 printf("Lista vacia");
	}

}

void insertaInicio(Lista *A,Dato nuevo){
	Nodo *porInsertar=creaNodo(nuevo);
	if(esVacia(*A)==1){
		A->fin=porInsertar;
	}else{
		porInsertar->sig=A->inicio;
	}
	A->inicio=porInsertar;
	A->tam++;
}

void insertaFinal(Lista *A,Dato nuevo){
	Nodo *porInsertar=creaNodo(nuevo);
	if(esVacia(*A)==1){
		A->inicio=porInsertar;
	}else{
		A->fin->sig=porInsertar;  //Verificar porque no deja acceder al miembro con el punto
	}
	A->fin=porInsertar;
	A->tam++;
}

void insertaPos(Lista *A,Dato nuevo,int k){
     int pos=0;
     Nodo *aux=NULL;
     Nodo *porInsertar=creaNodo(nuevo);
     if(k==0 || esVacia(*A)==1){
             insertaInicio(A,nuevo);
     }else{
           if(k>=tamLista(*A)){
              insertaFinal(A,nuevo);
           }else{
              aux=A->inicio;
              for(pos=0;pos<k-1;pos++){
              aux=aux->sig;
              }
              porInsertar->sig=aux->sig;
              aux->sig=porInsertar;
              A->tam;
              }
     }
}

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

int comparaDatos(Dato a, Dato b){
   if(a==b){
	return 1;
   }
   return 0;
}

int busqueda(Lista A, Dato buscado, int (* compara)(Dato, Dato)){
    Nodo *aux= A.inicio;
    int pos=0; 
    while(aux!=NULL && compara(buscado, aux->contenido)!=1){
	aux= aux->sig;
        pos++;
        }	
        if(aux==NULL){
	return -1;
    }else{
   return pos;
   }
}	
           
main(){
       Lista lista;
       Dato nuevo=16;
       
       inicializa(&lista);
       insertaInicio(&lista,nuevo);
       imprimeLista(lista);
       
}
