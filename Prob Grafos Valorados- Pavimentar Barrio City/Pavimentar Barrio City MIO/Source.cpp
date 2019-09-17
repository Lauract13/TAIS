#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "GrafoValorado.h"
#include "IndexPQ.h"

class PrimMST{


private:
	vector<Arista<int>> edgeTo; // vertices adyacentes
	vector<int> distTo; // distTo[w] = edgeTo[w].weight()
	vector<bool> marked; // verdadero si v pertenece al arbol
	IndexPQ<int> pq; 


	// Coste O(log E) donde E es el nº de aristas del grafo
	void visit(vector<Arista<int>> const &list, int nodo){

		marked[nodo] = true;
		for (Arista<int> a : list){
			int dest = a.otro(nodo);

			if (!marked[dest]){
				if (a.valor() < distTo[dest]){
					distTo[dest] = a.valor();
					pq.update(dest, a.valor());
				}
			}
		}
	}

	// Coste O(V*log E) siendo V el nº de vertices y E el nº de aristas
	void llenaCola(GrafoValorado<int> const &g){

		distTo[0] = 0;
		pq.push(0, 0);

		while (!pq.empty()){
			int nodo = pq.top().elem;
			pq.pop();
			vector<Arista<int>> a = g.ady(nodo);

			visit(a, nodo);
		}
	}
public:
	
	PrimMST(size_t v) : marked(v, false), distTo(v, 100000000), pq(v){};
	
	// Coste O(V*logE)
	int prim(GrafoValorado<int> const &g){
		
		int coste = 0;

		llenaCola(g);

		bool imp = false;
		int i = 0;
		
		while (i < marked.size() && !imp){
			if (marked[i]){
				coste += distTo[i];
			}
			else{
				imp = true;
				coste = -1;
			}
			i++;
		}
		return coste;
	}

	
};


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int intersecciones;
	int calles;

	cin >> intersecciones;

	while (!cin.fail()) {
		cin >> calles;
		Arista<int>	arista;
		GrafoValorado<int> g(intersecciones);

		int a, b, v;
		for (int i = 0; i < calles; i++) {
			cin >> a >> b >> v;
			arista = Arista<int>(a - 1, b - 1, v);
			g.ponArista(arista);
		}

		PrimMST mst = PrimMST(g.V());

		int coste = 0;
		

		
		int sol = mst.prim(g);
		if (sol == -1) {
			cout << "Imposible" << endl;
		}
		else {
			cout << sol << endl;
		}

		cin >> intersecciones;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}