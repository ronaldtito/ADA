#pragma once
#include "puzzle_1.h"
#include "puzzle_2.h"
#include "puzzle_3.h"
#include <vector>
using namespace std;
void puzzle(vector< vector<double> >& tiempos, int groups, int test, int n, int x, int y) {
	vector<double> group1;
	for (int i = 0; i < groups; i++) {
		for (int i = 0; i < test; i++) {
			group1.push_back(puzzle_1(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(puzzle_2(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(puzzle_3(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
	}
	//return la matriz de tiempos
}