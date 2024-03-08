#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data) {
  struct Node *newNode = newNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data) {
  struct Node *newNode = newNode(data);
  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to insert a new node after a given node
void insertAfter(struct Node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }

  struct Node *newNode = newNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

// Function to delete a node from the beginning of the linked list
void deleteAtBeginning(struct Node **head) {
  if (*head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Function to delete a node from the end of the linked list
void deleteAtEnd(struct Node **head) {
  if (*head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  struct Node *temp = *head;
  struct Node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL) {
    *head = NULL;
  } else {
    prev->next = NULL;
  }

  free(temp);
}

// Function to delete a node after a given node
void deleteAfter(struct Node *prevNode) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }

  if (prevNode->next == NULL) {
    printf("There is no node after the given node\n");
    return;
  }

  struct Node *temp = prevNode->next;
  prevNode->next = temp->next;
  free(temp);
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;

  // Insert nodes at the beginning of the linked list
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);

  // Print the linked list
  printLinkedList(head);

  // Insert a node at the end of the linked list
  insertAtEnd(&head, 40);

  // Print the linked list
  printLinkedList(head);

  // Insert a node after a given node
  insertAfter(head->next, 50);

  // Print the linked list
  printLinkedList(head);

  // Delete a node from the beginning of the linked list
  deleteAtBeginning(&head);

  // Print the linked list
  printLinkedList(head);

  // Delete a node from the end of the linked list
  deleteAtEnd(&head);

  // Print the linked list
  printLinkedList(head);

  // Delete a node after a given node
  deleteAfter(head);

  // Print the linked list
  printLinkedList(head);

  return 0;
}
