//
//  main.cpp
//  PartiturasMusicos
//
//  Grupo03 Salvador González Álvarez
//

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es MLog M + KLog M, donde M es el numero
// de grupos de musicos existentes, y K es el numero de partituras;



//REPARTIR LAS PARTITURAS DE MANERA QUE MUSICOS/PARTITURA
//ES EL NUM DE MUSICOS MAX
//REPARTIR EN ORDEN DE MAYOR NUMERO DE MUSICOS A MENOR UNA PARTITURA POR CADA VUELTA
//NUMPARTITURAS-NUMGRUPOS PARTITURAS DE MÁS QUE PUEDO REPARTIR

class solucion{

private:
	int personas;
	int partituras;
	int actual;


public:
	solucion(int personas) : personas(personas), partituras(1), actual(personas) {}
	solucion() : personas(0), partituras(0), actual(0) {}

	int getPersonas() const {
		return personas;
	}
	int getPartituras() const{
		return partituras;
	}

	int getActual() const {
		return actual;
	}

	int masParti(){
		return partituras++;
	}

	void setActual(int nuevo){
		if (nuevo >= 1)
			actual = nuevo;
		else
			actual = 1;
	}

	bool operator < (const solucion &otraSol)const {
		return actual>otraSol.getActual();

	}

};


long int resolver(PriorityQueue< solucion> cola, int aRepartir){


	while (aRepartir != 0){

		solucion aux = cola.top();
		cola.pop();
		aux.masParti();
		int nuevoActual;
		if (aux.getPersonas() % aux.getPartituras() == 0)
			nuevoActual = aux.getPersonas() / aux.getPartituras();
		else{
			nuevoActual = (aux.getPersonas() / aux.getPartituras()) + 1;;
		}
		aux.setActual(nuevoActual);
		aRepartir--;

		cola.push(aux);

	}

	return cola.top().getActual();
}






// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int partituras, instrumentos;

	cin >> partituras >> instrumentos;

	if (!cin)
		return false;

	int aux;
	PriorityQueue<solucion, less<solucion>> prioridad;

	for (int i = 0; i<instrumentos; ++i){
		cin >> aux;
		prioridad.push(solucion(aux));

	}
	int aRepartir = partituras - instrumentos;

	long int sol = resolver(prioridad, aRepartir);

	cout << sol << endl;
	return true;
}



int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/UNI/3º/TAIS/TAIS2/Visual/partituras/partituras/Datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf); //reset to standard input again
	system("PAUSE");
#endif
}
