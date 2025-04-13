#include "list.h"
#include "tickets.h"
#include "extra_tickets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

//*====================*//
// FUNCIONES DE TICKETS //
//*====================*//

void ticket_registrar(List* L) {
    // Mensaje principal.
    imprimirSeparador("#================#", "REGISTRE SU TICKET") ;

    //*=======================*//
    tipoTicket* datos = (tipoTicket*) malloc(sizeof(tipoTicket)) ;
    char buffer[100] ; // Buffer para leer datos
    errno = 0 ; // Asigna un valor nulo a errno (para verificar errores)
    datos->orden = clock() ; // Genera un número que irá siempre en aumento. Empieza en 0 y va aumentando con la ejecución del programa.
    asignarTiempo(datos->horaActual) ; // Asigna el tiempo actual al ticket.
    printf("Hora registrada: %s\n", datos->horaActual) ;

    // Escanea un Identificador (ID) que servirá para identificar el ticket del usuario.
    puts("Coloque su Identificador (sólo un valor numérico):") ;
    fgets(buffer, sizeof(buffer), stdin) ;
    // Convierte el string a un ID que se pueda guardar.
    int ID = (int) strtol(buffer, NULL, 10) ;
    if (errno == ERANGE || ID <= 0) { // Verifica que la ID esté dentro del rango.
        puts("La ID no es válida. Vuelva a elegir las opciones.") ;
        free(datos) ;
        return ;
    }
    datos->ID = ID ; // Mueve el ID ingresado a la estructura del ticket.
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
    // Verifica si la lista está vacía. Si lo está, termina la función.
    if (listaEstaVacia(L)) return ;
    // Mensaje principal.
    imprimirSeparador("#==============================#", "ASIGNE LA PRIORIDAD DE UN TICKET") ;

    //*=======================*//
    char buffer[100] ;
    errno = 0 ;
    // Se busca asignar un ID para el ticket.
    printf("Ingrese la ID del ticket: ") ;
    fgets(buffer, sizeof(buffer), stdin) ;
    int IDaBuscar = (int) strtol(buffer, NULL, 10) ;

    if (errno == ERANGE) {
        // Si no encontró el ticket, menciona que el ticket no se encuentra dentro de la lista.
        puts("El ticket es inválido.") ;
    } else if (IDenLista(IDaBuscar, L)) { // Si el ticket está dentro...
        tipoTicket *ticketEncontrado = list_current(L) ; // Apunta a esa posición.
        errno = 0 ;
        //*=======================*//
        puts("Modifique la prioridad del ticket:") ;
        puts("Escriba el número correspondiente a su prioridad deseada.") ;
        puts("'2' (ALTO), '1' (MEDIO) & '0' (BAJO)") ;
        // Escanea el valor que se quiere de prioridad.
        fgets(buffer, sizeof(buffer), stdin) ;
        int prioridad = (int) strtol(buffer, NULL, 10) ;
        if (errno == ERANGE) { // Si es que la función falla, devuelve el mensaje.
            puts("No existe esa prioridad.") ;
        } else if (prioridad > 2 || prioridad < 0) { // Si es que el dato está fuera del rango, lo menciona. 
            puts("La prioridad asignada se encuentra fuera del rango.") ;
        } else {
            ticketEncontrado->prioridad = prioridad ; // Si no, asigna la prioridad del ticket a la prioridad deseada (p).
            list_popCurrent(L) ; // Elimina el ticket actual de la lista.
            list_sortedInsert(L, ticketEncontrado, ordenar) ; // Ordena el ticket por la prioridad asignada y retorna.
        }
    } else {
        puts("El ticket no se encuentra dentro de la lista.") ;
    }
    return ;
}

void ticket_mostrarPendientes(List* L) {
    // Limpia la pantalla de la terminal.
    system("cls") ;
    // Verifica si la lista está vacía o no.
    if (listaEstaVacia(L)) return ;
    // Mensaje principal.
    imprimirSeparador("#=========================#", "LISTA DE TICKETS PENDIENTES") ;
    // Se posiciona la lista en el primer elemento, en la variable dato.
    tipoTicket* dato = list_first(L) ;
    // Imprime los datos del ticket.
    while (dato != NULL) {
        imprimirTicket(dato) ;
        dato = list_next(L) ; // Avanza al siguiente ticket de la lista.
    } 
    return ;
}

void ticket_procesarSiguiente(List* L) {
    // Verifica si la lista está vacía o no.
    if (listaEstaVacia(L)) return ;
    // Mensaje principal.
    imprimirSeparador("#=========================#", "EL TICKET A PROCESAR ES EL:") ;
    // Imprime los datos del primer elemento (el primer ticket).
    imprimirTicket(list_first(L)) ;
    // Quita el ticket de la lista y menciona que fue atendido (que ya se resolvió su problema).
    list_popFront(L) ;
    puts("Ticket atendido.") ;
    return ;
}

void ticket_buscar(List* L) {
    // Verifica si la lista está vacía y termina si es así.
    if (listaEstaVacia(L)) return ;
    //*=======================*//
    char buffer[100] ;
    errno = 0 ;

    puts("Ingrese el ticket a buscar:") ;
    // Se lee el ticket a buscar.
    fgets(buffer, sizeof(buffer), stdin) ;
    int pivote = (int) strtol(buffer, NULL, 10) ;
    // Si la función falla, o el ticket se encuentra fuera de valores que se necesitan, se termina la función.
    if (errno == ERANGE || pivote <= 0) { puts("El ticket no se encuentra dentro de la lista.") ; }
    else if (IDenLista(pivote, L)) { // Si el ID se encuentra dentro de la lista, imprime sus datos.
        puts("#===========================================#") ;
        imprimirTicket(list_current(L)) ;
    } 

    return ;
}