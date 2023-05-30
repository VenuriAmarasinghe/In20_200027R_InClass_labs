#include <stdio.h>
#include <stdbool.h>

#define V 6  // No of vertices in the graph
#define INF 999999999 // Infinity

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    bool visited[V]; // visited[i] will be true if vertex i is included in the shortest path tree

    // Initialize dist[] and visited[]
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance value among the unvisited vertices
        int minDist = INF, minIndex;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        // Mark the picked vertex as visited
        visited[minIndex] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INF
                && dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Print the average time from source
   
    //int tot = 0;
    for (int i = 0; i < V; i++) {
       // tot += dist[i];

        printf("average time  to  node %d = %d\n", i, dist[i]);
    }
    //printf("average time  is %d\n", tot / (V-1));
}

int main() {
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};
    for (int i=0;i<V;i++){
        int source_node = i;
    printf("Source is node  %d\n", source_node);
    dijkstra(graph, source_node);
    }                   
    

    return 0;
}
