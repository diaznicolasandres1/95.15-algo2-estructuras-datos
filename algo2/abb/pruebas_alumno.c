#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include "abb.h"
#include <stdlib.h>
#include <string.h>



//hacer un strcmp manual

void arbol_vacio(){
	printf("======PRUEBAS ARBOL VACIO======\n");
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Creo arbol vacio", arbol);
	print_test("Cantidad elementos debe ser 0", abb_cantidad(arbol)==0);
	print_test("Borrar vacio debe ser NULL",abb_borrar(arbol,"clave") == NULL );
	print_test("Obtener debe ser NULL", abb_obtener(arbol,"clave")==NULL);
	print_test("Pertenece deber ser NULL",abb_pertenece(arbol,"clave")==false );
	abb_destruir(arbol);
}
void guardar_pertenece_obtener(){
	printf("======PRUEBAS CON PERTENECE Y OBTENER======\n");
	int uno= 1;
	int dos =2;
	int tres =3;
	int veinte =20;
	char* clave1= "clave_uno";
	char* clave2= "clave_dos";
	char* clave3= "clave_tres";
	char* clave4= "clave_cuatro";
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Creo arbol vacio", arbol);
	print_test("Guardo clave_uno", abb_guardar(arbol,clave1,&uno));
	print_test("Cantidad elementos debe ser 1", abb_cantidad(arbol)==1);
	print_test("Obtener debe ser 1", abb_obtener(arbol,clave1)== &uno);
	print_test("Pertenece deber ser true",abb_pertenece(arbol,clave1)==true);

	print_test("Guardo clave_dos", abb_guardar(arbol,clave2,&dos));
	print_test("Cantidad elementos debe ser 2", abb_cantidad(arbol)==2);
	print_test("Obtener debe ser 2", abb_obtener(arbol,clave2)== &dos);
	print_test("Pertenece deber ser true",abb_pertenece(arbol,clave2)==true);

	print_test("Guardo clave_tres", abb_guardar(arbol,clave3,&veinte));
	print_test("Cantidad elementos debe ser 3", abb_cantidad(arbol)==3);
	print_test("Obtener debe ser 20", abb_obtener(arbol,clave3)== &veinte);
	print_test("Pertenece deber ser true",abb_pertenece(arbol,clave3)==true);

	print_test("Guardo clave_cuatro", abb_guardar(arbol,clave4,&tres));
	print_test("Cantidad elementos debe ser 4", abb_cantidad(arbol)==4);
	print_test("Obtener debe ser 20", abb_obtener(arbol,clave4)== &tres);
	print_test("Pertenece deber ser true",abb_pertenece(arbol,clave4)==true);
	abb_destruir(arbol);

}


