#ifndef PILA_H
#define PILA_H

#include <stdbool.h>


/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* Se trata de una pila que contiene datos de tipo void*
 * (punteros genéricos).  La pila en sí está definida en el .c.  */

struct pila;  // Definición completa en pila.c.
typedef struct pila pila_t;


/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// Crea una pila.
// Post: devuelve una nueva pila vacía.
pila_t* pila_crear(void);

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila);

// Devuelve verdadero o falso, según si la pila tiene o no elementos apilados.
// Pre: la pila fue creada.
bool pila_esta_vacia(const pila_t *pila);

// Agrega un nuevo elemento a la pila. Devuelve falso en caso de error.
// Pre: la pila fue creada.
// Post: se agregó un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor);

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si está vacía devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolvió el valor del tope de la pila, cuando la pila no está
// vacía, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila);

// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila está vacía, devuelve
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vacía, se devuelve el valor del tope anterior
// y la pila contiene un elemento menos.
void* pila_desapilar(pila_t *pila);


/* *****************************************************************
 *                    PRUEBAS PARA LA PILA
 * *****************************************************************/

// Realiza pruebas sobre la implementación de la pila del alumno.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_alumno.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en pila.h
// (esto es, las pruebas no pueden acceder a los miembros del struct pila).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_pila_alumno(void);

#endif // PILA_H


void crear_destruir_pila(){
	pila_t* pila = pila_crear();
	print_test("Crear pila vacia",pila_esta_vacia(pila) == true);
	pila_destruir(pila);
	print_test("Se destuyo la pila", true);
}
void pruebas_pila_vacia(){
	printf("-----INICIO DE PRUEBAS CON PILA VACIA-----\n");
    pila_t* pila = pila_crear();
    print_test("Tope debe ser NULL",pila_ver_tope(pila) == NULL );   
    print_test("Desapilar vacio debe ser NULL",pila_desapilar(pila) == NULL); 
    print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true );  
    pila_destruir(pila);
}


void apilar_desapilar_for(){
	pila_t* pila = pila_crear();
	int arreglo[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	for(int i = 0; i < 19; i++){
		print_test("Apilar elemento", pila_apilar(pila,&arreglo[i]) == true);
		print_test("Tope correcto",pila_ver_tope(pila) == &arreglo[i]);
	}
	for(int i = 0; i < 19; i++){
		print_test("Desapilar elemento", pila_desapilar(pila,&arreglo[i]) == true);
		print_test("Tope correcto",pila_ver_tope(pila) == &arreglo[i]);
	}
}




