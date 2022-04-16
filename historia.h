#ifndef HISTORIA_H_INCLUDED
#define HISTORIA_H_INCLUDED

void copiar_vector(int coincidencias, int * aux, int * &arreglo);


void almacenar_coincidencia(int &coincidencias, int * &arreglo, int posicion);

/*
	PRE: recibe un puntero de enteros represetando la direccion de las posiciones
		donde hubo coincidencia, y un entero que representa el numero de 
		coincidencias que totales en la historia
	POST:
*/
void imprimir_resultado(int *posiciones);

/*
	PRE: recibe dos enteros, uno representa el tamanio de la historia
		otro representando el tamanio de la frase
		recibe dos cadenas, una es las historia, el segundo la frase a buscar
	POST: recorre la historia comparandola con el primer caracter de la frase 
		llama a la funcion imprimir resultado
*/
int* buscar_frase(int cantidad_argumentos, char historia[], char frase[]);

#endif