void guardar_reemplazo(){
	printf("======PRUEBAS CON REEMPLAZO DE CLAVE======\n");
	int uno= 1;
	int dos =2;
	int tres =3;
	int veinte =20;
	char* clave1= "clave_uno";
	char* clave2= "clave_dos";	
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Guardo clave_uno con valor 1" , abb_guardar(arbol,clave1,&uno));
	print_test("Guardo clave_dos con valor 2", abb_guardar(arbol,clave2,&dos));
	print_test("Obtener clave_dos debe ser 2", abb_obtener(arbol,clave2)== &dos);

	print_test("Guardo clave_dos con valor 20", abb_guardar(arbol,clave2,&veinte));
	print_test("Obtener clave_dos debe ser nuevo valor", abb_obtener(arbol,clave2)== &veinte);

	print_test("Guardo clave_uno con valor 3r", abb_guardar(arbol,clave1,&tres));
	print_test("Obtener clave_dos debe ser valor 3", abb_obtener(arbol,clave1)== &tres);

	print_test("Pertenece clave_uno deber ser true",abb_pertenece(arbol,clave1)==true);
	print_test("Pertenece clave_dos deber ser true",abb_pertenece(arbol,clave2)==true);
	abb_destruir(arbol);
}
bool visitar_imprimir(const char* clave, void* dato,void* extra){
	printf("-/ %s - %s /-",clave,dato!=NULL?"True":"False");
	return true;
}
void pruebas_borrado_dos(){
	printf("=====PRUEBAS DE BORRADO 2=====\n");
	char* clave2= "2";
	char* clave4= "4";
	char* clave3= "3";
	char* clave5= "5"; 
	char* clave7 = "7";
	char* clave6 = "6";
	char* clave8 = "8";
	char* clave9 = "9";	

	int dos= 2;
	int cuatro =4;
	int tres =3;
	int cinco =5;
	int siete =7;
	int seis =6;
	int ocho = 8;
	int nueve = 9;
	
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Guardo clave5", abb_guardar(arbol,clave5,&cinco));
	print_test("Guardo clave3", abb_guardar(arbol,clave3,&tres));
	print_test("Guardo clave7", abb_guardar(arbol,clave7,&siete));
	print_test("Guardo clave2", abb_guardar(arbol,clave2,&dos));	
	print_test("Guardo clave4", abb_guardar(arbol,clave4,&cuatro));			
	print_test("Guardo clave6 ",abb_guardar(arbol,clave6,&seis));	
	print_test("Guardo clave8", abb_guardar(arbol,clave8,&ocho));	
	print_test("Guardo clave9", abb_guardar(arbol,clave9,&nueve));
	
	abb_in_order(arbol,visitar_imprimir,NULL);
	print_test("Borrar clave 8",abb_borrar(arbol,clave8)==&ocho);
	print_test("Borrar clave2",abb_borrar(arbol,clave2)==&dos);
	print_test("Borrar clave5",abb_borrar(arbol,clave5)==&cinco);
	print_test("Borrar clave3",abb_borrar(arbol,clave3)==&tres);
	print_test("Borrar clave4",abb_borrar(arbol,clave4)==&cuatro);
	print_test("Borrar clave9",abb_borrar(arbol,clave9)==&nueve);	
	print_test("Borrar clave7",abb_borrar(arbol,clave7)==&siete);
	print_test("Borrar clave6",abb_borrar(arbol,clave6)==&seis);	
	abb_in_order(arbol,visitar_imprimir,NULL);
	
	print_test("No debe pertenecer clave2",abb_pertenece(arbol,clave2)==false);
	print_test("No debe pertenecer clave4",abb_pertenece(arbol,clave4)==false);
	print_test("No debe pertenecer clave3",abb_pertenece(arbol,clave3)==false);
	print_test("No debe pertenecer clave5",abb_pertenece(arbol,clave5)==false);
	print_test("No debe pertenecer clave7",abb_pertenece(arbol,clave7)==false);
	print_test("No debe pertenecer clave6",abb_pertenece(arbol,clave6)==false);
	print_test("No debe pertenecer clave8",abb_pertenece(arbol,clave8)==false);

	print_test("Cantidad de elementos debe ser 0", abb_cantidad(arbol)==0);
	
	abb_destruir(arbol);



}
void borrado_3(void){
	printf("===============Pruebas de borrado 3 (simula las del script)=================\n");
	char* clave1 = "1";
	char* clave2 = "2";
	char* clave4 = "4";
	char* clave3 = "3";
	char* clave5 = "5";
	
	int uno = 1;
	int dos = 2;
	int cuatro = 4;
	int tres = 3;
	int cinco = 5;
	
	abb_t* arbol = abb_crear(strcmp,NULL);
	abb_guardar(arbol,clave1,&uno);
	abb_guardar(arbol,clave2,&dos);
	abb_guardar(arbol,clave4,&cuatro);
	abb_guardar(arbol,clave3,&tres);
	abb_guardar(arbol,clave5,&cinco);
	
	print_test("Borrar clave 1",abb_borrar(arbol,clave1)==&uno);
	abb_in_order(arbol,visitar_imprimir,NULL);
	print_test("Borrar clave 2",abb_borrar(arbol,clave2)==&dos);
	abb_in_order(arbol,visitar_imprimir,NULL);
	print_test("Borrar clave 4",abb_borrar(arbol,clave4)==&cuatro);
	abb_in_order(arbol,visitar_imprimir,NULL);
	print_test("Borrar clave 3",abb_borrar(arbol,clave3)==&tres);
	abb_in_order(arbol,visitar_imprimir,NULL);
	print_test("Borrar clave 5",abb_borrar(arbol,clave5)==&cinco);
	abb_in_order(arbol,visitar_imprimir,NULL);
	
	abb_destruir(arbol);
	
}
void borrar_elementos(){
	printf("======PRUEBAS DEL BORRADO======\n");
	int uno= 1;
	int dos =2;
	int tres =3;
	int veinte =20;
	char* clave1= "clarga";
	char* clave2= "perooooo";
	char* clave3= "abecedefghijklomnopers";
	char* clave4= "probandooooooclavemuylarga";
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Creo arbol vacio", arbol);
	print_test("Guardo clave_uno", abb_guardar(arbol,clave1,&uno));	
	print_test("Guardo clave_dos", abb_guardar(arbol,clave2,&dos));	
	print_test("Guardo clave_tres", abb_guardar(arbol,clave3,&veinte));
	print_test("Guardo clave_cuatro", abb_guardar(arbol,clave4,&tres));

	print_test("Cantidad elementos debe ser 4", abb_cantidad(arbol)==4);

	print_test("Borrar clave_dos",abb_borrar(arbol,clave2)==&dos);
	print_test("Cantidad elementos debe ser 3", abb_cantidad(arbol)==3);	

	print_test("Borrar clave_tres",abb_borrar(arbol,clave3)==&veinte);
	print_test("Cantidad elementos debe ser 2", abb_cantidad(arbol)==2);

	print_test("Borrar clave_cuatro",abb_borrar(arbol,clave4)==&tres);
	print_test("Cantidad elementos debe ser 1", abb_cantidad(arbol)==1);
	print_test("Pertenece clave_cuatro deber ser false",abb_pertenece(arbol,clave4)==false);	

	print_test("Borrar clave_uno",abb_borrar(arbol,clave1)==&uno);
	print_test("Cantidad elementos debe ser 0",abb_cantidad(arbol)==0);
	print_test("Pertenece clave_uno deber ser false",abb_pertenece(arbol,clave1)==false);

	print_test("Guardo luego de llegar a vacio clave_uno", abb_guardar(arbol,clave1,&uno));	
	print_test("Pertenece clave_uno deber ser true",abb_pertenece(arbol,clave1)==true);
	print_test("Cantidad elementos debe ser 1",abb_cantidad(arbol)==1);

	abb_destruir(arbol);
	
}

