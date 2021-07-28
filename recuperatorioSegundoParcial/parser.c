#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "bicicletas.h"

/** \brief parsea los datos desde el archivo .csv (en modo texto)
 *
 * \param pfile FILE*
 * \param listaBicicletas LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pfile, LinkedList* listaBicicletas)
{
    char buffer[4][20];
    int cant;
    eBicicletas* auxBicicleta;
    while(!feof(pfile))
    {
        cant= fscanf(pfile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant==4)
        {
            auxBicicleta= bicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            if(auxBicicleta!=NULL)
            {
                ll_add(listaBicicletas,auxBicicleta);
            }
        }
    }
    fclose(pfile);
    return 1;
}
