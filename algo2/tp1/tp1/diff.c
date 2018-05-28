#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* quitar_salto_linea(char* linea){
	size_t largo = strlen(linea) - 1;
	if (linea[largo] == '\n') {
    	linea[largo] = '\0';
	}
	return linea;
}
void diff(FILE* arch1, FILE* arch2){	
	char* linea_uno=NULL;
	char* linea_dos = NULL;		
	size_t capacidad_uno =0,leidos_uno=0,capacidad_dos =0,leidos_dos=0;
	size_t contador = 1;
	leidos_uno = getline(&linea_uno,&capacidad_uno,arch1);	
	leidos_dos = getline(&linea_dos,&capacidad_dos,arch2);
 	while((leidos_uno != -1) || (leidos_dos != -1)){ 		
 		if(leidos_uno == -1){
 			linea_uno = strcpy(linea_uno, "\n");
 		}
 		if(leidos_dos == -1){
 			linea_dos = strcpy(linea_dos,"\n");
 		}
 		if(strcmp(linea_uno,linea_dos) != 0){
 			printf("Diferencia en linea %lu\n",contador);
 			printf("< %s\n", quitar_salto_linea(linea_uno));
 			printf("---\n");
 			printf("> %s\n", quitar_salto_linea(linea_dos));
 		} 		
 		leidos_uno = getline(&linea_uno,&capacidad_uno,arch1); 		
		leidos_dos = getline(&linea_dos,&capacidad_dos,arch2);
 		contador++;
	}
	free(linea_uno);
	free(linea_dos);
}


int main(int argc, char* argv[]){
	if(argc != 3){
		fprintf(stderr,"Cantidad de parametros erronea\n");
		return 0;
	} 
	FILE* arch1 = fopen(argv[1],"r");
	if(!arch1 ){
		fprintf(stderr,"Archivo erroneo");		
		return 0;
	}
	FILE* arch2 = fopen(argv[2],"r");
	if(!arch2){
		fprintf(stderr,"Archivo erroneo");
		fclose(arch1);		
		return 0;
	}	
	diff(arch1,arch2);
	fclose(arch1);
	fclose(arch2);

}
