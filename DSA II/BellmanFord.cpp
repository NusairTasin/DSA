#include<bits/stdc++.h>
using namespace std;

void bellman(vector<vector<pair<int, int>>> &graph, vector<int> &d) {
    int V = graph.size();
    d.assign(V, INT_MAX);
    d[0] = 0;

    // Relaxation
    for(int i = 0; i < V-1; i++) {
        for(int u = 0; u < V; u++) {
            for(auto &[v, w] : graph[u]) {
                int ver = v;
                int weight = w;
                if(d[u] != INT_MAX && d[v] > d[u] + weight) {
                    d[v] = d[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for(int i = 0; i < 1; i++) {
        for(int u = 0; u < V; u++) {
            for(auto &[v, w] : graph[u]) {
                int ver = v;
                int weight = w;
                if(d[u] != INT_MAX && d[v] > d[u] + weight) {
                    cout<<"Negative cycle detected"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"Shortest Distances from source vertex 0: "<<endl;
    for(int i = 0; i < V; ++i) {
        cout<<"Vertex "<<i<<": ";
        if(d[i] == INT_MAX) {
            cout<<"Infinity"<<endl;
        }
        else {
            cout<<d[i]<<endl;
        }
    }
}

int main() {
    int V, E; cin>>V>>E;
    vector<vector<pair<int, int>>> graph(V);
    vector<int> d, p;

    for(int i = 0; i < E; i++) {
        int u, v, w; cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    bellman(graph, d);
}

// Check for output:
// 7
// 10
// 0 1 6
// 0 2 5
// 0 3 5
// 1 4 -1 
// 2 1 -2
// 2 4 1
// 3 2 -2
// 3 5 -1
// 4 6 3
// 5 6 5