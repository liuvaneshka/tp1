#include <iostream>
#include "historia.h"

using namespace std;

void imprimir_resultado(int *posiciones){

	if( posiciones == nullptr){

		cout << "No se encuentra esa frase en la historia indicada." << endl;
	}

	else{
		int len=sizeof(posiciones);
		cout << "tamanio " << len << endl;
		for(int i = 0; i <= 16; i++)
			cout << posiciones[i] << "-";
		/*
		int i = 0;
		int ultimo_elemento = -1;

		while(posiciones[i] != ultimo_elemento){
			cout << posiciones[i] << "-";
			i++;
		};
		*/

		cout << endl;
	}
}

void copiar_vector(int coincidencias, int * aux, int* &arreglo){

	for(int i =0; i <= coincidencias; i++){
		aux[i] = arreglo[i];
	}

	delete[]arreglo;
	arreglo = aux;

}

void almacenar_coincidencia(int &coincidencias, int* &arreglo, int posicion){

	if(coincidencias == 0){
		coincidencias++;
		arreglo = new int[coincidencias];
		arreglo[0] = posicion;
	}
	else{
		int* aux = new int[coincidencias + 1];
		copiar_vector(coincidencias, aux, arreglo);
		aux[coincidencias] = posicion;
		coincidencias++;
	}
}

int* buscar_frase(int cantidad_argumentos, char historia[], char frase[]){

	int tamanio_historia, tamanio_frase;
	tamanio_historia = (int)((string) historia).size();
	tamanio_frase = (int)((string) frase).size();
	int ultima_frase = tamanio_historia - tamanio_frase;
	int* arreglo = nullptr;
	int coincidencias = 0;
	int posicion = 0;

	if((tamanio_historia > tamanio_frase) && (cantidad_argumentos == 3) ){

		int j = 0;
		int caracter_validado = 0;

		for(int i = 0; i < tamanio_historia; i++){

			cout << " historia "<< historia[i] << " frase " << frase[j] << endl;

			if(((char)tolower(historia[i])) == ((char)tolower(frase[j]))){ 
				caracter_validado++;
				j++;
				if(tamanio_frase == caracter_validado){
					posicion = (i - j) + 1;
					almacenar_coincidencia(coincidencias, arreglo, posicion);
					j = 0;
				}
			}

			else{
				j = 0;
				caracter_validado = 0;
			}

			if( (i == ultima_frase) && (caracter_validado == 0) && ((char)tolower(historia[i])) != ((char)tolower(frase[j]))){ 
				i = tamanio_historia;
			}

		}
	}
	for(int i = 0; i <= coincidencias; i++)
		cout << arreglo[i] << "  ";
	cout << endl;

	return arreglo;
}
