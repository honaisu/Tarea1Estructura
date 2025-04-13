#include "TDAs/list.h"
#include "TDAs/tickets.h"
#include "TDAs/extra_tickets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********
    ORDEN POR PRIORIDADES
Cada ticket posee un nivel de urgencia (Alto, Medio y Bajo)
Programa que registra nuevos tickets, modificar su prioridad, procesarlos y mostrarlos.
**********/

int main() {
    char opcion ;
    char buffer[100] ;
    List *listaTickets = list_create() ;

    do {
        mostrarMenuPrincipal() ;
        puts("Seleccione su opción: ") ;
        // Lee los datos que se quieren.
        fgets(buffer, sizeof(buffer), stdin) ;
        // Toma el primer caracter de buffer y lo guarda en la variable opcion.
        sscanf(buffer, "%c", &opcion) ;

        switch (opcion) {
            case '1': { // Registra el ticket.
                ticket_registrar(listaTickets) ;
                break ;
            }
            case '2': { // Asigna prioridad a un ticket.
                ticket_asignarPrioridad(listaTickets) ;
                break ;
            }
            case '3': // Mostra la lista de tickets pendientes.
                ticket_mostrarPendientes(listaTickets) ;
                break ;
            case '4': { // Procesa el ticket con más prioridad y más antiguo y lo elimina de la lista.
                ticket_procesarSiguiente(listaTickets) ;
                break ;
            }
            case '5': { // Busca cierto ticket dentro de la lista.
                ticket_buscar(listaTickets) ;
                break ;
            }
            case '0': {
                break ;
            }
            default: { // En caso de que ninguna opción sea la indicada en los casos
                puts("Opción no válida. Por favor, ingrese una de las opciones presentadas.") ;
            }
        }
        if (opcion != '0') esperarEnter() ; // Si la opción es distinta a 0, espera ENTER para continuar.
    } while (opcion != '0') ;

    puts("Saliendo del programa...") ;
    list_clean(listaTickets) ; // Quita todos los elementos de la lista.
    free(listaTickets) ; // Libera la memoria asignada por la lista.
    
    return 0 ;
}
