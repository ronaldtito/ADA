#pragma once
#include "horse_1.h"
#include "horse_2.h"
#include "horse_3.h"
#include <vector>
using namespace std;

void horse(vector< vector<double> >& tiempos, int groups, int test, int n, int x, int y) {
	vector<double> group1;
	for (int i = 0; i < groups; i++) {
		for (int i = 0; i < test; i++) {
			group1.push_back(horse_1(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(horse_2(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
		for (int i = 0; i < test; i++) {
			group1.push_back(horse_3(n, x, y));
		}
		tiempos.push_back(group1);
		group1.clear();
	}
}