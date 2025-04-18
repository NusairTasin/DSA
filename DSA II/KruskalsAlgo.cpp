#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent) {
    if(parent[node] == -1) 
        return node;
    return findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int> &parent) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    parent[parentU] = parentV;
}

void kruskalAlgo(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V, -1);
    vector<Edge> mst;
    int totalWeight = 0;

    for(Edge e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if(pu != pv) {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSets(pu, pv, parent);
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