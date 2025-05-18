// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    cin>>x>>y;
    int n = x.size(), m = y.size();
    
    vector<vector<int>> b(n+1, vector<int>(m+1, 0));
    vector<vector<char>> c(n+1, vector<char>(m+1, ' '));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; j++) {
            if(x[i-1] == y[j-1]) {
                b[i][j] = b[i-1][j-1] + 1;
                c[i][j] = 'D';
            }
            else if(b[i-1][j] >= b[i][j-1]) {
                b[i][j] = b[i-1][j];
                c[i][j] = 'U';
            }
            else {
                b[i][j] = b[i][j-1];
                c[i][j] = 'L';
            }
        }
    }
    
    string lcs; 
    int i = n, j = m;
    while(i and j) {
        if(c[i][j] == 'D') {
            lcs+=x[i-1];
            --i;
            --j;
        }
        else if(c[i][j] == 'L') --j;
        else --i;
    }
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<endl;
    cout<<lcs.size()<<endl;

    return 0;
} 