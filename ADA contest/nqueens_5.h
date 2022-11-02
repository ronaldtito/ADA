#ifndef NQUEENS_5_H
#define NQUEENS_5_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {
        x = 0; y = 0;
    }
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
    void setPoint(int _x, int _y) {
        x = _x; y = _y;
    }
    void copyPoint(Point P) {
        x = P.x; y = P.y;
    }
};

class Queen1 {
public:
    int cont;
    vector<int> queen;
    vector<int> rdiag;
    vector<int> ldiag;
    vector<int> rows;
    vector<int> columns;

    Queen1(int n, int x, int y) {
        cont = n;
        int N2 = (n + 1) * (n + 1);
        queen.resize(N2, 0);
        rdiag.resize(n * 2, 0);
        ldiag.resize(n * 2, 0);
        rows.resize(n, 0);
        columns.resize(n, 0);

        Point point(x, y);
        bool A = putQueen(point, n);
        Write();

    }
    void Write() {
        ofstream nfile("nqueens_5.txt", ios::app);
        for (int i = 0; i < queen.size() - cont * 2; i++) {
            if (i % cont == 0)
                nfile << endl;
            if (queen[i] != 0)
                nfile << " * ";
            else
                nfile << " . ";

        }
        nfile << "-----------------------------------------" << endl;
        nfile.close();
    }

    bool check(int x, int y) {
        if (!rows[x] && !columns[y] && !ldiag[x + y] && !rdiag[x - y + cont - 1] && !queen[x + (y * cont)])
            return true;
        return false;
    }

    bool putQueen(Point& pt, int size) {
        int i = cont;
        while (i != 0) {
            if (size == 0)
                return true;
            if (check(pt.x, pt.y)) {
                queen[pt.x + (pt.y * cont)] = rows[pt.x] = columns[pt.y] = rdiag[pt.x - pt.y + cont - 1] = ldiag[pt.x + pt.y] = 1;
                Point temp(pt.x + 2, pt.y + 1);
                if (temp.x >= cont)
                    temp.x = 0;
                if (temp.y >= cont)
                    temp.y = 0;
                if (putQueen(temp, size - 1))
                    return true;
                queen[pt.x + (pt.y * cont)] = rows[pt.x] = columns[pt.y] = rdiag[pt.x - pt.y + cont - 1] = ldiag[pt.x + pt.y] = 0;
            }
            pt.x += 1;
            if (pt.x >= cont)
                pt.x = 0;
            i -= 1;
        }
        return false;
    }

};

double nqueens_5(int n, int x, int y) {
    unsigned t0, t1;
    t0 = clock();
    Queen1 prueba(n, x, y);
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC); 

    return time;
}

#endif