void guardar_null(){
	printf("======PRUEBAS GUARDAR NULL======\n");
	abb_t* arbol = abb_crear(strcmp,NULL);
	char* clave = "guardar_null";
	char* dato= NULL;
	print_test("Guardo NULL", abb_guardar(arbol,clave,dato));	
	print_test("Cantidad elementos debe ser 1",abb_cantidad(arbol)==1);
	print_test("Pertenece clave guardar_null deber ser true",abb_pertenece(arbol,clave)==true);
	print_test("Obtener debe ser NULL",abb_obtener(arbol,clave)==dato);
	print_test("Borrar clave guardar_null",abb_borrar(arbol,clave)==dato);
	print_test("Cantidad elementos debe ser 0",abb_cantidad(arbol)==0);
	abb_destruir(arbol);
}

void pruebas_clave_vacia(){
	printf("======INICIO PRUEBAS CLAVE VACIA======\n");
	abb_t* arbol = abb_crear(strcmp,NULL);
	char* clave ="";
	int dato =1;
	print_test("Guardo clave vacia", abb_guardar(arbol,clave,&dato));
	print_test("Cantidad elementos debe ser 1",abb_cantidad(arbol)==1);
	print_test("Pertenece clave vacial deber ser true",abb_pertenece(arbol,clave)==true);
	print_test("Obtener debe ser uno",abb_obtener(arbol,clave)==&dato);
	print_test("Borrar clave vacia",abb_borrar(arbol,clave)==&dato);
	print_test("Cantidad elementos debe ser 0",abb_cantidad(arbol)==0);		
	abb_destruir(arbol);
}


