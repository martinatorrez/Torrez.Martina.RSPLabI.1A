#include <stdio.h>
#include <stdlib.h>
#include "bicicletas.h"
#include "LinkedList.h"
#include "controller.h"
int main()
{
    int opcion=0;
    int flagBicicleta=0;
    int flagTiempo=0;
    int flagOrden=0;
    char nombreArchivo[40];


    LinkedList* listaBicicletas=ll_newLinkedList();
    LinkedList* listaBicicletasTipo = ll_newLinkedList();
    if(listaBicicletas==NULL)
    {
        printf("No se pudo crear el linkedlist\n");
    }
    do
    {
        switch(menu())
        {
        case 1:
            do
            {
                printf("Ingrese el nombre del archivo que quiere cargar: 'bicicletas.csv', 'bicicletastipo.csv' o 'bicicletasorden.csv'\n");
                fflush(stdin);
                gets(nombreArchivo);
                flagBicicleta=1;
            }
            while(loadFromText(nombreArchivo, listaBicicletas)!=1);
            if(flagBicicleta==1)
            {
                printf("Bicicletas cargadas con exito\n");
                system("pause");
            }
            break;
        case 2:
            if(flagBicicleta!=0)
            {
                controller_listBicicletas(listaBicicletas);
                system("pause");
            }
            else
            {
                printf("Debe cargar las bicicletas con la opcion 1 para acceder a esta opcion");
                system("pause");
            }
            break;
        case 3:
            if(flagBicicleta!=0)
            {
                ll_map(listaBicicletas,asignarTiempos);
                printf("Se aplico el tiempo correctamente\n");
                flagTiempo=1;
                system("pause");
            }
            else
            {
                printf("Debe cargar las bicicletas con la opcion 1 para acceder a esta opcion");
                system("pause");
            }
            break;
        case 4:
            if(flagBicicleta!=0 && flagTiempo==0)
            {
                printf("Debe asignar el tiempo para acceder a esta opcion\n");
                system("pause");
            }
            else if(flagBicicleta!=0 && flagTiempo!=0)
            {
                listaBicicletasTipo=ll_filter(listaBicicletas,filtrarTipo);
                saveAsText("bicicletastipo.csv", listaBicicletasTipo);
                printf("Bicicletas filtradas y guardadas con exito\n");
                system("pause");
            }
            else
            {
                printf("Debe cargar las bicicletas con la opcion 1 para acceder a esta opcion\n");
                system("pause");
            }
            break;
        case 5:
            if(flagBicicleta!=0)
            {
                controller_sortBicicletas(listaBicicletas);
                controller_listBicicletas(listaBicicletas);
                flagOrden=1;
                system("pause");
            }
            else
            {
                printf("Debe cargar los paises con la opcion a para acceder a esta opcion\n");
                system("pause");
            }
            break;
            break;
        case 6:
            if(flagBicicleta!=0 && flagOrden==0)
            {
                printf("Debe ordenar las bicicletas con la opcion 5 para acceder a esta opcion\n");
                system("pause");
            }
            else if(flagBicicleta!=0 && flagOrden!=0)
            {
                saveAsText("bicicletasorden.csv", listaBicicletas);
                printf("Bicicletas guardadas en un archivo con exito\n");
                system("pause");
            }
            else
            {
                printf("Debe cargar las bicicletas con la opcion 1 para acceder a esta opcion\n");
                system("pause");
            }
            break;
        case 7:
            printf("Seguro que desea salir? Si no es asi presione 0: \n");
            scanf("%d", &opcion);
            break;
        }
    }
    while(opcion==0);
    return 0;
}

