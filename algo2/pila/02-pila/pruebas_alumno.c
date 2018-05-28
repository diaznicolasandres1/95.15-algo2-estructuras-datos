#include "pila.h"
#include "testing.h"
#include <stddef.h>

#include <stdio.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void crear_destruir_pila(){
	printf("-----INICIO DE PRUEBAS CONSTRUIR Y DESTRUIR -----\n");
	pila_t* pila = pila_crear();
	print_test("Crear pila vacia",pila_esta_vacia(pila) == true);
	pila_destruir(pila);
	print_test("Se destuyo la pila", true);
	
}
void pruebas_pila_vacia(){
	printf("-----INICIO DE PRUEBAS CON PILA VACIA-----\n");
    pila_t* pila = pila_crear();
    print_test("Tope debe ser vacio",pila_ver_tope(pila) == NULL);   
    print_test("Desapilar vacio debe ser NULL",pila_desapilar(pila) == NULL); 
    print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true);  
    pila_destruir(pila);
  
}

void apilar_desapilar(){
	printf("----INICIO PRUEBAS APILAR Y DESAPILAR----\n");
	pila_t* pila = pila_crear();
	int arreglo[] = {0,1,2,3};

	print_test("Apilamos 0", pila_apilar(pila,&arreglo[0]) == true);
	print_test("Tope correcto",pila_ver_tope(pila) == &arreglo[0]);

	print_test("Apilamos 1", pila_apilar(pila,&arreglo[1]) == true);
	print_test("Tope debe ser 1",pila_ver_tope(pila) == &arreglo[1]);

	print_test("Apilamos 2", pila_apilar(pila,&arreglo[2]) == true);
	print_test("Tope debe ser 2",pila_ver_tope(pila) == &arreglo[2]);

	print_test("Desapilamos debe ser valor 2", pila_desapilar(pila) == &arreglo[2]);
	print_test("Tope debe ser 1",pila_ver_tope(pila) == &arreglo[1]);

	print_test("Apilamos 2", pila_apilar(pila,&arreglo[2]) == true);
	print_test("Tope debe ser 2",pila_ver_tope(pila) == &arreglo[2]);

	print_test("Apilamos 3", pila_apilar(pila,&arreglo[3]) == true);
	print_test("Tope debe ser 3",pila_ver_tope(pila) == &arreglo[3]);

	print_test("Desapilamos debe ser valor 3", pila_desapilar(pila) == &arreglo[3]);
	print_test("Tope debe ser 2",pila_ver_tope(pila) == &arreglo[2]);

	print_test("Desapilamos debe ser valor 2", pila_desapilar(pila) == &arreglo[2]);
	print_test("Tope debe ser 1",pila_ver_tope(pila) == &arreglo[1]);

	print_test("Desapilamos debe ser valor 1", pila_desapilar(pila) == &arreglo[1]);
	print_test("Tope debe ser 0",pila_ver_tope(pila) == &arreglo[0]);

	print_test("Desapilamos debe ser valor 0", pila_desapilar(pila) == &arreglo[0]);	
	print_test("Tope debe ser vacio",pila_ver_tope(pila) == NULL);
	print_test("La pila esta vacia",pila_esta_vacia(pila) == true);
	pila_destruir(pila);
}


void apilar_desapilar_volumen(size_t tam){
	bool resultado_apilar =false;
	bool resultado_desapilar =false;
	printf("----INICIO PRUEBAS APILAR DESAPILAR VOLUMEN----\n");
	pila_t* pila = pila_crear();
	int arreglo[tam]; //Creo arreglo [0,1....tam-1]
	
	for(size_t i = 0; i < tam; i++){		
		if(pila_apilar(pila,&arreglo[i]) == true){			
			if(pila_ver_tope(pila) == &arreglo[i]){
				resultado_apilar = true;
			}
		}else{
			resultado_apilar = false;
			break;
		}		
	}	
	print_test("Se apilaron correctamente", resultado_apilar);
	for(size_t i = tam-1; i >0; i--){
		
		if(pila_desapilar(pila) == &arreglo[i]){			
			if(pila_ver_tope(pila) == &arreglo[i-1]){
				resultado_desapilar = true;
			}
		}else{
			resultado_desapilar = false;
			break;
		}		
	}	
	print_test("Se desapilaron correctamente", resultado_desapilar);	
	print_test("Desapilar ultimo elemento", pila_desapilar(pila) == &arreglo[0]);
	print_test("Tope debe ser vacio",pila_ver_tope(pila) == NULL );   
    print_test("Desapilar vacio debe ser NULL",pila_desapilar(pila) == NULL); 
    print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true );   

	pila_destruir(pila);
	
}

void pruebas_null(){
	printf("----INICIO PRUEBAS CON NULL----\n");
	pila_t* pila = pila_crear();
	int* nulo = NULL;
	print_test("Apilar NULL", pila_apilar(pila,&nulo) == true);
	print_test("Tope debe ser NULL",pila_ver_tope(pila) == &nulo);
	print_test("La pila no debe estar vacia",pila_esta_vacia(pila) == false);
	print_test("Desapilar debe ser NULL",pila_desapilar(pila) == &nulo);
	print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true); 
	pila_destruir(pila);

}

void condiciones_borde(){
	printf("----INICIO PRUEBAS CONDICIONES BORDE----\n");
	pila_t* pila = pila_crear();
	print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true); 
	char a = 'a';
	char b = 'b';
	char c= 'c';
	print_test("Apilar a", pila_apilar(pila,&a) == true);
	print_test("Apilar b", pila_apilar(pila,&b) == true);
	print_test("Apilar c", pila_apilar(pila,&c) == true);
	print_test("La pila no debe estar vacia",pila_esta_vacia(pila) == false); 
	print_test("Desapilar c",pila_desapilar(pila) == &c);
	print_test("Desapilar b",pila_desapilar(pila) == &b);
	print_test("Desapilar a",pila_desapilar(pila) == &a);
	print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true); 
	print_test("Tope debe ser vacio",pila_ver_tope(pila) == NULL );   
    print_test("Desapilar vacio debe ser NULL",pila_desapilar(pila) == NULL);   
    pila_destruir(pila);    
}

void vaciar_reutilizar(){
	printf("----INICIO PRUEBAS VACIAR Y LUEGO REUTILIZAR----\n");
	pila_t* pila = pila_crear();
	char a = 'a';
	char b= 'b';
	print_test("Apilar a", pila_apilar(pila,&a) == true);
	print_test("Desapilar a",pila_desapilar(pila) == &a);
	print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true);
	print_test("Apilar b", pila_apilar(pila,&b) == true);
	print_test("Desapilar b",pila_desapilar(pila) == &b);
	print_test("La pila debe estar vacia",pila_esta_vacia(pila) == true);
	print_test("Tope debe ser vacio",pila_ver_tope(pila) == NULL );   
    print_test("Desapilar vacio debe ser NULL",pila_desapilar(pila) == NULL);  
    pila_destruir(pila);
}




void pruebas_pila_alumno() {
	crear_destruir_pila();
	pruebas_pila_vacia();
	vaciar_reutilizar();
	apilar_desapilar();
	apilar_desapilar_volumen(2000);
	pruebas_null();
	condiciones_borde();
	

	printf("----FIN DE PRUEBAS----\n");
  
}
