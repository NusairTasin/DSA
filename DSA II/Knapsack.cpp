#include<bits/stdc++.h>
using namespace std;

void knapsack(int W, int n, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w<=W; w++) {
            if(wt[i-1] <= w) dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1]);
            else dp[i][w] = dp[i-1][w];
        }
    }
    cout<<"Maximum value in Knapsack = "<<dp[n][W]<<endl;
}

int main() {
    int W, n; cin>>n>>W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cin>>wt[i]>>val[i];
    }
    knapsack(W, n, wt, val);
}