#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the graph
struct Node {
  int vertex;
  struct Node* next;
};

// A structure to represent a queue
struct Queue {
  int front, rear, size;
  struct Node** array;
};

// A utility function to create a new node
struct Node* newNode(int v) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->vertex = v;
  node->next = NULL;
  return node;
}

// A utility function to create a queue of given size
struct Queue* createQueue(int size) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->array = (struct Node**)malloc(queue->size * sizeof(struct Node*));
  return queue;
}

// A utility function to check if the queue is full
int isFull(struct Queue* queue) {
  return queue->rear == queue->size - 1;
}

// A utility function to check if the queue is empty
int isEmpty(struct Queue* queue) {
  return queue->front == -1;
}

// A utility function to add an element to the queue
void enqueue(struct Queue* queue, struct Node* node) {
  if (isFull(queue)) {
    return;
  }
  queue->array[++queue->rear] = node;
}

// A utility function to remove an element from the queue
struct Node* dequeue(struct Queue* queue) {
  if (isEmpty(queue)) {
    return NULL;
  }
  struct Node* node = queue->array[queue->front++];
  return node;
}

// A utility function to print the graph
void printGraph(struct Node* adjacencyList[]) {
  int v;
  for (v = 0; v < V; ++v) {
    struct Node* temp = adjacencyList[v];
    printf("\nAdjacency list of vertex %d\n head ", v);
    while (temp) {
      printf("-> %d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

// A function to perform BFS on a graph
void BFS(struct Node* adjacencyList[], int startVertex) {

  // Create a queue for BFS
  struct Queue* queue = createQueue(V);

  // Mark the startVertex as visited and enqueue it
  visited[startVertex] = 1;
  enqueue(queue, adjacencyList[startVertex]);

  while (!isEmpty(queue)) {

    // Dequeue a vertex from queue and print it
    struct Node* currentNode = dequeue(queue);
    printf("%d ", currentNode->vertex);

    // Get all adjacent vertices of the dequeued vertex. If a adjacent
    // has not been visited, then mark it visited and enqueue it
    struct Node* temp = adjacencyList[currentNode->vertex];
    while (temp) {
      if (!visited[temp->vertex]) {
        visited[temp->vertex] = 1;
        enqueue(queue, temp);
      }
      temp = temp->next;
    }
  }
}

// Driver program to test the above functions
int main() {
  // Create a graph given in the above diagram
  struct Node* adjacencyList[V];
  for (int i = 0; i < V; ++i) {
    adjacencyList[i] = NULL;
  }

  // Add edges to the graph
  addEdge(adjacencyList, 0, 1);
  addEdge(adjacencyList, 0, 2);
  addEdge(adjacencyList, 1, 2);
  addEdge(adjacencyList, 2, 0);
  addEdge(adjacencyList, 2, 3);
  addEdge(adjacencyList, 3, 3);

  // Print the graph
  printGraph(adjacencyList);

  // Perform BFS starting from vertex 2
  BFS(adjacencyList, 2);

  return 0;
}
