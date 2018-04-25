//Variables globales
int idCuarto=0;
//Metodo inicializa primer menu
void selecionOperacion(Lista *A);
//Presentacion de menus
void menu();
void menuRegistro();
//funciones/procedimeintos funcionales
void registro(Lista *A);
void elimina(Lista *A);
void busqueda(Lista A);
void generalistado(Lista A);
//funciones de registro
void registroSencilla(Lista * A);
void registroDoble(Lista *A);
void registroTriple(Lista *A);

//FUNCION SOLICITUD DE INFO CLIENTES
void setInfocliente(Persona * nuevoCliente);
void imprimeCuartos(Dato  consultando, int op,FILE *archivo);
//Imprime lista de cuartos
void imprimeListaHotel(Lista A, int op);
