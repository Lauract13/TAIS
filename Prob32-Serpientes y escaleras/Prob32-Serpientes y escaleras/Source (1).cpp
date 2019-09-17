// LAURA CASAS TORRES
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#include <vector>
using namespace std;

#include "Grafo.h"


// Coste O(K * N * N)
int bfs(vector<int> const& V, int const& N, int const& K) {


	int dest = N * N;

	queue<int> q;
	vector<bool> marked(dest + 1, false);
	vector<int> distTo(dest + 1);

	distTo[1] = 0;
	marked[1] = true;
	q.push(1);


	while (!q.empty()) {

		int v = q.front(); q.pop();

		for (int i = 1; i <= K && v + i <= dest; i++) {

			int w = V[v + i];

			if (!marked[w]) {

				distTo[w] = distTo[v] + 1;
				if (w == dest) {
					return distTo[dest];
				}


				marked[w] = true;
				q.push(w);
			}

		}

	}



}
// resuelve un caso de prueba
bool resuelveCaso() {

	int N, K, S, E;

	cin >> N >> K >> S >> E;

	if (N == 0) {
		return false;
	}
	vector<int> v(N*N + 1);


	for (int i = 1; i <=( N * N); i++) {

		v[i] = i;
	}

	int a, b;
	for (int i = 0; i < (S + E); i++) {
		cin >> a >> b;
		v[a] = b;
	}

	cout << bfs(v, N, K) << endl;



	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso()) {

	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}