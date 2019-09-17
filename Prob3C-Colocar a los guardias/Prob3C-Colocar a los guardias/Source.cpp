
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
#include "Grafo.h"

int cruceMejorSituado(Grafo const& g){

	int vertice = 0;
	int cruces = 0;

	for (int i = 0; i < g.V(); i++){
		if (cruces < g.ady(i).size()){
			vertice = i;
			cruces = g.ady(i).size();
		}
	}

	return vertice;
}
bool colocarGuardias(Grafo const& g, int v, int& guardias){

	vector<bool> marked(g.V(), false);
	vector<bool> guardia(g.V(), false);
	int callesCubiertas = 0;
	bool posible = true, encontrado = false;


	while (callesCubiertas < g.E() && posible){

		marked[v] = true;
		guardia[v] = true;
		guardias++;
		callesCubiertas += g.ady(v).size();

		for (auto w : g.ady(v)){
			marked[w] = true;
		}
		v = 0;
		while (!encontrado && v < marked.size()){

			if (!marked[v] && !guardia[v]){
				encontrado = true;
			}
			else{
				v++;
			}
		}

		if (v == marked.size() && callesCubiertas < g.E()){
			posible = false;
		}
	}

	return posible;
}
// resuelve un caso de prueba
void resuelveCaso(int const &N, int const &C) {

	Grafo grafo(N);
	int guardias = 0;
	int a1, a2;

	for (int i = 0; i < C; i++){
		cin >> a1 >> a2;
		grafo.ponArista(a1-1, a2-1);
	}

	int verticeInicio = cruceMejorSituado(grafo);

	if (colocarGuardias(grafo, verticeInicio,guardias)){
		cout << guardias << endl;
	}
	else{
		cout << "IMPOSIBLE" << endl;
	}


}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int N, C;

	cin >> N >> C;

	while (!cin.fail()) {

		resuelveCaso(N, C);

		cin >> N >> C;


	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}