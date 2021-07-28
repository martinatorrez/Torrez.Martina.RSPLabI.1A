#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"


#endif // CONTROLLER_H_INCLUDED
int controller_listBicicletas(LinkedList* listaBicicletas);
int loadFromText(char* path, LinkedList* listaBicicletas);
int saveAsText(char* path, LinkedList* listaBicicletas);
void* asignarTiempos(void* pElement);
int filtrarTipo(void* pElement);
int ordenarBicicletas(void* bicicleta1, void* bicicleta2);
int controller_sortBicicletas(LinkedList* lista);
