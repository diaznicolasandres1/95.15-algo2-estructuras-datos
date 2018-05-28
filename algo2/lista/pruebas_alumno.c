#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include "lista.h"
#include "pila.h"



void manejo_lista_vacia(){
	printf("----INICIO PRUEBA LISTA VACIA ----\n");
	lista_t* lista = lista_crear();
	int uno = 1,dos=2;
	print_test("Se creo lista vacia",lista_esta_vacia(lista) == true);
	lista_iter_t* iter= lista_iter_crear(lista);
	print_test("ITER VER ACTUAL VACIO",lista_iter_ver_actual(iter) == NULL);
    lista_iter_destruir(iter);
	print_test("Borrar primero vacio",lista_borrar_primero(lista) == NULL);
	print_test("Ver primero vacio",lista_ver_primero(lista) ==NULL);
	print_test("Ver primero ultimo vacio",lista_ver_ultimo(lista) ==NULL);
	print_test("Largo lista vacia",lista_largo(lista) == 0);
	print_test("Borrar vacio",lista_borrar_primero(lista) == NULL );
	print_test("Insertar primero ", lista_insertar_primero(lista,&uno) == true);
	print_test("Insertar ultimo ", lista_insertar_ultimo(lista,&dos) == true);
	lista_destruir(lista,NULL);
	print_test("Destruir lista", true);
}
void utilizando_lista(){
	printf("----INICIO PRUEBA MANEJO DE LISTA  ----\n");
	lista_t* lista = lista_crear();	
	int uno =1,dos=2,tres=3,cuatro=4;
	print_test("Insertar primero ", lista_insertar_primero(lista,&uno) == true);
	print_test("Insertar ultimo", lista_insertar_ultimo(lista,&dos) == true);
	print_test("Insertar ultimo ", lista_insertar_ultimo(lista,&tres) == true);
	print_test("Insertar ultimo ", lista_insertar_ultimo(lista,&cuatro) == true);
	print_test("Ver primero ",lista_ver_primero(lista) == &uno);
	print_test("Ver ultimo ",lista_ver_ultimo(lista) == &cuatro);
	print_test("Borrar primero", lista_borrar_primero(lista) == &uno);
	print_test("Ver primero despues de borrar", lista_borrar_primero(lista) == &dos);
	print_test("Borrar hasta vacio", lista_borrar_primero(lista) == &tres);
	print_test("Borrar hasta vacio", lista_borrar_primero(lista) == &cuatro);
	print_test("Largo lista debe ser 0",lista_largo(lista) == 0);
	print_test("No se puede borrar vacio", lista_borrar_primero(lista) == NULL);
	print_test("Insertar NULL", lista_insertar_primero(lista,NULL) == true);
	print_test("Largo lista debe ser 1",lista_largo(lista) == 1);
	print_test("Ver primero debe devolver dato null",lista_ver_primero(lista) ==NULL);
	print_test("Borrar NULL", lista_borrar_primero(lista) == NULL);
	print_test("Largo lista debe ser 0",lista_largo(lista) == 0);
	lista_destruir(lista,NULL);
}

void pruebas_de_volumen(size_t tam){
	printf("----INICIO PRUEBAS DE VOLUMEN  ----\n");
	lista_t* lista = lista_crear();
	int array[tam];	
	printf("Insertamos primero 100 elementos\n");
	bool ok = true;
	for(size_t i =0;i<tam;i++){
		ok&= lista_insertar_ultimo(lista,&array[i]);
	}
	print_test("Se insertaron ultimos 100 elementos", ok);
	for(size_t i =0;i<tam;i++){
		ok&= lista_insertar_primero(lista,&array[i]);
	}	
	print_test("Se insertaron primeros 100 elementos", ok);
	for(size_t i = tam-1; i>0;i--){
		ok&= (&array[i]==lista_borrar_primero(lista));
	}
	ok&= (&array[0]==lista_borrar_primero(lista));
	print_test("Borro los insertados_primero", ok);
	for(size_t i =0; i<tam;i++){
		ok&= (&array[i]==lista_borrar_primero(lista));
	}
	print_test("Borro los insertados_ultimo", ok);

	print_test("Se borraron todos los elementos", lista_largo(lista) ==0);
	lista_destruir(lista, NULL);
}

