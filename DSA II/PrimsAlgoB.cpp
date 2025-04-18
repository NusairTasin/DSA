//Prim's Algorithm (Minimum Spanning Tree)
//Beginner Friendly using Adjacency Matrix

#include<bits/stdc++.h>
using namespace std;

int minVertex(vector<int>& key, vector<bool>& explored, int V) {
    int min = INT_MAX, minIndex;

    for(int v=0; v<V; v++) {
        if(!explored[v] && key[v]<min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primsAlgo(vector<vector<int>> graph, int V) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> explored(V, false);

    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count<V; count++) {
        int u = minVertex(key, explored, V);
        explored[u] = true;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !explored[v] && graph[u][v]<key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    //Print
    cout<<"Edge \tWeight\n";
    for(int i=1; i<V; i++) {
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primsAlgo(graph, V);
}