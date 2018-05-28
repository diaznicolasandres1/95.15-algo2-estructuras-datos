#ifndef COLA_H
#define COLA_H

#include <stdbool.h>


/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La cola está planteada como una cola de punteros genéricos. */

struct cola;
typedef struct cola cola_t;


/* ******************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

// Crea una cola.
// Post: devuelve una nueva cola vacía.
cola_t* cola_crear(void);


void cola_destruir(cola_t *cola, void destruir_dato(void*));

bool cola_esta_vacia(const cola_t *cola);


bool cola_encolar(cola_t *cola, void* valor);


void* cola_ver_primero(const cola_t *cola);


void* cola_desencolar(cola_t *cola);




void pruebas_cola_alumno(void);

#endif // COLA_H
