#ifndef TICKETS_H
#define TICKETS_H
#include "list.h"
#include <time.h>

// Macro para el tamaño máximo de la descripción del problema.
#define MAX 1000
// Macro del tamaño máximo del string del tiempo.
#define M_TIEMPO 50

// Representa un ticket. Posee valores como ID, un problema, prioridad, la hora actual de consulta, y una variable que guarda el orden de llegada.
typedef struct tipoTicket {
    int ID ; // Valor que se le asignará al ticket. Representa la identificación del cliente.
    char problema[MAX] ; // Problema a describir por el cliente, posee un máximo ajustable.
    int prioridad ; // Guardará valores 2 (Alto), 1 (Medio) y 0 (Bajo) que definen su prioridad.
    char horaActual[M_TIEMPO] ; // Guarda la hora (string) en que el cliente hizo la petición. 
    clock_t orden ; // Guarda el orden de llegada del ticket.
} tipoTicket ;

// FUNCIONES NECESARIAS

// Genera un ticket con un usuario. Requiere su ID y descripción del problema. Asigna su prioridad a bajo y la hora actual.
void ticket_registrar(List*) ; 
// Modifica cierta prioridad a un ticket. Se ingresan valores numéricos, y se asocia una prioridad dependiendo del caso.
void ticket_asignarPrioridad(List*) ;
// Muestra los tickets por prioridad, y por hora más antigua (orden de llegada).
void ticket_mostrarPendientes(List*) ; 
// Procesa el ticket con mayor prioridad, y más antiguo, y lo elimina de la lista.
void ticket_procesarSiguiente(List*) ; 
// Busca el ticket que se desee ingresando el ID del ticket, mostrando sus datos.
void ticket_buscar(List*) ; 

#endif