void pruebas_null(){
	printf("----INICIO PRUEBA CON DATO NULL  ----\n");
	lista_t* lista = lista_crear();
	void* ptr = NULL;
	print_test("Insertar primero NULL", lista_insertar_primero(lista,ptr) == true);
	print_test("Insertar ultimo NULL ", lista_insertar_ultimo(lista,ptr) == true);
	print_test("Se destruyo correctamente", true);
	lista_destruir(lista,NULL);
	
}
void elemento_destruir_wrapper(void* elem){
	pila_destruir((pila_t*) elem);
}
void pruebas_destruir_wrapper(){	
	printf("----INICIO PRUEBA DESTRUIR CON WRAPPER (PILAS)  ----\n");
	printf("ENCOLANDO PILAS\n");
	int datos[]={1,2,3,4,5};
	pila_t* pila1 = pila_crear();
	pila_t* pila2 = pila_crear();
	pila_apilar(pila1,&datos[0]);
	pila_apilar(pila1,&datos[1]);
	pila_apilar(pila2,&datos[2]);
	pila_apilar(pila2,&datos[3]);
	lista_t* lista = lista_crear();
	print_test("Insertar pila",lista_insertar_ultimo(lista,pila1) == true);
	print_test("Insertar pila",lista_insertar_ultimo(lista,pila2) == true);
	print_test("Insertar pila",lista_insertar_ultimo(lista,pila1) == true);	
	print_test("Ver primera pila encolada",lista_ver_primero(lista) == pila1);
	print_test("Desencolar pila", lista_borrar_primero(lista) == pila1);
	lista_destruir(lista,elemento_destruir_wrapper);
	print_test("Se destruyo lista con wrapper", true);
}


bool visitar(void* dato, void* extra){	
    printf("%d-", *(int*) dato + *(int*) extra);
    return true;
}



void pruebas_iterador_interno(){
	printf("----INICIO PRUEBA ITERADOR INTERNO SIN CORTE  ----\n");
	int suma = 1;	lista_t* lista = lista_crear();	
	int cero=0;
	int uno =1,dos=2,tres=3,cuatro=4;
	lista_insertar_primero(lista,&uno);
	lista_insertar_ultimo(lista,&dos);
	lista_insertar_ultimo(lista,&tres);
	lista_insertar_ultimo(lista,&cuatro);
	printf("Debe imprimir 2-3-4-5 Resultado : ");	
	lista_iterar(lista,visitar,&suma);
	print_test("\nIterador funciona correctamente", true);	
	printf("Debe imprimir 1-2-3-4 Resultado : ");	
	lista_iterar(lista,visitar,&cero);
	print_test("\nIterador funciona correctamente", true);
	lista_destruir(lista,NULL);	
}


bool visitar_corte(void* dato, void* extra){
	if(*(int*) dato < 4){
    	printf("%d-", *(int*) dato + *(int*) extra);
    	return true;
    }else{
    	return false;
    }
}
void prueba_iterador_interno_corte(){
	printf("----INICIO PRUEBA ITERADOR INTERNO CON CORTE  ----\n");
	int suma =0;
	int suma2= 1;
	lista_t* lista = lista_crear();	
	int uno =1,dos=2,tres=3,cuatro=4;
	lista_insertar_primero(lista,&uno);
	lista_insertar_ultimo(lista,&dos);
	lista_insertar_ultimo(lista,&tres);
	lista_insertar_ultimo(lista,&cuatro);
	printf("Debe imprimir 1-2-3 Resultado : ");	
	lista_iterar(lista,visitar_corte,&suma);
	print_test("\nIterador funciona correctamente", true);	
	printf("Debe imprimir 2-3-4 Resultado : ");	
	lista_iterar(lista,visitar_corte,&suma2);
	print_test("\nIterador funciona correctamente", true);
	lista_destruir(lista,NULL);	


}