void pruebas_volumen(size_t tam){
	bool almacenado = true;
	bool pertenece = true;
	bool borrado = true;
	bool obtener = true;
	
	printf("=====INICIO PRUEBAS VOLUMEN=====\n");
	abb_t* arbol = abb_crear(strcmp,free);	
	size_t largo_clave = 10;
	char (*claves)[largo_clave] = malloc(tam * largo_clave);
	unsigned* valores[tam];
	
	for(unsigned i = 0 ; i<tam;i++){
		valores[i] = malloc(sizeof(int)); //valores dinamicos
		sprintf(claves[i], "%08d",i); //transforma int en string
		almacenado = abb_guardar(arbol,claves[i],valores[i]);
		*valores[i] = i;
		if(!almacenado)
			break;
	}
	//pruebas de almacenado
	if(almacenado){
		print_test("Almacenamos muchos datos correctamente",almacenado);
		print_test("Se almaceno cantidad correcta de datos",abb_cantidad(arbol)==tam);
	}
	//pruebas de pertenece 
	for(size_t i = 0 ; i<tam;i++){
		pertenece = abb_pertenece(arbol,claves[i]);
		if(!pertenece)
			break;
		obtener= abb_obtener(arbol,claves[i]);
		if(!obtener)

			break;
	}
	if(obtener)
		print_test("Prueba de obtener muchos elementos es correcta",obtener);
	if(pertenece)
		print_test("Prueba de pertenece muchos elementos es correcta",pertenece);

	//pruebas borrado


	for(size_t i = 0 ; i<tam;i++){
		borrado = abb_borrar(arbol,claves[i])== valores[i];		
		if(!borrado)
			break;
	}
	if(borrado){
		print_test("Se borraron muchos elementos correctamente",borrado);
		print_test("la cantidad de elementos debe ser 0",abb_cantidad(arbol)==0);
	}	
	
	abb_destruir(arbol);
	for(size_t i = 0; i<tam;i++){		
		free(valores[i]);
	}
	free(claves);
	

	
}


void pruebas_iter_externo(void){
	printf("=====PRUEBAS DE iter ext=====\n");
	char* clave1= "a";
	char* clave2= "b";
	char* clave3= "c";
	char* clave4= "d"; 
	char* clave5 = "e";
	char* clave6 = "f";
	char* clave7 = "g";
	char* clave8= "h";
	char* clave9= "i";
	
	char* dato= "dato";
	abb_t* arbol = abb_crear(strcmp,NULL);
	print_test("Guardo clave", abb_guardar(arbol,clave1,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave2,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave3,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave4,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave5,dato));	
	print_test("Guardo clave ",abb_guardar(arbol,clave6,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave7,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave8,dato));	
	print_test("Guardo clave", abb_guardar(arbol,clave9,dato));	

	abb_iter_t* iter = abb_iter_in_crear(arbol);
	print_test("El iter se creo correctamente: ",iter!= NULL);
	print_test("Ver actual == A: ",strcmp(abb_iter_in_ver_actual(iter),"a")==0);
	print_test("Avanzar correcto: ",abb_iter_in_avanzar(iter));
	print_test("Ver actual == B: ",strcmp(abb_iter_in_ver_actual(iter),"b")==0);
	print_test("El iter esta al final falso: ",abb_iter_in_al_final(iter)== false);
	print_test("Avanzar correcto: ",abb_iter_in_avanzar(iter));
	print_test("Ver Actual == C: ",strcmp(abb_iter_in_ver_actual(iter),"c")==0);
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Actual == D: ",strcmp(abb_iter_in_ver_actual(iter),"d")==0);
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Actual == E: ",strcmp(abb_iter_in_ver_actual(iter),"e")==0);
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("El iter esta al final falso: ",abb_iter_in_al_final(iter)==false);
	print_test("Actual == F: ",strcmp(abb_iter_in_ver_actual(iter),"f")==0);
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Actual == G: ",strcmp(abb_iter_in_ver_actual(iter),"g")==0);
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Actual == H: ",strcmp(abb_iter_in_ver_actual(iter),"h")==0);	
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Actual == I: ",strcmp(abb_iter_in_ver_actual(iter),"i")==0);
	
	print_test("El iter esta al final falso: ",abb_iter_in_al_final(iter)==false);	
	print_test("Avanzar: ",abb_iter_in_avanzar(iter));
	print_test("Avanzar otra vez falso porque esta al final: ",abb_iter_in_avanzar(iter)==false);
	print_test("El iter esta al final ok: ",abb_iter_in_al_final(iter));
	abb_iter_in_destruir(iter);
	
	abb_destruir(arbol);
	
	
	
}

	
void borrar_hoja(){
	printf("===BORRAR HOJA===\n");
	abb_t* arbol = abb_crear(strcmp,NULL);
	char* clave= "clave";
	char* dato = "dato";
	print_test("Guardo hoja", abb_guardar(arbol,clave,dato));
	print_test("Borrar clave hoja",abb_borrar(arbol,clave)==dato);
	abb_destruir(arbol);
}

