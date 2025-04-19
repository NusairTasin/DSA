// Bellman Ford Algorithm
// Beginner Friendly

#include<bits/stdc++.h>
using namespace std;

void bellmanFord(int V, vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(V, INT_MAX);

    dist[0] = 0;
    
    // Relaxation
    for(int i = 0; i < V-1; ++i) {
        for(int u = 0; u < V; ++u) {
            for(auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if(dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Checking for negative cycles
    for(int u = 0; u < V; ++u) {
        for(auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                cout<<"Negative Cycle Detected"<<endl;
                return;
            }
        }
    }

    //Print
    cout<<"Shortest Distances from source vertex 0: "<<endl;
    for(int i = 0; i < V; ++i) {
        cout<<"Vertex "<<i<<": ";
        if(dist[i] == INT_MAX) {
            cout<<"Infinity"<<endl;
        }
        else {
            cout<<dist[i]<<endl;
        }
    }
}

int main() {
    int V = 7;
    vector<vector<pair<int, int>>> graph(V);

    graph[0].push_back({1, 6});
    graph[0].push_back({2, 5});
    graph[0].push_back({3, 5});
    graph[1].push_back({4, -1});
    graph[2].push_back({1, -2});
    graph[2].push_back({4, 1});
    graph[3].push_back({2, -2});
    graph[3].push_back({5, -1});
    graph[4].push_back({6, 3});
    graph[5].push_back({6, 5});

    bellmanFord(V, graph);
}