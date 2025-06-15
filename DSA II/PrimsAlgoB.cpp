//Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int V = 9;
int wght = 0;

int minWeight(int weight[], bool visited[]){
    int minimum = INT_MAX;
    int min_index = -1; 
    for(int i = 0; i < V; i++){
        if(visited[i] == false and weight[i] < minimum){
            minimum = weight[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]){
    cout << "Edge \tWeight\n";
    for(int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        wght += graph[i][parent[i]];
    }

    cout << "Total weight of MST: " << wght << endl;
    
}

void primMST(int graph[V][V]){
    int parent[V];
    int weight[V];
    bool visited[V];
    for(int i =0; i < V; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
        parent[i] = -1;
    }

    weight[0] = 0;
    parent[0] = -1;
    
    for(int count = 0; count <V -1; count ++){
        int u = minWeight(weight, visited);
        visited[u] = true;
        for(int v=0; v < V; v++){
            if (graph[u][v] != 0 && visited[v] == false && graph[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main(){
    int graph[V][V] ={
        {0, 10, 6, 5, 0, 0, 0, 0, 0}, 
        {10, 0, 0, 15, 8, 0, 0, 0, 0}, 
        {6, 0, 0, 4, 0, 0, 6, 0, 0}, 
        {5, 15, 4, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 0, 0, 0, 0, 3, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 4, 7, 6}, 
        {0, 0, 6, 0, 3, 4, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 7, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 6, 0, 0, 0}
    };
    primMST(graph);
}