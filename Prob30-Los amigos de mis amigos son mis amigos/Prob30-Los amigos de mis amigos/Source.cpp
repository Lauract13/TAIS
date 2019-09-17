
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


#include <vector>
using namespace std;

#include "Grafo.h"

class MaximaComponenteConexa{

public: 
	MaximaComponenteConexa(Grafo const& G) : marked(G.V(), false), _maximo(0){

		for (int v = 0; v < G.V(); v++){
			if (!marked[v]){
				int tam = 0;
				dfs(G, v, tam);
				_maximo = max(_maximo, tam);
			}
		}
	}

	int maximo() const{
		return _maximo;
	}
private:
	vector<bool> marked;
	int _maximo;

	void dfs(Grafo const &G, int v, int &tam){

		marked[v] = true;
		tam++;

		for (int w : G.ady(v)){
			if (!marked[w]){
				dfs(G, w, tam);
			}
		}
	}

};

// resuelve un caso de prueba
void resuelveCaso() {
	int amigos, pares;
	cin >> amigos >> pares;

	Grafo grafo(amigos);

	for (int i = 0; i < pares; i++){
		int amigo1, amigo2;
		cin >> amigo1 >> amigo2;
		
		grafo.ponArista(amigo1 - 1, amigo2 - 1);
	}
	MaximaComponenteConexa mcc(grafo);
	cout << mcc.maximo() << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;
	cin.get();
	for (int i = 0; i < casos; i++){
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}