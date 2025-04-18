////Prim's Algorithm (Minimum Spanning Tree)
//Optimized using Min-Heap and Adjacency List

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

void primsAlgo(int V, Graph& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; //as we are comparing pair, we use pii or else greater<int>

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0,0});
    key[0] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;

        for(auto [v, weight] : adj[u]) {
            if(!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
}

int main() {
    int V =5;
    
    //Adjacency List
    Graph adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({4, 9});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    adj[4].push_back({3, 9});

    primsAlgo(V, adj);
}