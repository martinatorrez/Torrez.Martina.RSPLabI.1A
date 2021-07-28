#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;

} eBicicletas;


#endif // BICICLETAS_H_INCLUDED
int menu();
eBicicletas* bicicletas_new();
int bicicleta_setId(eBicicletas* bicicleta,int id);
int bicicleta_getId(eBicicletas* this,int* id);
int bicicleta_setNombre(eBicicletas* bicicleta,char* nombre);
int bicicleta_getNombre(eBicicletas* this,char* nombre);
int bicicleta_setTipo(eBicicletas* bicicleta,char* tipo);
int bicicleta_getTipo(eBicicletas* this,char* tipo);
int bicicleta_setTiempo(eBicicletas* bicicleta,int tiempo);
int bicicleta_getTiempo(eBicicletas* this,int* tiempo);
void bicicleta_delete(eBicicletas* p);
eBicicletas* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipo, char* tiempo);
int mostrarBicicleta(eBicicletas* p);
