#include "list.h"
#include "tickets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void imprimirSeparador(char* sep, char* string) {
    puts(sep) ;
    puts(string) ;
    puts(sep) ;
}

void imprimirTicket(tipoTicket* D) {
    char* prioridadF ;
    switch (D->prioridad) {
        case 0 : { prioridadF = "BAJA" ; break ; }
        case 1 : { prioridadF = "MEDIA" ; break ; } 
        case 2 : { prioridadF = "ALTA" ; break ; } 
    }

    printf("Ticket con prioridad %s\n", prioridadF) ;
    printf("ID: %d | Hora de Registro: %s\n", D->ID, D->horaActual) ;
    printf("Detalle del problema:\n%s\n", D->problema) ;
}

void mostrarMenuPrincipal() {
    system("cls") ;
    imprimirSeparador("#================#", "Sistema de Tickets") ;

    puts("(1). Registrar ticket") ;
    puts("(2). Asignar prioridad") ;
    puts("(3). Mostrar lista de tickets") ;
    puts("(4). Procesar ticket") ;
    puts("(5). Buscar ticket") ;
    puts("(0). Salir") ;
}

void esperarEnter() {
    puts("Presione ENTER para continuar...") ;
    while (getchar() != '\n') ;
}

//*******************************//

void asignarTiempo(char *T) {
    time_t segundos = time(NULL) ;
    struct tm *tiempoActual = localtime(&segundos) ;
    strftime(T, M_TIEMPO, "%Y-%m-%d %H:%M:%S", tiempoActual) ;
}

int IDenLista(int ID, List* L) {
    tipoTicket *pivote = list_first(L) ;
    while (pivote != NULL) {
        if (pivote->ID == ID) return 1 ;
        pivote = list_next(L) ;
    }

    return 0 ;
}

int listaEstaVacia(List* L) {
    if (list_first(L) == NULL) { 
        puts("NO HAY TICKETS REGISTRADOS.") ; 
        return 1 ;
    }
    return 0 ;
}


int ordenar(void* data1, void* data2) {
    tipoTicket* a = (tipoTicket*) data1 ;
    tipoTicket* b = (tipoTicket*) data2 ;
    if (a->prioridad == b->prioridad) {
        return a->orden < b->orden ;
    }
    return a->prioridad > b->prioridad ;
}