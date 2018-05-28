#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include "cola.h"
#include "pila.h"
#include <stdlib.h>



void pruebas_cola_vacia(){
	printf("----INICIO PRUEBAS COLA VACIA----\n");
	cola_t* cola = cola_crear();
	print_test("Se creo una cola vacia",cola_esta_vacia(cola) == true);
	print_test("Ver primero debe ser NULL", cola_ver_primero(cola) == NULL);
	print_test("Desencolar es invalido", cola_desencolar(cola) == NULL);
	cola_destruir(cola,NULL);	
}

void pruebas_encolar_desencolar(){
	printf("----INICIO PRUEBAS ENCOLAR Y DESENCOLAR----\n");
	cola_t* cola = cola_crear();
	int elementos[] = {1,2,3,4,5};
	print_test("Se creo cola vacia",cola_esta_vacia(cola) == true);
	print_test("Encolar primer elemento ",cola_encolar(cola,&elementos[0]) == true);
	print_test("Ver primer elemento es correcto", cola_ver_primero(cola) == &elementos[0]);
	print_test("Encolar segundo elemento ",cola_encolar(cola,&elementos[1]) == true);
	print_test("Ver primer elemento es correcto", cola_ver_primero(cola) == &elementos[0]);
	print_test("Encolar tercer elemento ",cola_encolar(cola,&elementos[2]) == true);
	print_test("Encolar cuarto elemento ",cola_encolar(cola,&elementos[3]) == true);
	print_test("Encolar quinto elemento ",cola_encolar(cola,&elementos[4]) == true);
	print_test("Ver primer elemento es correcto (elemento 1)", cola_ver_primero(cola) == &elementos[0]);
	print_test("Desencolar es correcto (elemento 1)", cola_desencolar(cola) == &elementos[0]);
	print_test("Ver primer elemento es correcto(elemento 2)", cola_ver_primero(cola) == &elementos[1]);
	print_test("Desencolar es correcto (elemento 2)", cola_desencolar(cola) == &elementos[1]);
	print_test("Ver primer elemento es correcto(elemento 3)", cola_ver_primero(cola) == &elementos[2]);
	print_test("Desencolar es correcto (elemento 3)", cola_desencolar(cola) == &elementos[2]);
	print_test("Ver primer elemento es correcto(elemento 4)", cola_ver_primero(cola) == &elementos[3]);
	print_test("Desencolar es correcto (elemento 4)", cola_desencolar(cola) == &elementos[3]);
	print_test("Ver primer elemento es correcto(elemento 5)", cola_ver_primero(cola) == &elementos[4]);
	print_test("Desencolar es correcto (elemento 4)", cola_desencolar(cola) == &elementos[4]);
	print_test("La cola esta vacia",cola_esta_vacia(cola) == true);
	cola_destruir(cola,NULL);	
}

void reutilizar_cola(){
	printf("----INICIO PRUEBAS REUTILIZAR COLAR----\n");
	cola_t* cola = cola_crear();
	int elementos[] = {1,2};
	print_test("Se creo cola vacia",cola_esta_vacia(cola) == true);
	print_test("Encolar primer elemento ",cola_encolar(cola,&elementos[0]) == true);	
	print_test("Encolar segundo elemento ",cola_encolar(cola,&elementos[1]) == true);
	print_test("Desencolar es correcto (elemento 1)", cola_desencolar(cola) == &elementos[0]);
	print_test("Ver primer elemento es correcto(elemento 2)", cola_ver_primero(cola) == &elementos[1]);
	print_test("Desencolar es correcto (elemento 2)", cola_desencolar(cola) == &elementos[1]);
	print_test("Ver primero es invalido", cola_ver_primero(cola) == NULL);
	print_test("La cola esta vacia",cola_esta_vacia(cola) == true);
	print_test("Encolar primer elemento ",cola_encolar(cola,&elementos[0]) == true);	
	print_test("Encolar segundo elemento ",cola_encolar(cola,&elementos[1]) == true);
	print_test("Ver primer elemento es correcto", cola_ver_primero(cola) == &elementos[0]);
	print_test("Desencolar es correcto (elemento 1)", cola_desencolar(cola) == &elementos[0]);
	print_test("Ver primer elemento es correcto(elemento 2)", cola_ver_primero(cola) == &elementos[1]);
	print_test("Desencolar es correcto (elemento 2)", cola_desencolar(cola) == &elementos[1]);
	print_test("La cola esta vacia",cola_esta_vacia(cola) == true);
	cola_destruir(cola,NULL);	
}

