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
    time_t segundos = time(NULL) ; // Toma el tiempo desde el 1 de enero de 1970 hasta ahora y lo convierte a segundos.
    struct tm *tiempoActual = localtime(&segundos) ; // Transforma los segundos en el formato tm, que contiene los parámetros de la hora actual (año, mes, día, horas...).
    strftime(T, M_TIEMPO, "%Y-%m-%d %H:%M:%S", tiempoActual) ; // Convierte el tiempo en un string con el formato que se desea.
}

int IDenLista(int ID, List* L) {
    tipoTicket *pivote = list_first(L) ; // Toma el primero de la lista, para recorrerlo.
    while (pivote != NULL) {
        if (pivote->ID == ID) return 1 ; // Si la ID es igual a la de mi pivote, retorna 1 (significando que si lo encontró).
        pivote = list_next(L) ; // Si no, el pivote se mueve al siguiente elemento.
    }
    // Retorna 0 en caso de no encontrar el ID dentro de la lista.
    return 0 ; 
}

int listaEstaVacia(List* L) {
    if (list_first(L) == NULL) { // Si no hay ningún ticket (la lista está vacía), menciona que no hay tickets registrados.
        puts("NO HAY TICKETS REGISTRADOS.") ; 
        return 1 ;
    }
    return 0 ;
}

int ordenar(void* data1, void* data2) {
    tipoTicket* a = (tipoTicket*) data1 ; // Convierte los datos a tipoTicket (mi estructura del ticket).
    tipoTicket* b = (tipoTicket*) data2 ;
    if (a->prioridad == b->prioridad) { // Si las prioridades son las mismas, ordena por orden de llegada (de menor a mayor).
        return a->orden < b->orden ;
    }
    return a->prioridad > b->prioridad ; // Ordena por prioridad, de mayor a menor (siendo ALTO el mayor, y BAJO el menor)
}