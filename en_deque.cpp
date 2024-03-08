#include <stdio.h>
#define MAX_SIZE 100

// Function to create a queue
struct Queue {
  int front;
  int rear;
  int size;
  int *array;
};

// Function to create a queue
struct Queue *createQueue(int size) {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->size = size;
  queue->array = (int *)malloc(size * sizeof(int));
  return queue;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
  return queue->rear == queue->size - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
  return queue->front == -1;
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  queue->rear++;
  queue->array[queue->rear] = data;
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }
  int data = queue->array[queue->front];
  queue->front++;
  return data;
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return;
  }
  for (int i = queue->front + 1; i <= queue->rear; i++) {
    printf("%d ", queue->array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  struct Queue *queue = createQueue(MAX_SIZE);

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  display(queue);

  dequeue(queue);
  dequeue(queue);

  display(queue);

  return 0;
}
