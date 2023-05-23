#include<iostream>
#include<climits>


#define V 6
int min_key(int key[], bool mst_set[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++){
        if (mst_set[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void display_mst(int parent[], int graph[V][V]){
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void prim_mst(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mst_set[V];
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mst_set[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++){
        int u = min_key(key, mst_set);
        mst_set[u] = true;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    display_mst(parent, graph);
}

int main(){
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };
    prim_mst(graph);
    return 0;
}