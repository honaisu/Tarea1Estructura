#include "list.h"
#include "tickets.h"
#include "extra_tickets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//*====================*//
// FUNCIONES DE TICKETS //
//*====================*//

void ticket_registrar(List* L) {
    // Mensaje principal.
    imprimirSeparador("#================#", "REGISTRE SU TICKET") ;

    //*=======================*//
    tipoTicket* datos = (tipoTicket*) malloc(sizeof(tipoTicket)) ;

    datos->orden = clock() ;
    asignarTiempo(datos->horaActual) ; // Asigna el tiempo actual al ticket.
    printf("Hora registrada: %s\n", datos->horaActual) ;

    // Escanea un Identificador (ID) que servirá para identificar el ticket del usuario.
    puts("Coloque su Identificador (valor numérico):") ;
    scanf(" %d", &datos->ID) ;
    getchar() ;

    // Verifica si es que el ticket ya se encuentra dentro de la lista o no.
    if (IDenLista(datos->ID, L)) {
        puts("Este ticket ya está registrado.") ;
        return ;
    }

    // Escanea y guarda el problema a resolver del usuario.
    puts("Coloque su problema (1000 carácteres máximo):") ;
    fgets(datos->problema, MAX, stdin) ;

    datos->prioridad = 0 ; // Establece la prioridad a '0' (Bajo) para el dato.
    list_sortedInsert(L, datos, ordenar) ; // Guarda el dato en la lista de datos.
    return ;
}

void ticket_asignarPrioridad(List* L) {
    if (listaEstaVacia(L)) return ;
    imprimirSeparador("#==============================#", "ASIGNE LA PRIORIDAD DE UN TICKET") ;

    int ticketBuscado ;
    tipoTicket *ticket = list_first(L) ;

    printf("Ingrese la ID del ticket: ") ;
    scanf("%d", &ticketBuscado) ;

    for (int p ; ticket != NULL ; ticket = list_next(L)) {
        if (ticket->ID == ticketBuscado) {
            puts("Modifique la prioridad del ticket:") ;
            puts("Escriba el número correspondiente a su prioridad deseada.") ;
            puts("'2' (ALTO), '1' (MEDIO) & '0' (BAJO)") ;
            scanf(" %d", &p) ;
            if (p > 2 || p < 0) puts("NO EXISTE ESA PRIORIDAD.") ;
            else {
                ticket->prioridad = p ;
                list_popCurrent(L) ;
                list_sortedInsert(L, ticket, ordenar) ;
            }
            return ;
        }
    }

    puts("El ticket no se encuentra dentro de la lista.") ;
    return ;
}

void ticket_mostrarPendientes(List* L) {
    system("cls") ;
    if (listaEstaVacia(L)) return ;

    tipoTicket* dato = list_first(L) ;
    imprimirSeparador("#=========================#", "LISTA DE TICKETS PENDIENTES") ;
    // Imprime los datos 
    while (dato != NULL) {
        imprimirTicket(dato) ;
        dato = list_next(L) ; // Avanza al siguiente dato de la lista
    } 
    return ;
}

void ticket_procesarSiguiente(List* L) {
    if (listaEstaVacia(L)) return ;
    imprimirSeparador("#=========================#", "EL TICKET A PROCESAR ES EL:") ;
    imprimirTicket(list_first(L)) ;
    list_popFront(L) ;
    puts("Ticket atendido.") ;
    return ;
}

void ticket_buscar(List* L) {
    if (listaEstaVacia(L)) return ;
    int pivote ;

    puts("Ingrese el ticket a buscar:") ;
    scanf("%d", &pivote) ;

    if (IDenLista(pivote, L)) {
        puts("#===========================================#") ;
        imprimirTicket(list_current(L)) ;
    } else {
        puts("El ticket no se encuentra dentro de la lista.") ;
    }

    return ;
}