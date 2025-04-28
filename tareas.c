#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;
typedef struct Nodo tNodo;


typedef struct Nodo{
Tarea T;
 tNodo *Siguiente;
}tNodo;

tNodo *creaNodo(int id,char*descrip,int tiempo,int tam){

        tNodo *nNodo = (tNodo*)malloc(sizeof(tNodo));
        nNodo->T.TareaID = id;
        nNodo->T.Duracion = tiempo;
        nNodo->T.Descripcion = (char *)malloc(tam * sizeof(char) + 1);
        strcpy(nNodo->T.Descripcion,descrip);
        nNodo->Siguiente = NULL;
        return nNodo;
}

void insertarNodo(tNodo **start,tNodo *nNodo){
    nNodo ->Siguiente = *start;
    *start = nNodo;
}

tNodo  * listaVacia();
tNodo* buscaPalabra(tNodo *start,char*transferido);
tNodo * quitarNodo(tNodo **start,int id);
void leerListas(tNodo * start,tNodo *realizada);
void buscarPorId(int num,tNodo ** pend,tNodo **reali);

int main(){
    
    int id=1000,tiempo,tam,cambiar;
    char busca[40];
    char descrip[40];
    tNodo *resultado;
    
    tNodo *relizada = listaVacia();
    tNodo *start = listaVacia(); 


    

    int agreagarTarea=1;

    while (agreagarTarea == 1)
    {
        printf("ingrese la descripcion de la tarea pendiente:");
        scanf("%s",descrip);
        tam = strlen(descrip);

        printf("ingrese la duracion de la tarea:");
        scanf("%d",&tiempo);

        tNodo * Nodo = creaNodo(id,descrip,tiempo,tam);
        insertarNodo(&start,Nodo);

        printf("ingresar 1 para agregar mas tareas o 0 para finalizar\n");
        id++;
        scanf("%d",&agreagarTarea);
    }
    
    printf("desea cambiar una tarea pendiente a realizada? 1:si 2:no\n");
    scanf("%d",&cambiar);

    while (cambiar == 1)
    {
        printf("ingrese la activad buscada\n");
        scanf("%s",busca);
        
        resultado = buscaPalabra(start,busca);

        if (resultado !=NULL)
        {
            tNodo * trealizada = creaNodo(resultado->T.TareaID,resultado->T.Descripcion,resultado->T.Duracion,strlen(resultado->T.Descripcion));
             insertarNodo(&relizada,trealizada);
             quitarNodo(&start,resultado->T.TareaID);
             printf("se agrego a la lista de tareas realizadas:%s\n",resultado->T.Descripcion);
        }else
        {
            printf("esa tarea no exite\n");
        }
        
        printf("desea cambiar una tarea pendiente a realizada? 1:si 2:no\n");
        scanf("%d",&cambiar);

    }

    leerListas(start,relizada);

    int numero;
    printf("ingrese el id buscado");
    scanf("%d",&numero);

    buscarPorId(numero,&start,&relizada);
    

    return 0;
}
tNodo * listaVacia(){
    return NULL;
}

tNodo* buscaPalabra(tNodo *start,char * busca){
    tNodo *aux = start;
    char *respuesta;
    
    
    while (aux != NULL)
    {
        respuesta = strstr(aux->T.Descripcion,busca);
    
        if (respuesta != NULL)
        {
            return aux;    
        }
        aux = aux->Siguiente;
    }   
    return NULL;
}
tNodo* quitarNodo(tNodo **start,int id){
    tNodo *aux = (*start);
    tNodo *nodoAnt = NULL;
    while (aux != NULL && aux->T.TareaID != id)
    {
       nodoAnt = aux; 
       aux = aux->Siguiente;
    }

   if (aux != NULL)
   {
        if (aux == (*start))
        {
            (*start) = aux->Siguiente;
        }else
        {
            nodoAnt->Siguiente = aux->Siguiente;
            
        }
        aux->Siguiente = NULL;
        
   }
   return (aux);
   
}
void leerListas(tNodo *start,tNodo *realizada){
    tNodo *aux1,*aux2;

    aux1 = start;
    aux2 = realizada;

    printf("Lista de pendientes:\n");
    while (aux1)
    {
        printf("tarea: %s  duracion:%d  id:%d\n",aux1->T.Descripcion,aux1->T.Duracion,aux1->T.TareaID);
        aux1 = aux1->Siguiente;
    }

    printf("Lista de realizadas:\n");
    while (aux2)
    {
        printf("tarea: %s  duracion:%d  id:%d\n",aux2->T.Descripcion,aux2->T.Duracion,aux2->T.TareaID);
        aux2 = aux2->Siguiente;
    }   
}
void buscarPorId(int num,tNodo **pend,tNodo **reali){
    tNodo *lista1 = (*pend);
    tNodo *lista2 = (*reali);

    while (lista1 != NULL && lista1->T.TareaID != num)
    {
        lista1 = lista1->Siguiente;

    }

    if (lista1 != NULL)
    {
        printf("tarea encontrada en lista de pendientes\n");
        printf("Tarea Id: %d Tarea:%s  Duracion:%d\n",lista1->T.TareaID,lista1->T.Descripcion,lista1->T.Duracion);
    }

    while (lista2 != NULL && lista2->T.TareaID != num)
    {
        lista2 = lista2->Siguiente;
    }
    
    if (lista2 !=NULL)
    {
        printf("tarea encontrada en lista de realizadas\n");
        printf("Tarea Id: %d Tarea:%s  Duracion:%d\n",lista2->T.TareaID,lista2->T.Descripcion,lista2->T.Duracion);
    }

    if (lista1 == NULL && lista2 == NULL)
    {
        printf("la tarea con ese id no existe\n");
    }
}