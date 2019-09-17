

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;




int resuelveCasos(vector<int> const &jugadores, vector<int> const &camisetas) {
	int equipaciones = 0;
	int posJ = 0, posC = 0;


	while (posJ < jugadores.size() && posC < camisetas.size()){
		if (camisetas[posC] == jugadores[posJ] || camisetas[posC] == jugadores[posJ] + 1){
			posJ++;
			posC++;
			equipaciones++;
		}
		else{
			posC++;
		}
	}

	return equipaciones;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int N, M;

	cin >> N >> M;

	while (!cin.fail()){

		vector<int> jugadores(N);
		vector<int> camisetas(M);
		int num;

		for (int j = 0; j < N; j++){

			cin >> num;
			jugadores[j] = num;

		}
		for (int i = 0; i < M; i++){
			cin >> num;
			camisetas[i] = num;
		}

		sort(jugadores.begin(), jugadores.end());
		sort(camisetas.begin(), camisetas.end());

		cout << N - resuelveCasos(jugadores, camisetas) << endl;



		cin >> N >> M;

	}






	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif	

	return 0;
}
