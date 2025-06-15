#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void matrixChainOrder(vector<int>& d, vector<vector<int>>& M, vector<vector<int>>& S) {
    int n = d.size() - 1;
    M.assign(n, vector<int>(n, 0));
    S.assign(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {  // Chain length
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int q = M[i][k] + M[k+1][j] + d[i] * d[k+1] * d[j+1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<int> dimensions = {30, 35, 15, 5, 10, 20, 25};
    vector<vector<int>> M, S;

    matrixChainOrder(dimensions, M, S);

    cout << "Cost Matrix (M):\n";
    printMatrix(M);

    cout << "\nSplit Matrix (S):\n";
    printMatrix(S);

    return 0;
}