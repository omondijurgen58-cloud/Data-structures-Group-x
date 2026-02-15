/*
  GROUP PROJECT: DATA STRUCTURES & ALGORITHMS
  
 
  PART A: Research where the data structures types are applied and give reasons why.
 
  1. ARRAY: Used in Student Marksheets.
  Reason: Allows random access (fast retrieval) using ID numbers
  2. STACK: Used in "Undo" buttons in apps.
  Reason: Uses LIFO (Last In, First Out) behavior which perfectly matches the 
  need to reverse the most recent actions.
  3. QUEUE: Used in Printer line / Ticket systems.
  Reason: Uses FIFO (First In, First Out) behavior to ensure the first request 
  received is the first one processed.
  4. TREE: Used in File Systems (Folders).
  Reason: Hierarchical structure is ideal for organizing data into levels (Parent -> Child).
  5. GRAPH:Used in Social Networks.
  Reason: Best for modeling complex web-like connections (Friends of Friends).
 
  PART B: Performance & Applications
  1. Inventory search: Searching 10^6 items sequentially is too slow. 
  Using Binary Search algorithm on an organized data structure allows for instant results
  2. Performance Metrics: Measured through Time Complexity and Space complexity.
 
  PART C: How data structures work within systems
  - Overcome Processor Limits: Efficient organization handles billion of files.
  - Handle Multiple Requests: Prevents server failure when thousands of users search simultaneously.
  - Abstraction: They provide an interface (ADT) to use data without managing complex internal code.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define V 3


// 1. PRIMITIVE DATA STRUCTURES

void primitiveExample() {
    printf("\n*** 1. PRIMITIVE DATA STRUCTURES ***\n");
    int age = 20;
    float height = 5.9;
    char grade = 'A';
    double balance = 1500.52;

    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Grade: %c\n", grade);
    printf("Balance: %.2lf\n", balance);
}


// 2. LINEAR DATA STRUCTURES


// (a) Array
void arrayExample() {
    printf("\n*** 2(a). ARRAY ***\n");
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array Elements: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// (b) Linked List (YouTube Playlist)
struct Node {
    int data;
    struct Node* next;
};

void linkedListExample() {
    printf("\n*** 2(b). LINKED LIST ***\n");
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    // Traverse and print
    struct Node* temp = head;
    printf("Linked List Elements: "); 
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// (c) Stack (LIFO - Undo Button)
int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void stackExample() {
    printf("\n*** 2(c). STACK (LIFO) ***\n");
    top = -1; // Reset stack
    
    // Push items
    push(10);
    push(20);
    push(30);
    printf("Stack created (Top is 30)\n");

    // Pop items
    printf("Popped: %d (Last In, First Out)\n", pop());
    printf("Popped: %d\n", pop());
}

// (d) Queue (FIFO - Printer Line)
int queue[SIZE];
int front = 0, rear = -1;

void enqueue(int value) {
    if(rear == SIZE - 1)
        printf("Queue Full\n");
    else
        queue[++rear] = value;
}
int dequeue() {
    if(front > rear) {
        printf("Queue Empty\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void queueExample() {
    printf("\n*** 2(d). QUEUE (FIFO) ***\n");
    front = 0; rear = -1; // Reset queue
    
    // Enqueue items
    enqueue(5);
    enqueue(15);
    enqueue(25);
    printf("Queue created (Front is 5)\n");

    // Dequeue items
    printf("Dequeued: %d (First In, First Out)\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
}


// 3. NON-LINEAR DATA STRUCTURES


// (a) Binary Tree (File System)
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void treeExample() {
    printf("\n*** 3(a). BINARY TREE ***\n");
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Root: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);
}

// (b) Graph (Social Network)
void graphExample() {
    printf("\n*** 3(b). GRAPH ***\n");
    int graph[V][V] = {
        {0, 1, 1}, // Node 0 connects to 1 and 2
        {1, 0, 0}, // Node 1 connects to 0
        {1, 0, 0}  // Node 2 connects to 0
    };

    printf("Graph Adjacency Matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


int main() {
    primitiveExample(); 
    arrayExample(); 
    linkedListExample();
    stackExample(); 
    queueExample(); 
    treeExample();
    graphExample();

    return 0;
}