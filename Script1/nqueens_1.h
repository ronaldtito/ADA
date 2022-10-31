#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector< vector<int> >& matrix) {
    
}
void Answer(vector< vector<int> > &matrix/* solution tuplas */) {
    for (int i = 0; i < solution.size(); i++){
        int posX = solution[i][0];
        int posY = solution[i][1];
        matrix[posX][posY] = 1;
    }
}

void cDisponibles(vector<int>& rows, vector<int>& ldiag, vector<int>& rdiag,vector<int>& columns, int y, int n) {
    for (int i = 0; i < n; i++) {
        if (!rows[i] && !ldiag[y + i] && !rdiag[i - y + n - 1])
            columns.push_back(i);
    }
}

void Solution(vector< vector<int> > &matrix, int n, int posX, int posY){
    vector< vector<int> > matrix(n, vector<int>(n, 0));
    vector<int> rows(n, 0);
    vector<int> rdiag(n * 2, 0);
    vector<int> ldiag(n * 2, 0);
    
    vector<int> columns;
    vector< vector<int> > solution;

    while (solution.size() != n) {
        solution.clear();
        replace(rows.begin(), rows.end(), 1, 0);
        replace(rdiag.begin(), rdiag.end(), 1, 0);
        replace(ldiag.begin(), ldiag.end(), 1, 0);
        //solution.push_back(); add point x y
        rows[posX] = ldiag[posX + posY] = rdiag[posX - posY + n - 1] = 1;

        for (int y = 0; y < n; y++) {
            if (y == posY)
                continue;
            columns.clear()
            cDisponibles(rows,ldiag,rdiag,columns,y, n);
            if (!columns.empty())
                ;//x = random choice columns
            else
                break;

            rows[x] = ldiag[x + y] = rdiag[x - y + n - 1] = 1;
            //solution.push_back(); add point x y
    }
        Answer(matrix,solution);
}

double nqueens_1(int const n, int x, int y) {
    auto start = chrono::steady_clock::now();
    // code
    vector< vector<int> > matrix(n, vector<int>(n, 0));
    Solution(matrix, n, x, y);
    Print(matrix);

   
    
    auto end = chrono::steady_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return time;
}