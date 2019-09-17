//Laura Casas Torres
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

#include "PriorityQueue.h"

struct tarea{

	long long int inicio;
	long long int final;
	long long int periodo;

};

bool operator<(tarea const& a, tarea const& b) {
	if (a.final <= b.inicio) return true;
	else  return false;

}

// resuelve un caso de prueba
bool resuelveCaso(long long int n, long long int m, long long int t) {

	PriorityQueue<tarea> pq;
	bool conflicto = false, final = false;
	long long int ini, fin, p, tfinal = 0;

	for (int i = 0; i < n; i++)
	{

		cin >> ini >> fin;
		pq.push({ ini, fin, 0 });

	}

	for (int j = 0; j < m; j++){

		cin >> ini >> fin >> p;
		pq.push({ ini, fin, p });

	}

	if (pq.size() > 1){

		tarea t1 = pq.top();
		t = t + t1.inicio;
		tfinal = t1.final;


		while (!conflicto && !final){

			t1 = pq.top();

			pq.pop();
			tarea t2 = pq.top();
			if (t1.inicio < t){

				if (t2.inicio < tfinal){
					conflicto = true;
				}
				else{
					tfinal = t1.final;
					if (t1.periodo != 0){
						t1.inicio = t1.inicio + t1.periodo;
						pq.push(t1);

					}
				}



			}
			else{
				final = true;
			}

		}


	}
	else{
		conflicto = false;
	}


	return conflicto;

}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int unicas, periodicas;
	long long int minutos;

	cin >> unicas >> periodicas >> minutos;

	while (!cin.fail()) {
		if (resuelveCaso(unicas, periodicas, minutos)){
			cout << "SI" << endl;
		}
		else{
			cout << "NO" << endl;
		}

		cin >> unicas >> periodicas >> minutos;

	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}