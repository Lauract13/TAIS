#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

#include "PriorityQueue.h"

int esfuerzo(const int n) {

	PriorityQueue<int> cola;

	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cola.push(num);
	}

	int esfuerzo = 0;

	while (cola.size() > 1) {

		int suma = cola.top();

		cola.pop();
		suma = suma + cola.top();
		cola.pop();
		esfuerzo = esfuerzo + suma;
		cola.push(suma);
	}


	return esfuerzo;
	
}

// resuelve un caso de prueba
void resuelveCaso(const int sum) {

	if (sum == 1) {

		int aux;
		cin >> aux;
		
		cout << 0 << endl;
	}
	else {


		cout << esfuerzo(sum) << endl;

	}
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int sumandos;
	std::cin >> sumandos;
	cin.get();

	while (sumandos != 0)
	{
		resuelveCaso(sumandos);
		std::cin >> sumandos;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
