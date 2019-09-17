
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
#include "GrafoValorado.h"
#include "IndexPQ.h"

class CaminoMin{

public:

	CaminoMin(GrafoValorado<int> const& g, int origen) : distTo(g.V(), numeric_limits<int>::max()), cola(g.V()), distancias(g.V()){
		dijkstra(g, origen);
	}

	int dameCaminos(){
		return distancias[distancias.size() - 1];
	}
	
private:
	vector<int> distTo;
	IndexPQ<int> cola;
	vector<int> distancias;
	
	
	
	void dijkstra(GrafoValorado<int> const& g, int s){


		distTo[s] = 0;
		cola.push(s, 0);
		distancias[s] = 1;

		while (!cola.empty()){
			int v = cola.top().elem;
			cola.pop();

			for (Arista<int> w : g.ady(v)){
				int origen = w.uno();
				
				int destino = w.otro(v);

				if (distTo[destino] > distTo[origen] + w.valor()){
					distTo[destino] = distTo[origen] + w.valor();
					cola.update(destino, distTo[destino]);
					distancias[destino] = distancias[origen];
					
				}
				else{
					if (distTo[destino] == distTo[origen] + w.valor()){
						
						distancias[destino] += distancias[origen];
					}
				}

				
				
			}
		}

	}

};
// resuelve un caso de prueba
void resuelveCaso(int const &N, int const &C) {

	int a1, a2, valor;

	GrafoValorado<int> grafo(N);


	for (int i = 0; i < C; i++) {

		cin >> a1 >> a2 >> valor;
		Arista<int> arista(a1 - 1, a2 - 1, valor);
		grafo.ponArista(arista);

	}

	CaminoMin sol(grafo, 0);

	int cam = sol.dameCaminos();

	cout << cam << endl;
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