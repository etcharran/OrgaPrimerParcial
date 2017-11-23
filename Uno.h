#include "stdint.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct p{
    unsigned char puntos_equipo_local;
    unsigned char puntos_equipo_visitante;
    char* descripcion;
    struct p* siguiente;
} partido;

partido* Ultimo(partido*);
int DobleOMas(partido*);
void DividirPartidos(partido**, partido**);
void imprimirPartido(partido*);
partido* LlenarPartidos();
void Borrado(partido**);
int main();
