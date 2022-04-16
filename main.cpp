#include <iostream>
#include "historia.h"

using namespace std;

int main(int argc, char* argv[]){

	int cantidad_argumentos = argc;
	char* historia = argv[1];
	char* frase = argv[2];

	int* vector_resultante = buscar_frase(cantidad_argumentos, historia, frase);
	//imprimir_resultado(vector_resultante);
	delete[]vector_resultante;
	vector_resultante = nullptr;
	
	return 0;
}