void pruebas_iter_externo(){
	printf("----INICIO PRUEBA ITERADOR EXTERNO ----\n");
	lista_t* lista = lista_crear();	
	int uno =1,dos=2,tres=3,cuatro=4,cinco=5,seis=6;
	lista_insertar_primero(lista,&uno);
	lista_insertar_ultimo(lista,&dos);
	lista_insertar_ultimo(lista,&tres);
	lista_insertar_ultimo(lista,&cuatro);
	lista_iter_t* iter =lista_iter_crear(lista);
	print_test("Insertar al crear", lista_iter_insertar(iter,&cinco) == true);
	print_test("Se inserto primero", lista_iter_ver_actual(iter) == &cinco);	
	print_test("Avanzo", lista_iter_avanzar(iter) == true);
	print_test("Avanzo", lista_iter_avanzar(iter) == true);
	print_test("Insertar elemento en el medio", lista_iter_insertar(iter,&seis) == true);
	print_test("Ver actual", lista_iter_ver_actual(iter) == &seis);
	print_test("Avanzo", lista_iter_avanzar(iter) == true);
	print_test("Avanzo", lista_iter_avanzar(iter) == true);
	print_test("Veo actual", lista_iter_ver_actual(iter) == &tres);
	print_test("Borro en el medio el tres", lista_iter_borrar(iter) == &tres);
	print_test("Avanzo", lista_iter_avanzar(iter) == true);	
	print_test("Llego al final", lista_iter_avanzar(iter) == false);
	print_test("Llego al final", lista_iter_al_final(iter) == true);
	print_test("Insertar al final", lista_iter_insertar(iter,&seis) == true);
	print_test("Ver actual al final", lista_iter_ver_actual(iter) == &seis);

	printf("TERMINE DE ITERAR VEO RESULTADOS EN LA LISTA\n");
	//(quedo con los valores 5-1-6-2-4-6)
	print_test("Ver final de la lista", lista_ver_ultimo(lista) == &seis);
	print_test("Ver primero de la lista", lista_ver_primero(lista) == &cinco);
	print_test("Borro y debe ser el cinco", lista_borrar_primero(lista) == &cinco);
	print_test("Borro y debe ser el uno", lista_borrar_primero(lista) == &uno);
	print_test("Borro y debe ser el seis", lista_borrar_primero(lista) == &seis);
	print_test("Borro y debe ser el dos", lista_borrar_primero(lista) == &dos);
	print_test("Borro y debe ser el cuatro", lista_borrar_primero(lista) == &cuatro);
	print_test("Borro y debe ser el seis", lista_borrar_primero(lista) == &seis);
	lista_iter_destruir(iter);	
	lista_destruir(lista, NULL);

}
void otros_casos_iter_ext(){
	printf("----INICIO PRUEBA REUTILIZACION LISTA ITERADOR EXTERNO  ----\n");
	lista_t* lista = lista_crear();		
	int uno =1,dos=2,tres=3,cuatro=4;
	lista_insertar_ultimo(lista,&uno);
	lista_insertar_ultimo(lista,&dos);
	lista_insertar_ultimo(lista,&tres);
	lista_insertar_ultimo(lista,&cuatro);
	lista_iter_t* iter =lista_iter_crear(lista);
	print_test("Borro hasta vacio", lista_iter_borrar(iter) == &uno);
	print_test("Borro hasta vacio", lista_iter_borrar(iter) == &dos);
	print_test("Borro hasta vacio", lista_iter_borrar(iter) == &tres);
	print_test("Borro hasta vacio", lista_iter_borrar(iter) == &cuatro);
	print_test("Inserto al quedar vacio", lista_iter_insertar(iter,&uno) ==true);
	print_test("Borro hasta vacio", lista_iter_borrar(iter) == &uno);
	print_test("Inserto al quedar vacio", lista_iter_insertar(iter,&uno) ==true);
	print_test("Ver primero", lista_iter_ver_actual(iter) == &uno);	
	print_test("Avanzo", lista_iter_avanzar(iter) == true);
	print_test("Llego al final", lista_iter_al_final(iter) == true);
	lista_iter_destruir(iter);	
	lista_destruir(lista, NULL);
}

void pruebas_lista_alumno(){
	manejo_lista_vacia();
	utilizando_lista();
	pruebas_de_volumen(2000);
	pruebas_null();
	pruebas_destruir_wrapper();
	printf("PRUEBAS DEL ITERADOR INTERNO\n");
	pruebas_iterador_interno();
	prueba_iterador_interno_corte();
	pruebas_iter_externo();
	otros_casos_iter_ext();
	
}
