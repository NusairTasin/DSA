#include<bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    cin>> x>> y;

    int n = x.size();
    int m = y.size();

    vector<vector<int>> c(n+1, vector<int>(m+1, 0));
    vector<vector<char>> b(n+1, vector<char>(m+1, ' '));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }    
    }

    cout<<endl<<"LCS length table (c) :"<<endl;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"LCS direction table (b):"<<endl;
    for(int i = 1; i<=n; ++i) {
        for(int j =1; j <=m; ++j) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    string lcs;
    int i = n, j = m;

    while(i and j) {
        if(b[i][j] == 'D') {
            lcs += x[i-1];
            --i;
            --j;
        }
        else if(b[i][j] == 'U') --i;
        else --j;
    }

    reverse(lcs.begin(), lcs.end());
    cout<<endl<<"LCS: "<<lcs<<endl;
    cout<<"LCS Length: "<<lcs.size()<<endl;
}