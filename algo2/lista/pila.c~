#include "pila.h"
#include <stdlib.h>
#include <stdio.h>
#define CAPACIDAD_INICIAL 5
#define VACIA 0

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if (pila == NULL) {
        return NULL;
    }    
    pila->datos = malloc(sizeof(void**)*CAPACIDAD_INICIAL);
    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }
    pila->capacidad = CAPACIDAD_INICIAL;
    pila->cantidad = VACIA;   
    return pila;
}

void pila_destruir(pila_t *pila){
	if(pila->datos != NULL){
		free(pila->datos);	
		free(pila);	
	}
}

bool duplicar_capacidad(pila_t* pila){
	void* datos_nuevo = realloc(pila->datos, (pila->capacidad *2 )*sizeof(void*));
	if (datos_nuevo == NULL)
		return false;
	pila->datos = datos_nuevo;
	pila->capacidad = (pila->capacidad * 2);
	return true;
}

bool pila_llena(pila_t* pila){
	return(pila->cantidad == pila->capacidad);
}


bool pila_esta_vacia(const pila_t *pila){
	return(pila->cantidad == VACIA);			
}

bool pila_apilar(pila_t *pila, void* valor){
	if(pila_llena(pila))
		duplicar_capacidad(pila);	
	pila->datos[pila->cantidad]= valor;	
	if(pila->datos[pila->cantidad] == valor){
		pila->cantidad = pila->cantidad + 1;						
		return true;		
	}else 
		return false;
}

void* pila_ver_tope(const pila_t *pila){
	if(pila_esta_vacia(pila))
		return NULL;
	return pila->datos[(pila->cantidad)-1];
}
bool capacidad_sin_uso(pila_t* pila){
	return ((pila->capacidad > (pila->cantidad)*4 )&& (pila->capacidad > CAPACIDAD_INICIAL));
}
void* pila_desapilar(pila_t *pila){
	pila_t* auxiliar = pila_ver_tope(pila);
	
	if(auxiliar == NULL && pila->cantidad ==0)
		return auxiliar;
	pila->cantidad = (pila->cantidad)-1;
	if(capacidad_sin_uso(pila))
		pila->capacidad = pila->capacidad/2;
	return auxiliar;
}




