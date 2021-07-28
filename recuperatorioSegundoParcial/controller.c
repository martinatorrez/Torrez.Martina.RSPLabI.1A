#include <stdio.h>
#include <stdlib.h>
#include "bicicletas.h"
#include "controller.h"
#include <string.h>
#include "parser.h"
/** \brief muestra las bicicletas de la lista
 *
 * \param listaBicicletas LinkedList*
 * \return int
 *
 */
int controller_listBicicletas(LinkedList* listaBicicletas)
{
    eBicicletas* aux=NULL;
    int todoOk=0;
    int flag=0;

    if(listaBicicletas!=NULL)
    {

        printf("ID  Nombre Tipo  Tiempo\n");
        for(int i=0; i<ll_len(listaBicicletas); i++)
        {
           aux= (eBicicletas*)ll_get(listaBicicletas,i);
           mostrarBicicleta(aux);
           flag=1;
           todoOk=1;
        }
        printf("\n\n");
        if(flag==0)
        {
            printf("No hay bicicletas para mostrar\n");
        }
    }
    return todoOk;
}
/** \brief Carga los datos de las bicicletas desde el archivo .csv en modo texto.
 *
 * \param path char*
 * \param listaBicicletas LinkedList*
 * \return int
 *
 */
int loadFromText(char* path, LinkedList* listaBicicletas)
{
    FILE* f=fopen(path,"r");
    if(f==NULL)
    {
      printf("No se pudo abrir\n");
      exit(1);
    }
    else
    {
      parser_FromText(f,listaBicicletas);
    }
    return 1;
}

/** \brief Guarda los datos de las bicicletas .csv en modo texto
 *
 * \param path char*
 * \param listaBicicletas LinkedList*
 * \return int
 *
 */
int saveAsText(char* path, LinkedList* listaBicicletas)
{
    int todoOk=0;
    eBicicletas* aux;

    FILE* f= fopen(path, "w");
    if(f==NULL)
    {
        printf("No se pudo abrir\n");
    }
    fprintf(f,"Id,nombre,tipo,tiempo\n");
    for(int i=0; i<ll_len(listaBicicletas); i++)
    {
        aux=ll_get(listaBicicletas,i);
        if(aux!=NULL)
        {
            fprintf(f,"%d,%s,%s,%d\n",
                    aux->id_bike,
                    aux->nombre,
                    aux->tipo,
                    aux->tiempo);
            todoOk=1;
        }
    }
    fclose(f);



    return todoOk;
}

/** \brief asigna los tiempos a las bicicletas
 *
 * \param pElement void*
 * \return void*
 *
 */
void* asignarTiempos(void* pElement)
{
    eBicicletas* aux;
    int tiempo;
    int max1 = 120;
    int min1 = 50;



    if(pElement != NULL )
    {
        aux=(eBicicletas*) pElement;
        tiempo = rand() % (max1 - min1 + 1) + min1;
        aux->tiempo = tiempo;

    }
    return aux;
}

/** \brief filtra las bicicletas por el tipo seleccionado
 *
 * \param pElement void*
 * \return int
 *
 */
int filtrarTipo(void* pElement)
{
   int retorno=0;
    eBicicletas* aux;
    if(pElement!=NULL)
    {
        aux=(eBicicletas*) pElement;
        if(strcmp(aux->tipo,"BMX")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

/** \brief ordena las bicicletas por tipo de la A a la Z
 *
 * \param bicicleta1 void*
 * \param bicicleta2 void*
 * \return int
 *
 */
int ordenarBicicletas(void* bicicleta1, void* bicicleta2)
{
    eBicicletas* b1;
    eBicicletas* b2;
    int retorno=-2;

    b1= (eBicicletas*)bicicleta1;
    b2= (eBicicletas*) bicicleta2;
    if(bicicleta1 != NULL && bicicleta2 != NULL)
    {
        if(strcmp(b1->tipo,b2->tipo)>0)
        {
            retorno=1;
        }
        else if(strcmp(b1->tipo,b2->tipo)==0)
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief ordena las bicicletas
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_sortBicicletas(LinkedList* lista)
{
   printf("Bicicletas ordenadas\n");

    ll_sort(lista,ordenarBicicletas,1);

    return 1;
}
