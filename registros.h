
void registroSencilla(Lista *A){
	system("cls");
	//Varible para la opcion de recursividad
	char op;
	//Variabels para la lista Hotel
	Dato nuevoainsertar;
	Cuarto *nuevo = (Cuarto *)malloc(sizeof(Cuarto));
	//variables para el cuarto
	Lista * huespedes= (Lista *)malloc(sizeof(Lista));
	Dato  datonuevo;
	Tipocamas nuevascamas;
	inicializa(huespedes);
	Persona *cliente  =(Persona *)malloc(sizeof(Persona));
	inicializaTipoCamas(&nuevascamas, 1, 0);
	setInfocliente(cliente);
	datonuevo = (Dato)(cliente);
	insertaInicio(huespedes, datonuevo);	
	nuevoainsertar=creaDatoCuarto(idCuarto,1,nuevascamas,1,(void*)(huespedes),nuevo);
	insertaInicio(A, nuevoainsertar);
	printf("¿Decea realizar otro registro de cuarto Sencillo? [S/N]: ");
	scanf("%c",&op);
	if (op == 'S' || op == 's'){
		idCuarto++;
		registroSencilla(A);
	}
}
void registroDoble(Lista *A){
	system("cls");
	int op = 0;
	int i = 0;
	int numAux = 0;
	//------------------------------------------------------
	op = menuRegistroDoble();
	if (op != 0){
		//Variabels para la lista Hotel
		Dato nuevoainsertar;
		Cuarto *nuevo = (Cuarto *)malloc(sizeof(Cuarto));
		//variables para el cuarto
		Lista * huespedes= (Lista *)malloc(sizeof(Lista));
		Dato  datonuevo;
		Tipocamas nuevascamas;
		inicializa(huespedes);
		if(op==1){ numAux = 2; inicializaTipoCamas(&nuevascamas,2,0);
		}else{	   numAux = 4; inicializaTipoCamas(&nuevascamas,0,2);}
		for(i = 0; i < numAux; i++){
			Persona *cliente  =(Persona *)malloc(sizeof(Persona));
			setInfocliente(cliente);
			datonuevo= (Dato)(cliente);
			insertaInicio(huespedes, datonuevo);
		}	
		nuevoainsertar=creaDatoCuarto(idCuarto,2,nuevascamas,numAux,(void*)(huespedes),nuevo);
		insertaInicio(A, nuevoainsertar);
		printf("¿Decea realizar otro registro de cuarto doble? [S/N]: ");
		scanf("%c",&op);
		if (op == 'S' || op == 's'){
			idCuarto++;
			registroSencilla(A);
		}
		
	}
	//------------------------------------------------------
	system("pause");
}
void registroTriple(Lista *A){
	system("cls");
	int i = 0;
	//Varible para la opcion de recursividad
	char op;
	//Variabels para la lista Hotel
	Dato nuevoainsertar;
	Cuarto *nuevo = (Cuarto *)malloc(sizeof(Cuarto));
	//variables para el cuarto
	Lista * huespedes= (Lista *)malloc(sizeof(Lista));
	Dato  datonuevo;
	Tipocamas nuevascamas;
	inicializa(huespedes);
	Persona *cliente  =(Persona *)malloc(sizeof(Persona));
	inicializaTipoCamas(&nuevascamas,0,3);
	for(i = 0; i < 3; i++){
		Persona *cliente  =(Persona *)malloc(sizeof(Persona));
		setInfocliente(cliente);
		datonuevo= (Dato)(cliente);
		insertaInicio(huespedes, datonuevo);
	}	
	nuevoainsertar=creaDatoCuarto(idCuarto,3,nuevascamas,3,(void*)(huespedes),nuevo);
	insertaInicio(A, nuevoainsertar);
	printf("¿Decea realizar otro registro de cuarto Sencillo? [S/N]: ");
	scanf("%c",&op);
	if (op == 'S' || op == 's'){
		idCuarto++;
		registroSencilla(A);
	}
}
void setInfocliente(Persona * nuevoCliente){
	char nombre[100];
	int age;
	fflush(stdin);
	printf("Dame el nombre del cliente\n");
	scanf("%[^\n]", nombre);
	fflush(stdin);
	printf("Dame la edad del huesped\n");
	scanf("%d", &age);
	fflush(stdin);
	creaDatoPersona(nombre, age, nuevoCliente);
}
