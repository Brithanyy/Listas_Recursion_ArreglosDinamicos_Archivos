#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
///ESTRUCTURAS:
typedef struct{
    int dato;
    struct nodo * siguiente;
}nodo;

typedef struct{
    char nombre[20];
    int edad;
}persona;

typedef struct{
    persona persona;
    struct nodoPersona * siguiente;
}nodoPersona;


/// PROTOTIPADO:
int *cargarArregloDinamico(int *arreglo, int *dim, int *validos);
int *redimensionarArreglo(int *arreglo,int *dim, int *validos);
void mostrarArregloDinamico(int *arreglo, int validos);
void pasarDeUnArregloDinamicoAUnArchivo(char nombreArchi[], int *arreglo, int validos);
void mostrarArchivo(char nombreArchi[]);
nodo *inicLista();
nodo *crearNodo(int num);
nodo *agregarAlPrincipio(nodo *lista, nodo *nodoInsertar);
nodo *pasarDeArchiALista(nodo *lista, char nombreArchi[]);
void mostrarListaRecursiva(nodo *lista);
nodo *eliminarNodoPrincipio(nodo *lista);
nodo *eliminarNodosConValores(nodo *lista, int datoEliminar);
nodo *cargarListaEnterosAleatorio(nodo *lista);
int *pasarDeListaArregloYArchivo(char nombreArchi[], nodo *lista, int *arreglo, int *dim, int *validos);
int *cargarArreglo2(int *arreglo, int dim);
void cargarArregloChar(char arreglo[][10], int dim);
void mostrarArregloChar(char arr[][10], int dim);
void pasarDatosApersonas(persona personas[10], int arrEdad[10], char nombres[][10]);
void mostrarEstructuraPersona(persona persona[10]);
nodoPersona *crearNodoPersona(persona persona);
nodoPersona *agregarAlPrincipioPersona(nodoPersona *lista, nodoPersona *nodoInsertar);
nodoPersona *agregarNodosEnOrdenSegunEdadPersona(nodoPersona *lista, nodoPersona *nodoInsertar);
void mostrarListaRecursivaPersna(nodoPersona *lista);
nodoPersona *pasarDeEstructuraALista(nodoPersona *lista, persona personas[10]);
nodoPersona *inicListaPersona();
void modularizarMostrarListaRecursivaPersona(nodoPersona *lista);
int main(){
/// 1) Crear un arreglo dinámico con punteros:
int dim = 10;
int *arreglo = (int *)malloc(dim * sizeof(int));
int validos = 0;
///Al pasarlo por referencia le pasamos la direccion en memoria. Por ende si queremos modificar en contenido en la funcion lo hacemos mediante *
arreglo = cargarArregloDinamico(arreglo, &dim, &validos);
mostrarArregloDinamico(arreglo, validos);
printf("\n\n");
char nombreArchi[] = {"numeros.bin"};
pasarDeUnArregloDinamicoAUnArchivo(nombreArchi, arreglo,validos);
mostrarArchivo(nombreArchi);
printf("\n\n");
nodo *lista = inicLista();
lista = pasarDeArchiALista(lista, nombreArchi);
printf("\nMostrando la lista con los elementos del archivo: \n");
mostrarListaRecursiva(lista);
printf("\n\n");
int dato = 2;
lista = eliminarNodosConValores(lista, dato);
mostrarListaRecursiva(lista);
printf("\n");
///Ejercicio 5:
//nodo *listaPunto5 = inicLista();
//listaPunto5 = cargarListaEnterosAleatorio(listaPunto5);
//printf("\nMOSTRANDO LISTA ALEATORIAMENTE\n");
//mostrarListaRecursiva(listaPunto5);
//
//int dim2 = 10;
//int *array2 = (int *)malloc(dim * sizeof(int));
//int validos2 = 0;
//char nombreArchi2[] = {"archi.bin"};
//array2 = pasarDeListaArregloYArchivo(nombreArchi2,listaPunto5,array2,&dim2, &validos2);
//printf("\nMOSTRANDO ARREGLO 2 CON NUMEROS PARES:\n");
//printf("\MOSTRANDO VALIDOS 2 %i \n", validos2);
//printf("\nARREGLO %i POSICIOM 4", array2[4]);
//printf("\nARREGLO %i POSICIOM 5", array2[5]);
//printf("\nARREGLO %i POSICIOM 6", array2[6]);
//printf("\nARREGLO %i POSICIOM 7", array2[7]);
//mostrarArregloDinamico(array2,validos2);
//printf("\n\n\n");
//printf("\nMOSTRANDO ARCHIVO CON NUMEROS IMPARES:\n");
//mostrarArchivo(nombreArchi2);
//printf("\n\n\n");
//int dim3 = 10;
//int *arreglo2 = (int *)malloc(dim3 * sizeof(int)); ///Dinamico
//arreglo2 = cargarArreglo2(arreglo2,dim3);
//mostrarArregloDinamico(arreglo2, dim3);
char arregloNombres[10][10]; ///Estatico
cargarArregloChar(arregloNombres,dim3);
mostrarArregloChar(arregloNombres,dim3);
persona personas[10];
pasarDatosApersonas(personas,arreglo2, arregloNombres);
mostrarEstructuraPersona(personas);

nodoPersona *listaPersonas = inicListaPersona();
listaPersonas = pasarDeEstructuraALista(listaPersonas,personas);
printf("\nMOSTRANDO LA LISTA CON LAS PERSONAS REGISTRADAS: \n\n");
mostrarListaRecursivaPersna(listaPersonas);
}
///PUNTO 1:
int *cargarArregloDinamico(int *arreglo, int *dim, int *validos){
    char eleccion = 's';
    int i = 0;
    while(eleccion == 's'){
        /// PARA REDIMENSIONAR ARREGLO:
        arreglo = redimensionarArreglo(arreglo, dim, validos);

        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%i", &arreglo[i]);
        *validos = i;
        i++;

        printf("Pulsa 's' si desea continuar: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }
    return arreglo;
}

int *redimensionarArreglo(int *arreglo,int *dim, int *validos){
    if(*dim == *validos){
            *dim = *dim + *dim;
            printf("\nEl arreglo se quedo sin espacios. Incrementando %i ...\n", *dim);
            arreglo = (int *)realloc(arreglo,*dim * sizeof(int));
            printf("\nMostrando la dimension actual: %i ...\n", *dim);
        }
        return arreglo;
}

///Mostrar arreglo dinamico:
void mostrarArregloDinamico(int *arreglo, int validos){
    for(int i = 0; i < validos; i++){
        printf("|%i|", arreglo[i]);
    }
}
///Ejercicio 3:
void pasarDeUnArregloDinamicoAUnArchivo(char nombreArchi[], int *arreglo, int validos){
    FILE *punteroArchi = fopen(nombreArchi,"ab");
    int numero;
    if(punteroArchi != NULL){
            for(int i = 0; i < validos; i++){
                numero = arreglo[i];
                fwrite(&numero,sizeof(int),1,punteroArchi);
            }
            fclose(punteroArchi);
    }else printf("\nError al abrir el archivo.\n");
}
void mostrarArchivo(char nombreArchi[]){
    FILE *punteroArchi = fopen(nombreArchi,"rb");
    int num;
    if(punteroArchi != NULL){
        while(!feof(punteroArchi)){
            fread(&num,sizeof(int),1,punteroArchi);
            if(!feof(punteroArchi)){
            printf("|%i| ",num);
            }
        }
    printf("\n\n");
    fclose(punteroArchi);
    }else printf("\nError al abrir el archivo.\n");
}
///Ejercicio 4: Algunas finciones basicas de listas
nodo *inicLista(){
    return NULL;
}
nodoPersona *inicListaPersona(){
    return NULL;
}
nodo *crearNodo(int num){
    nodo *aux = (int *)malloc(sizeof(nodo));
    aux->dato = num;
    aux->siguiente = NULL;
    return aux;
}
nodoPersona *crearNodoPersona(persona persona){
    nodoPersona *aux = (nodoPersona *)malloc(sizeof(nodoPersona));
    aux->persona = persona;
    aux->siguiente = NULL;
    return aux;
}
nodo *agregarAlPrincipio(nodo *lista, nodo *nodoInsertar){
    if(lista == NULL) lista = nodoInsertar;
    else{
        nodoInsertar->siguiente = lista;
        lista = nodoInsertar;
    }
    return lista;
}
nodo *agregarNodosEnOrdenSegunDato(nodo *lista, nodo *nodoInsertar){
    nodo *ante;
    nodo *aux;
    if(lista == NULL) lista = nodoInsertar;
    else{
        if(nodoInsertar->dato < lista->dato){
            agregarAlPrincipio(lista,nodoInsertar);
        }else{
            ante = lista;
            aux = lista->siguiente;
            while(aux != NULL && (nodoInsertar->dato > aux->dato)){
                ante = aux;
                aux = aux->siguiente;
            }
            ///CUANDO ENCONTRAMOS LA POSICION:
            ante->siguiente = nodoInsertar;
            nodoInsertar->siguiente = aux;
        }
    }
    return lista;
}
nodo *pasarDeArchiALista(nodo *lista, char nombreArchi[]){
    FILE *punteroArchi = fopen(nombreArchi,"rb");
    int num;
    if(punteroArchi != NULL){
        while(!feof(punteroArchi)){
            fread(&num,sizeof(int),1,punteroArchi);
            nodo *nodoInsertar = crearNodo(num);
            if(!feof(punteroArchi)){
                lista = agregarNodosEnOrdenSegunDato(lista,nodoInsertar);
            }
        }
        fclose(punteroArchi);
    }
    return lista;
}

void mostrarListaRecursiva(nodo *lista){
    if(lista == NULL) printf("");
    else{
        printf("|%i| ", lista->dato);
        mostrarListaRecursiva(lista->siguiente);
    }
}
nodo *eliminarNodoPrincipio(nodo *lista){
    nodo *aux = lista;
    lista = lista->siguiente;
    free(aux);
    aux = NULL;
    return lista;
}
///Ejercicio 4
nodo *eliminarNodosConValores(nodo *lista, int datoEliminar){
    nodo *aux;
    nodo *ante;
    int contador = 0;
    if(lista == NULL) printf("\nLa lista esta vacia no hay nada que eliminar.\n");
    else{
        if(lista->dato == datoEliminar) {
                lista = eliminarNodoPrincipio(lista);
                contador++;
        }
        else{
            ante = lista;
            aux = lista->siguiente;
            while(aux != NULL){
                if(aux->dato == datoEliminar) {
                    ante->siguiente = aux->siguiente;
                    nodo *auxBorrar = aux;
                   // aux = aux->siguiente;
                    free(auxBorrar);
                    auxBorrar = NULL;
                    contador++;
                }//else {
                    ante = aux;
                    aux = aux->siguiente;
                    //}
                }
            }
        }
    printf("\nLa cantidad de nodos borrados con el dato %i son %i \n\n", datoEliminar,contador);
    return lista;
}
///Ejercicio 5:
nodo *cargarListaEnterosAleatorio(nodo *lista){
    srand(time(NULL));
    int dato;
    for(int i = 0; i < 50; i++){
        dato = rand()%10+1;
        nodo *aux = crearNodo(dato);
        lista = agregarAlPrincipio(lista,aux);
    }
    return lista;
}
int *pasarDeListaArregloYArchivo(char nombreArchi[], nodo *lista, int *arreglo, int *dim,int *validos){
    FILE *punteroArchi = fopen(nombreArchi,"ab");
    nodo *aux = lista;
    int auxValidos;
    int num;
    if(punteroArchi != NULL){
            printf("\n\n");
            while(aux->siguiente != NULL){
                     num = aux->dato;
                if((aux->dato % 2) == 0){
                    arreglo = redimensionarArreglo(arreglo,dim,validos);
                    auxValidos = *validos;
                    arreglo[auxValidos] = num;
                    printf("/ %i / ", arreglo[auxValidos]);///debug
                    *validos = *validos + 1;
                }else{
                    fwrite(&num,sizeof(int),1,punteroArchi);
                }
                aux = aux->siguiente;
            }
            fclose(punteroArchi);

    }else printf("\nError al abrir el archivo.\n");
    return arreglo;
}
int *cargarArreglo2(int *arreglo, int dim){
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        arreglo[i] = rand()%30+1;
    }
    return arreglo;
}
void cargarArregloChar(char arreglo[][10], int dim){
    strcpy(arreglo[0], "\nBrisa");
    strcpy(arreglo[1], "Rocio");
    strcpy(arreglo[2], "Paola");
    strcpy(arreglo[3], "Lorena");
    strcpy(arreglo[4], "Sandra");
    strcpy(arreglo[5], "Paula");
    strcpy(arreglo[6], "Brithany");
    strcpy(arreglo[7], "Carlos");
    strcpy(arreglo[8], "Valentino");
    strcpy(arreglo[9], "Nicolas");
}
void mostrarArregloChar(char arr[][10], int dim){
    for(int i = 0; i < dim; i++){
        printf("%s \n", arr[i]);
    }
}
void pasarDatosApersonas(persona personas[10], int arrEdad[10], char nombres[][10]){
    for(int i = 0; i < 10; i++){
        strcpy(personas[i].nombre,nombres[i]);
        personas[i].edad = arrEdad[i];
    }
}
void mostrarEstructuraPersona(persona persona[10]){
    for(int i = 0; i < 10; i++){
        printf("\nNombre: %s | Edad: %i\n", persona[i].nombre, persona[i].edad);
    }
}
nodoPersona *pasarDeEstructuraALista(nodoPersona *lista, persona personas[10]){
    nodoPersona *aux;
    persona personaInsertar;
    int i;
    for(i = 0; i < 10; i++){
        personaInsertar = personas[i];
        aux = crearNodoPersona(personaInsertar);
        lista = agregarAlPrincipioPersona(lista,aux);
    }
    return lista;
}
nodoPersona *agregarAlPrincipioPersona(nodoPersona *lista, nodoPersona *nodoInsertar){
    if(lista == NULL) lista = nodoInsertar;
    else{
        nodoInsertar->siguiente = lista;
        lista = nodoInsertar;
    }
    return lista;
}
nodoPersona *agregarNodosEnOrdenSegunEdadPersona(nodoPersona *lista, nodoPersona *nodoInsertar){
    nodoPersona *ante;
    nodoPersona *aux;
    if(lista == NULL) lista = nodoInsertar;
    else{
        if(nodoInsertar->persona.edad < lista->persona.edad){
            agregarAlPrincipioPersona(lista,nodoInsertar);
        }else{
            ante = lista;
            aux = lista->siguiente;
            while(aux != NULL && (nodoInsertar->persona.edad > aux->persona.edad)){
                ante = aux;
                aux = aux->siguiente;
            }
            ///CUANDO ENCONTRAMOS LA POSICION:
            ante->siguiente = nodoInsertar;
            nodoInsertar->siguiente = aux;
        }
    }
    return lista;
}
void mostrarListaRecursivaPersna(nodoPersona *lista){
    if(lista == NULL) printf("");
    else{
        mostrarListaRecursivaPersna(lista->siguiente);
        modularizarMostrarListaRecursivaPersona(lista);
    }
}
void modularizarMostrarListaRecursivaPersona(nodoPersona *lista){
      printf("\nNombre: %s", lista->persona.nombre);
      printf("| Edad: %i \n",lista->persona.edad);
}
