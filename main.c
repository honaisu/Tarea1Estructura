#include "TDAs/list.h"
#include "TDAs/tickets.h"
#include "TDAs/extra_tickets.h"
#include <stdio.h>
#include <stdlib.h>

/*********
    ORDEN POR PRIORIDADES
Cada ticket posee un nivel de urgencia (Alto, Medio y Bajo)
Programa que registra nuevos tickets, modificar su prioridad, procesarlos y mostrarlos
**********/

int main() {
    char opcion ;
    List *listaTickets = list_create() ;

    do {
        mostrarMenuPrincipal() ;
        puts("Seleccione su opción: ") ;
        scanf(" %c", &opcion) ;

        switch (opcion) {
            case '1': { // Registrar el ticket
                ticket_registrar(listaTickets) ;
                break ;
            }
            case '2': { // Asignar prioridad a un ticket
                ticket_asignarPrioridad(listaTickets) ;
                getchar() ;
                break ;
            }
            case '3': // Mostrar la lista de tickets pendientes
                ticket_mostrarPendientes(listaTickets) ;
                getchar() ;
                break ;
            case '4': { // Procesar el ticket siguiente y eliminar el que estaba
                ticket_procesarSiguiente(listaTickets) ;
                getchar() ;
                break ;
            }
            case '5': { // Buscar cierto ticket
                ticket_buscar(listaTickets) ;
                getchar() ;
                break ;
            }
            case '0': {
                break ;
            }
            default: { // En caso de que ninguna opción sea la indicada en los casos
                puts("Opción no válida. Por favor, ingrese una de las opciones presentadas.") ;
                getchar() ;
            }
        }
        if (opcion != '0') esperarEnter() ;
    } while (opcion != '0') ;

    puts("Saliendo del programa...") ;
    list_clean(listaTickets) ;
    
    return 0 ;
}
