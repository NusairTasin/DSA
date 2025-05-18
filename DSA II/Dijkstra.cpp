#include<bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &graph, vector<int> &d, vector<int> &p) {
    int n = graph.size();
    d.assign(n, INT_MAX);
    p.assign(n, -1);
    d[src] = 0;

    set<pair<int, int>> pq;
    pq.insert({0, src});

    while(!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for(auto &[v, w] : graph[u]) {
            if(d[u] + w < d[v]) {
                pq.erase({d[v], v});
                d[v] = d[u] + w;
                p[v] = u;
                pq.insert({d[v], v});
            }
        }
    }
}

int main() {
    int V, E; cin>>V>>E;
    vector<vector<pair<int, int>>> graph(V); // adjacency list of the graph
    vector<int> d; // distance
    vector<int> p; // parent

    for(int i = 0; i < E; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        //graph[v].push_back({u, w}); use for undirected graph only
    }

    int src; cin>>src;

    dijkstra(src, graph, d, p);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << ": " << (d[i] == INT_MAX ? -1 : d[i]) << endl;
    return 0;
}