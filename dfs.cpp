#include <stdio.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
  int vertices; // Number of vertices in the graph
  int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to represent the edges in the graph
};

// Function to perform DFS traversal on the graph
void DFS(struct Graph* graph, int vertex) {
  // Mark the current vertex as visited
  graph->visited[vertex] = 1;

  // Print the current vertex
  printf("%d ", vertex);

  // Recursively explore all the adjacent vertices
  for (int i = 0; i < graph->vertices; i++) {
    if (graph->adjacency_matrix[vertex][i] == 1 && !graph->visited[i]) {
      DFS(graph, i);
    }
  }
}

// Main function
int main() {
  // Create a graph with 4 vertices
  struct Graph graph;
  graph.vertices = 4;

  // Initialize the adjacency matrix to 0
  for (int i = 0; i < graph.vertices; i++) {
    for (int j = 0; j < graph.vertices; j++) {
      graph.adjacency_matrix[i][j] = 0;
    }
  }

  // Add edges to the graph
  graph.adjacency_matrix[0][1] = 1;
  graph.adjacency_matrix[0][2] = 1;
  graph.adjacency_matrix[1][2] = 1;
  graph.adjacency_matrix[2][0] = 1;
  graph.adjacency_matrix[2][3] = 1;
  graph.adjacency_matrix[3][3] = 1;

  // Perform DFS traversal on the graph
  DFS(&graph, 2);

  return 0;
}
