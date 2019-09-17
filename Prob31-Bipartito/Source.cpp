	
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
#include "Grafo.h"



bool dfs(Grafo const& G, vector<bool> &marked, vector<bool> &color, int p, int &cont) {
	
	marked[p] = true;
	cont++;
	

	for (int w : G.ady(p)) {
		if (!marked[w]) {

			if (color[p]) {
				color[w] = false;
			}
			else {
				color[w] = true;
			}

			if (!dfs(G, marked, color, w, cont)){
				return false;
			}
		}
		else {
			if (color[p] == color[w]) {
				return false;
			}
		}
	}

	return true;
}

// resuelve un caso de prueba
bool resuelveCaso(Grafo const& g) {
	
	bool esBipartito = true;
	vector<bool> marked(g.V(), false);
	vector<bool> color(g.V(), false);
	int pos = 0;
	int cont = 0;

	while (cont < g.V() && esBipartito) {

		esBipartito = dfs(g, marked, color, pos, cont);

		
	}
	

	return esBipartito;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int vertices, aristas;

	cin >> vertices;

	

	
	while(!cin.fail()) {

		cin >> aristas;

		Grafo grafo(vertices);

		for (int i = 0; i < aristas; i++) {
			int a1, a2;
			cin >> a1 >> a2;

			grafo.ponArista(a1, a2);
		}
		if (resuelveCaso(grafo)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		cin >> vertices;

		
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}