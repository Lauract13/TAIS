#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


#include <vector>
using namespace std;

#include "Grafo.h"




void bfs(vector<int> const& V, int pos, int const& k, vector<bool> &marked, vector<int> &distTo) {
	
	
	queue<int> q;

	
	marked[pos] = true;
	q.push(pos);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		int w = v;
		while (w < (pos + k + 1) && w < V.size()){
			if (!marked[w]) {

				int dist = distTo[v] + 1;
				
				if (distTo[w] > distTo[v] || distTo[w] == 0){
					distTo[w] = distTo[v] + 1;
				}
				

				if (V[w] != -1 ){
					int aux = V[w];
					
					if (distTo[aux] > distTo[w] || distTo[aux] == 0){
						distTo[aux] = distTo[w];
					}
					
				}
				
				
				marked[w] = true;
				q.push(w);
			}
			w++;
		}
		
	}
	
}
// resuelve un caso de prueba
void resuelveCaso(int const& N, int const& K, int const& S, int const& E) {
	
	vector<bool> marked(N*N,false); // marked[v] = ¿hay camino de s a v?
	vector<int> distTo(N*N); // distTo[v] = aristas en el camino s-v más corto

	vector<int> v(N*N, -1);
	int a, b;


	for (int i = 0; i < (S+E); i++){
		std::cin >> a >> b;
		v[a -1] = b - 1;
	}
	for (int pos = 0; pos < v.size(); pos++){
		bfs(v, pos, K, marked, distTo);
	}
	
	int dist = distTo[(N*N) - 1];
	cout << dist << endl;


}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int N, K, S, E;
	std::cin >> N >> K >> S >> E;
	
	while(N != 0){
		resuelveCaso(N, K, S, E);

		std::cin >> N >> K >> S >> E;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}