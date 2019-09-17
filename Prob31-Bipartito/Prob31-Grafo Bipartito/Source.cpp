
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


#include <vector>
using namespace std;

#include "Grafo.h"

bool dfs(Grafo const &g, vector<bool> marked, vector<bool> color, int v){

	marked[v] = true;
	
	for (int w : g.ady(v)){
		if (!marked[w]){
			
				if (color[v]){
					color[w] = false;
				}
				else{
					color[w] = true;
				}
				if (!dfs(g, marked, color, w)){
					return false;
				}
		}
		else{
			if (color[v] == color[w]){
				return false;
			}
		}

	}
	return true;
}

// resuelve un caso de prueba
void resuelveCaso(int const &vertices, int const &aristas) {
	

	Grafo grafo(vertices);


	for (int i = 0; i < aristas; i++){
		int a1, a2;
		cin >> a1 >> a2;

		grafo.ponArista(a1, a2);
	}
	
	vector<bool> marked(grafo.V(), false);
	vector<bool> color(grafo.V(), false);

	

	if (dfs(grafo, marked, color, 0)){
		cout << "SI" << endl;
	}
	else{
		cout << "NO" << endl;
	}



}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int vertices, aristas;
	cin >> vertices;
	cin >> aristas;

	while (!cin.fail()){
		resuelveCaso(vertices, aristas);

		cin >> vertices;
		cin >> aristas;

	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}