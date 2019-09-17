//Laura Casas Torres
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "PriorityQueue.h"

struct cliente{

	int prio; 
	int caja;
};

bool operator<(cliente const& a, cliente const& b) {
	if (a.prio < b.prio) return true;
	else {
		return false;
	}
	

}

// resuelve un caso de prueba
void resuelveCaso(int const &nCajas, int nClientes) {

	PriorityQueue<cliente> pq;
	vector<cliente> clientes;
	int c;

	
	if (nCajas > nClientes){
		cout << nClientes + 1 << endl;

		for (int i = 0; i < nClientes; i++){
			cin >> c;
		}
	}
	else{
		int i;

		for (i = 1; i <= nCajas; i++){
			cin >> c;
			pq.push({ c, i });
			nClientes--;
		}

		while (nClientes > 0){
			cliente e = pq.top();
			pq.pop();
			cin >> c; 
			pq.push({ c + e.prio, e.caja });
			nClientes--;
		}

		cliente e = pq.top();
		cout << e.caja << endl;

		
	}
}
int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int numCajas, numClientes;
	cin >> numCajas >> numClientes;
	while (numCajas != 0) {
		resuelveCaso(numCajas, numClientes);

		cin >> numCajas >> numClientes;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}