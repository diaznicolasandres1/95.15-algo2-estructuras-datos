#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
/* tail imprime las últimas N lineas de un archivo, o de entrada estándar. */


void tail(size_t n){	
	lista_t* lista = lista_crear();
	char* linea = NULL;		
	size_t capacidad =0,leidos=0;
	for(size_t i=0; i<n;i++){
		leidos = getline(&linea,&capacidad,stdin);
		if(leidos != -1){			
			linea[leidos-1] = '\0';			
			char* auxiliar = strdup(linea);			
			lista_insertar_ultimo(lista,auxiliar);				
		}		
	}	
	while((leidos = getline(&linea,&capacidad,stdin)) !=-1){			
		free(lista_borrar_primero(lista));
		linea[leidos-1] = '\0';	
		char* auxiliar = strdup(linea);		
		lista_insertar_ultimo(lista,auxiliar);		
	}
	free(linea);
	while(!lista_esta_vacia(lista)){
		char* palabra= (char*)lista_borrar_primero(lista);		
		printf("%s\n",palabra);
		free(palabra);
	}	
	lista_destruir(lista,NULL);
}

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr,"Cantidad de parametros erronea \n");
		return 0;
	}
	int n = atoi(argv[1]);
	if(n == 0){
		fprintf(stderr,"Tipo de parametro incorrecto \n");
		return 0;
	}
	tail(n);
	return 0;
}