void pruebas_destruir(){
	printf("=====PRUEBAS CON DESTRUIR FREE=====\n");
	abb_t* arbol = abb_crear(strcmp,free);
	char* clave_uno = "clave uno";
	char* clave_dos = "clave dos";
	char* clave_tres = "clave tres";
	char* valor_uno;
	char* valor_dos;
	char* valor_tres;

	valor_uno= malloc(15* sizeof(char));
	valor_dos=malloc(15* sizeof(char));
	valor_tres=malloc(15* sizeof(char));
	print_test("Prueba guardado dinamico",abb_guardar(arbol,clave_uno,valor_uno));
	print_test("Obtener dato dinamico",abb_obtener(arbol,clave_uno)==valor_uno);
	print_test("Prueba pertenece es true", abb_pertenece(arbol,clave_uno)==true);
	print_test("Cantidad de elemenos = 1",abb_cantidad(arbol)==1);

	print_test("Prueba guardado dinamico",abb_guardar(arbol,clave_dos,valor_dos));
	print_test("Obtener dato dinamico",abb_obtener(arbol,clave_dos)==valor_dos);
	print_test("Prueba pertenece es true", abb_pertenece(arbol,clave_dos)==true);
	print_test("Cantidad de elemenos = 2",abb_cantidad(arbol)==2);

	print_test("Prueba guardado dinamico",abb_guardar(arbol,clave_tres,valor_tres));
	print_test("Obtener dato dinamico",abb_obtener(arbol,clave_tres)==valor_tres);
	print_test("Prueba pertenece es true", abb_pertenece(arbol,clave_tres)==true);
	print_test("Cantidad de elemenos = 3",abb_cantidad(arbol)==3);

	abb_destruir(arbol);


}
void pruebas_iter_ext_abb_vacio(void){
	printf("========== Pruebas iter con arbol vacio============\n");
	abb_t* arbol = abb_crear(strcmp,free);
	if(!arbol)
		return;
	abb_iter_t* iter = abb_iter_in_crear(arbol);
	
	print_test("Iter creado correctamente: ",iter);	
	print_test("Iter al final: ",abb_iter_in_al_final(iter));	
	print_test("Iter avanzar false: ",!abb_iter_in_avanzar(iter));		
	print_test("Iter ver actual == NULL: ",abb_iter_in_ver_actual(iter)== NULL);
	abb_iter_in_destruir(iter);
	abb_destruir(arbol);
		
}


void pruebas_abb_alumno(){
	
	arbol_vacio();
	guardar_pertenece_obtener();
	guardar_reemplazo();
	borrar_elementos(); 
	guardar_null();
	pruebas_destruir();		
	pruebas_clave_vacia();
	borrar_hoja();
	pruebas_borrado_dos();
	pruebas_volumen(50);	
	pruebas_iter_externo();
	pruebas_iter_ext_abb_vacio();
	
	

	}


