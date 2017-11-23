#include "Uno.h"


int main(){
    partido* primero = LlenarPartidos();
    partido* p = primero;
    partido** pe = &p;
    partido* nulo = NULL;
    partido** interesantes = &nulo;
    DividirPartidos(pe,interesantes);
    printf("Partidos bleh: \n");
    imprimirPartido(*pe);
    printf("\nPartidos interesantes: \n");
    imprimirPartido(*interesantes);
    Borrado(interesantes);
    getchar();
    return 0;
}

partido* AgregarPartido(partido* p,char* desc,int vis,int loc){
    p->siguiente = (partido*)malloc(sizeof(partido));
    p->siguiente->descripcion = desc;
    p->siguiente->puntos_equipo_visitante = vis;
    p->siguiente->puntos_equipo_local = loc;
    p->siguiente->siguiente = NULL;
    
    return p->siguiente;
}

partido* CrearPartido(char* desc,int vis,int loc){
    partido* p = (partido*)malloc(sizeof(partido));
    p->descripcion = desc;
    p->puntos_equipo_local = loc;
    p->puntos_equipo_visitante = vis;
    p->siguiente = NULL;
    return p;
}

partido* LlenarPartidos(){
    partido* primero = CrearPartido("primero",32,15);
    partido* segundo = AgregarPartido(primero,"segundo",15,10);
    AgregarPartido(segundo,"tercero",8,2);
    return primero;
}

void imprimirPartido(partido* p){
    printf("Descripcion: %s \n",p->descripcion);
    printf("Local: %i \n",p->puntos_equipo_local);
    printf("Visitante: %i \n",p->puntos_equipo_visitante);
    printf("Siguiente: %lu \n",p->siguiente);
    if(p->siguiente != NULL)
        imprimirPartido(p->siguiente);
    else
        printf("--No hay mas partidos--\n");
    }
    
    void DividirPartidos(partido** in, partido** out){
        partido* part = *in;
        partido* anterior;
        while(part != NULL){
            partido* actual = part;
            part = actual->siguiente;
            if(DobleOMas(actual) == 1){
                if(actual->descripcion == (*in)->descripcion){
                    if(part != NULL){
                        *in = part;
                    }
                    else{
                        *in = NULL;
                    }
                }
                else{
                    anterior->siguiente = part;
                }
                
                actual->siguiente = NULL;

                if(*out != NULL){
                    partido* ultimo = Ultimo(*out);
                    ultimo->siguiente = actual;
                }
                else{
                    *out = actual;
                }
            }
            anterior = actual;
        }
    }

    int DobleOMas(partido* p){
        return p->puntos_equipo_visitante >= 2* p->puntos_equipo_local;
    }

    partido* Ultimo(partido*p){
        while(p->siguiente != NULL){
            p = p->siguiente;
        }
        return p;
    }