void cola_destruir_memoria_dinamica(){
	printf("----INICIO PRUEBAS MEMORIA DINAMICA\n");
	int* valor_uno = malloc(sizeof(int));
	int* valor_dos = malloc(sizeof(int));
	int* valor_tres = malloc(sizeof(int));
	cola_t* cola = cola_crear();
	print_test("Encolar primer elemento ",cola_encolar(cola,valor_uno) == true);	
	print_test("Encolar segundo elemento ",cola_encolar(cola,valor_dos) == true);	
	print_test("Encolar tercer elemento ",cola_encolar(cola,valor_tres) == true);
	print_test("Ver primer elemento es correcto(elemento 1)", cola_ver_primero(cola) == valor_uno);	
	cola_destruir(cola,free);
	print_test("Se destruyeron los elementos encolados perder memoria",true);
}


void wrapper_destruir_pila(void* elem){
	pila_destruir((pila_t*)elem);
}
void encolar_estructuras(){
	printf("----INICIO PRUEBAS DESTRUIR CON ESTRUCTURAS\n");
	pila_t* pila_uno = pila_crear();
	pila_t* pila_dos = pila_crear();
	pila_t* pila_tres = pila_crear();
	cola_t* cola = cola_crear();
	print_test("Encolar primer pila ",cola_encolar(cola,pila_uno) == true);	
	print_test("Encolar segunda pila ",cola_encolar(cola,pila_dos) == true);
	print_test("Encolar tercer pila ",cola_encolar(cola,pila_tres) == true);
	print_test("Ver primer elemento es correcto(pila 1)", cola_ver_primero(cola) == pila_uno);	
	print_test("Desencolar primer elemento es correcto(pila 1)", cola_desencolar(cola) == pila_uno);
	print_test("Ver primer elemento es correcto(pila 2)", cola_ver_primero(cola) == pila_dos);
	cola_destruir(cola,wrapper_destruir_pila);
	pila_destruir(pila_uno);	
	print_test("Se destruyeron las estructuras encoladas sin perder memoria",true);
}

void pruebas_de_volumen(size_t tam){
	int elementos[tam];
	cola_t* cola = cola_crear();
	bool resultado_encolar = false;
	bool resultado_desencolar = true;
	bool resultado_ver_primero = true;
	size_t elementos_encolados = 0;
	for(size_t i = 0; i<tam;i++){
		resultado_encolar = cola_encolar(cola,&elementos[i]);
		elementos_encolados = i;
		if(resultado_encolar == false){			
			break;
		}
	}
	print_test("Se encolaron correctamente todos los elementos\n", resultado_encolar);

	for(size_t i=0;i<elementos_encolados;i++){		 
		if(!(cola_desencolar(cola) == &elementos[i])){
		 	resultado_desencolar = false;
		 	break;
		}
		if(!(cola_ver_primero(cola) == &elementos[i+1])){
			resultado_ver_primero = false;
			break;
		}
	}
	/*el ultimo lo desencolo afuera del for porque sino en cola_ver_primero de i+1 me voy fuera de rango*/
	print_test("Desencolar ultimo elemento es correcto", cola_desencolar(cola) == &elementos[tam-1]); 	
	print_test("Se desencolaron correctamente todos los elementos\n", resultado_desencolar);
	print_test("Se vieron correctamente los primeros elementos\n", resultado_ver_primero);
	print_test("Cola quedo vacia",cola_esta_vacia(cola) == true);
	cola_destruir(cola,NULL);
}
	

void pruebas_cola_alumno(void){
	pruebas_cola_vacia();
	pruebas_encolar_desencolar();
	reutilizar_cola();
	cola_destruir_memoria_dinamica();
	encolar_estructuras();
	pruebas_de_volumen(2000);

}
