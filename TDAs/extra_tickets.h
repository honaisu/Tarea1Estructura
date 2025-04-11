#ifndef EXTRA_TICKETS_H
#define EXTRA_TICKETS_H
#include "list.h"
#include "tickets.h"

//*** Header con funciones varias. Enfocadas a los otros usos ***//

// Pertenecientes al main

// Muestra el menú de las opciones del programa.
void mostrarMenuPrincipal() ; 
// Espera a que el usuario ingrese ENTER para continuar.
void esperarEnter() ; 

// Pertenecientes al tickets

// Recorre una lista hasta encontrar cierto ID
int IDenLista(int, List*) ; 
// Verifica si es que la lista se encuentra vacía o no. Devuelve 1 si está vacía, y 0 si no.
int listaEstaVacia(List*) ; 
// Asigna un string con el tiempo actual del sistema.
void asignarTiempo(char*) ; 
// Imprime separadores. La primer variable siendo el separador, y la segunda el mensaje.
void imprimirSeparador(char*, char*) ; 
// Imprime los datos del ticket correspondiente.
void imprimirTicket(tipoTicket*) ; 
// Ordena dos variables de cualquier dato. Para Tickets, ordena por prioridad y hora.
int ordenar(void*, void*) ; 

#endif