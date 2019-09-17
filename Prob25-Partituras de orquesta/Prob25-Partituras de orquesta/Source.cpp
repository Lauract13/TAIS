// Laura Casas Torres
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <iterator>
#include <functional>
using namespace std;

#include "PriorityQueue.h"


// resuelve un caso de prueba
void resuelveCaso(int const &nPartituras, int const &nMusicos) {


	PriorityQueue<int, greater<int>> musicos;
	int musico; 

	for (int i = 0; i < nMusicos; i++) {
		cin >> musico;
		musicos.push(musico);
	}
	int partiturasExtra = nPartituras - nMusicos; 

	
	if (partiturasExtra > 0) {
		for (int i = 0; i < partiturasExtra; i++) {

			int elem = musicos.top();
			musicos.pop(); 

			int a1 = elem / 2;
			int a2 = elem % 2;

			musicos.push(a1);
			musicos.push(a2);
		}

		
	}
	cout << musicos.top() << endl;

}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numPartituras,numInstrumentos;
	cin >> numPartituras >> numInstrumentos;

	while (!cin.fail()) {
		resuelveCaso(numPartituras, numInstrumentos);

		cin >> numPartituras >> numInstrumentos;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}