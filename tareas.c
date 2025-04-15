#include <stdio.h>
typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;
typedef struct Nodo{
Tarea T;
tNodo *Siguiente;
}tNodo;

tNodo *creaNodo(int id,char*descrip,int tiempo){

        tNodo *nNodo = (tNodo*)malloc(sizeof(tNodo));
        nNodo->T.TareaID = id;
        nNodo->T.Duracion = tiempo;
        nNodo->T.Descripcion = descrip;
        nNodo->Siguiente = NULL;
        return nNodo;
}
void insertarNodo(tNodo **start,tNodo *nNodo){
    nNodo ->Siguiente = *start;
    *start = nNodo;
}

int main(){
    
    int id=1000;
    tNodo *start;
    tNodo * tareaR(){
        return NULL;
    }
    tNodo *tereaP(){
        return NULL;
    }

    start = tareaP();

    return 0;
}