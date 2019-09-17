// Laura Casas Torres
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;
typedef struct {
	long long int ini; 
	long long int fin; 
	long long int periodo;

} tTarea;

bool operator<(const tTarea &t1, const tTarea &t2) {
	if (t1.ini < t2.ini) {
		return true;
	}
	else {
		if (t1.ini == t2.fin) {
			if (t1.fin < t2.fin) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

bool resolver(PriorityQueue<tTarea> &t, int tiempo) {

	bool correcto = true; 
	int contador = 0;

	tTarea tarea = t.top();

	int fin = tarea.fin;

	t.pop();

	if (tarea.periodo != 0) {
		t.push({ tarea.ini + tarea.periodo, tarea.fin + tarea.periodo, tarea.periodo });
	}

	while (correcto && contador <= tiempo ) {
		
		tTarea tarea = t.top();
		t.pop();

		if (fin > tarea.ini) { // Se solapan
			correcto = false;
		}
		else {
			contador += tarea.ini;

			fin = tarea.fin;
			if (tarea.periodo != 0) {

				t.push({ tarea.ini + tarea.periodo, tarea.fin + tarea.periodo, tarea.periodo });
			}
		}

	}

	return correcto;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	
	int numUnicas, numPeriodicas, tiempo, inicio, fin, per;

	cin >> numUnicas >> numPeriodicas >> tiempo;

	
	while (!cin.fail()) {


		PriorityQueue<tTarea> tareas;


		int cont;
		for (cont = 0; cont < numUnicas; cont++) {

			cin >> inicio >> fin;
			tareas.push({ inicio, fin,0 });
		}

		for (cont; cont < numUnicas + numPeriodicas; cont++) {
			cin >> inicio >> fin >> per;
			tareas.push({ inicio, fin, per });

		}


		if (tareas.size() <= 1) {
			cout << "NO" << endl;
		}
		else {
			if (resolver(tareas, tiempo)) {
				cout << "NO" << endl;
			}
			else {
				cout << "SI" << endl;
			}
		}

		cin >> numUnicas >> numPeriodicas >> tiempo;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}