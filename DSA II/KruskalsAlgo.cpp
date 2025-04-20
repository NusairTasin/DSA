//Kruskal's Algorithm

#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent) {
    if(parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    
    if(parentU == parentV) return;
    if(rank[parentU] < rank[parentV]) parent[parentU] = parentV;
    else if(rank[parentU] > rank[parentV]) parent[parentV] = parentU;
    else {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

void kruskalAlgo(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);
    vector<Edge> mst;
    for(int i = 0; i < V; i++) parent[i] = i;
    int totalWeight = 0;

    for(Edge e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if(pu != pv) {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSets(pu, pv, parent, rank);
        }
    }

    cout<<"Edge \tWeight\n";
    for(Edge e : mst) 
        cout<<e.u<<" - "<<e.v<<"\t"<<e.weight<<"\n";

    cout<<"Total Weight of MST: "<<totalWeight<<endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    kruskalAlgo(V, edges);
}