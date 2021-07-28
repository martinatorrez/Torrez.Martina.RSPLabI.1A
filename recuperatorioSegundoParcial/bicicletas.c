#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"

int menu()
{
    int option;
    system("cls");
    printf("  ***Menu***   \n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar posiciones\n");
    printf("6. Guardar posiciones\n");
    printf("7. Salir\n");


    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

eBicicletas* bicicletas_new()
{
    eBicicletas* newBicicleta = (eBicicletas*) malloc(sizeof(eBicicletas));
    if(newBicicleta!=NULL)
    {
        newBicicleta->id_bike=0;
        strcpy(newBicicleta->nombre, "");
        strcpy(newBicicleta->tipo, "");
        newBicicleta->tiempo=0;
    }
    return newBicicleta;

}

int bicicleta_setId(eBicicletas* bicicleta,int id)
{
    int todoOk=0;
    if(bicicleta!=NULL&&id>0)
    {
        bicicleta->id_bike=id;
        todoOk=1;

    }
    return todoOk;
}

int bicicleta_getId(eBicicletas* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id !=NULL)
    {
        *id = this->id_bike;
        todoOk=1;
    }
    return todoOk;
}

int bicicleta_setNombre(eBicicletas* bicicleta,char* nombre)
{
    int todoOk=0;
    if(bicicleta!=NULL&& nombre!=NULL &&strlen(nombre)<20)
    {
        strcpy(bicicleta->nombre,nombre);
        todoOk=1;
    }
    return todoOk;
}
int bicicleta_getNombre(eBicicletas* this,char* nombre)
{
    int todoOk = 0;
    if(nombre != NULL && this != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setTipo(eBicicletas* bicicleta,char* tipo)
{
    int todoOk=0;
    if(bicicleta!=NULL&& tipo!=NULL &&strlen(tipo)<20)
    {
        strcpy(bicicleta->tipo,tipo);
        todoOk=1;
    }
    return todoOk;
}
int bicicleta_getTipo(eBicicletas* this,char* tipo)
{
    int todoOk = 0;
    if(tipo != NULL && this != NULL)
    {
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }
    return todoOk;
}


int bicicleta_setTiempo(eBicicletas* bicicleta,int tiempo)
{
    int todoOk=0;
    if(bicicleta!=NULL&& tiempo>=0)
    {
        bicicleta->tiempo=tiempo;
        todoOk=1;
    }
    return todoOk;
}

int bicicleta_getTiempo(eBicicletas* this,int* tiempo)
{
    int todoOk=0;
    if(this!=NULL && tiempo !=NULL)
    {
        *tiempo = this->tiempo;
        todoOk=1;
    }
    return todoOk;
}

void bicicleta_delete(eBicicletas* p)
{
    free(p);
}
eBicicletas* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipo, char* tiempo)
{
    eBicicletas* nuevaBicicleta = bicicletas_new();
    if(nuevaBicicleta!=NULL)
    {
        if(!(bicicleta_setId(nuevaBicicleta,atoi(idStr)) &&
                bicicleta_setNombre(nuevaBicicleta,nombreStr) &&
                bicicleta_setTipo(nuevaBicicleta,tipo)&&
                bicicleta_setTiempo(nuevaBicicleta,atof(tiempo))))
        {
            bicicleta_delete(nuevaBicicleta);
            nuevaBicicleta=NULL;
        }
    }
    return nuevaBicicleta;
}

int mostrarBicicleta(eBicicletas* p)
{
    int auxId;
    char auxNombre[20];
    char auxTipo[20];
    int auxTiempo;
    int todoOk=0;

    if(p!=NULL && bicicleta_getId(p,&auxId) &&
            bicicleta_getNombre(p, auxNombre) &&
            bicicleta_getTipo(p, auxTipo) &&
            bicicleta_getTiempo(p, &auxTiempo))
    {
        printf("%2d  %2s  %2s  %2d\n", auxId, auxNombre, auxTipo,auxTiempo);
        todoOk=1;
    }
    return todoOk;
}
