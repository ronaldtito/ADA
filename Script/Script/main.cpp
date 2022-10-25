#include "puzzle.h"
#include "nqueens.h"
//#include "horse.h"
#include <vector>

using namespace std;
#include <iostream>
int main() {
	int test = 3;
	int groups = 3;
	vector< vector <double > > TPuzzle;
	vector< vector <double > > TNqueens;
	vector< vector <double > > THorse;
	puzzle(TPuzzle, test, groups,8, 3, 4);
	//horse(TNqueens, test, groups, 8, 3, 4);
	nqueens(THorse, test, groups, 8, 3, 4);



}