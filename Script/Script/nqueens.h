#pragma once
#pragma once
#include "nqueens_1.h"
#include "nqueens_2.h"
#include "nqueens_3.h"
#include <vector>

using namespace std;

void nqueens(vector< vector<double> >& tiempos, int groups, int test, int n, int x, int y) {
	vector<double> group1;
	for (int i = 0; i < groups; i++) {
		for (int i = 0; i < test; i++) {
			group1.push_back(nqueens_1(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(nqueens_2(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(nqueens_3(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
	}