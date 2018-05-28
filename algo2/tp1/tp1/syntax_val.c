#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include "pila.h"


char* quitar_salto_linea(char* linea){
	size_t largo = strlen(linea) - 1;
	if (linea[largo] == '\n') {
    	linea[largo] = '\0';
	}
	return linea;
}


bool caracter_apertura(char caracter){
	return (caracter == '{' || caracter == '(' || caracter == '[');
}
bool caracter_cerrado(char caracter){
	return (caracter == '}' || caracter == ')' || caracter == ']');
}



bool syntax_val(char* palabra){
	pila_t* pila = pila_crear();
	if(!pila){
		return false;
	}
	size_t tam_palabra = strlen(palabra);
	for(size_t i = 0; i < tam_palabra ; i++){
		if(caracter_apertura(palabra[i])){
			pila_apilar(pila,&palabra[i]);
		}
		else if(caracter_cerrado(palabra[i])){
			if(pila_esta_vacia(pila)){
				pila_destruir(pila);
				return false;
			}
			char desapilado = *(char*)pila_desapilar(pila);
			if(desapilado == '{' && palabra[i] != '}'){
				pila_destruir(pila);
				return false;
			}
			else if(desapilado == '[' && palabra[i] != ']'){
				pila_destruir(pila);
				return false;
			}
			else if(desapilado == '(' && palabra[i] != ')'){
				pila_destruir(pila);
				return false;
			}
		}
	}
	bool pila_vacia = pila_esta_vacia(pila);
	pila_destruir(pila);
	return pila_vacia;
}
 

bool aplicar(char* string){
	char** strv = split(string,  '\'');	
	size_t i  = 0;
	while(strv[i]){		
		i++;
	}

	if(i%2 == 0){
		free_strv(strv); //un arreglo valido tiene numero impar de elementos en strv		
		return false;
	}	
	char** nuevo = malloc(sizeof(char*)* ((i/2)+2));
	if(!nuevo){
		free_strv(strv);
		return false;
	}
	size_t cant= 0;
	/*elementos en posicion impar del arreglo se descartan*/
	for(int j=0 ; j < i ; j++){
		if(j%2 == 0){
			nuevo[cant] = strdup(strv[j]);			
			cant++;
		}
		nuevo[cant] = NULL;		
	}
	
	char* palabra = join(nuevo,';');
	bool resultado = syntax_val(palabra);
	free_strv(strv);
	free_strv(nuevo);
	free(palabra);
	return resultado;
	

}





int main(){


	char* linea = NULL;		
	size_t capacidad =0,leidos=0;
	bool resultado = false;
	while((leidos = getline(&linea,&capacidad,stdin)) !=-1){
		linea[leidos-1] = '\0';
		resultado = aplicar(linea);
		if(resultado){
			printf("OK\n");
		}else{
			printf("ERROR\n");
		}
	}
	free(linea);



	
	

	

}






