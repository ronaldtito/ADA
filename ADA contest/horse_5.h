#ifndef HORSE_5_H
#define HORSE_5_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class mov {
public:
	int idx;
	int value;
	mov(int _idx, int _value) {
		idx = _idx; value = _value;
	}
};




void Write(vector< vector<int> >& matrix) {
	ofstream nfile("horse_5.txt", ios::app);
	for (auto row_obj : matrix) {
		for (auto elem : row_obj)
			nfile << elem << "\t";
		nfile << endl;
	}
	nfile << "-----------------------------------------" << endl;
	nfile.close();

}

void MovValidos(vector< vector<int> >& matrix, vector< mov>& movValidos, int n, int x, int y) {
	int mH[8] = { 2,1,-1,-2,-2,-1, 1, 2 };
	int mV[8] = { 1,2, 2, 1,-1,-2,-2,-1 };
	for (int i = 0; i < 8; i++) {
		int x1 = x + mH[i];
		int y1 = y + mV[i];
		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && matrix[y1][x1] == 0) {
			mov movvalid(i, 0);
			for (int j = 0; j < 8; j++) {
				int x2 = x1 + mH[j];
				int y2 = y1 + mV[j];
				if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && matrix[y2][x2] == 0)
					movvalid.value += 1;
			}
			movValidos.push_back(movvalid);
		}
	}
	sort(movValidos.begin(), movValidos.end(), [](const mov& l, const mov& h) {
		return l.value < h.value; });

}

bool Horse(vector< vector <int> >& matrix, int n, int x, int y, int counter) {
	int N2 = n * n;
	if (counter == N2 + 1)
		return true;
	vector< mov> movValidos;
	MovValidos(matrix, movValidos, n, x, y);
	int pos = 0;
	int mH[8] = { 2,1,-1,-2,-2,-1, 1, 2 };
	int mV[8] = { 1,2, 2, 1,-1,-2,-2,-1 };
	while (pos < movValidos.size()) {
		int x1 = x + mH[movValidos[pos].idx];
		int y1 = y + mV[movValidos[pos].idx];
		matrix[y1][x1] = counter;
		if (Horse(matrix, n, x1, y1, counter + 1))
			return true;
		matrix[y1][x1] = 0;
		pos += 1;
	}
	return false;




}

double horse_5(int n, int x, int y) {
	unsigned t0, t1;
	t0 = clock();
	vector< vector<int> > matrix(n, vector<int>(n, 0));
	matrix[y][x] = 1;
	if (Horse(matrix, n, x, y, 2))
		Write(matrix);//Print matrix
	else
		cout << "No se encontro una Solution" << endl;
	
	t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);

	return time;

}

#endif