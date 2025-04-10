#ifndef EXTRA_TICKETS_H
#define EXTRA_TICKETS_H
#include "list.h"
#include "tickets.h"

// Pertenecientes al main

void mostrarMenuPrincipal() ; // Muestra el menú de las opciones del programa.
void esperarEnter() ; // Espera a que el usuario ingrese ENTER para continuar.

// Pertenecientes al tickets

int IDenLista(int, List*) ; // Recorre una lista hasta encontrar cierto ID
int listaEstaVacia(List*) ; // Verifica si es que la lista se encuentra vacía o no. Devuelve 1 si está vacía, y 0 si no.
void asignarTiempo(char*) ; // Asigna un string con el tiempo actual del sistema.
void imprimirSeparador(char*, char*) ; // Imprime separadores. La primer variable siendo el separador, y la segunda el mensaje.

void imprimirTicket(tipoTicket*) ; // Imprime los datos del ticket correspondiente.
int ordenar(void*, void*) ; // Ordena dos variables de cualquier dato. Para Tickets, ordena por prioridad y hora.

#endif