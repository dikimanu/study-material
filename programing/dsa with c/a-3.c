// LINEAR QUEUE USSING ARRAY

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot remove element.\n");
    } else {
        printf("%d removed from queue.\n", queue[front++]);
        if (front > rear)
            front = rear = -1; // Reset queue when empty
    }
}

void frontElement() {
    if (isEmpty())
        printf("Queue is Empty!\n");
    else
        printf("Front element is: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("\n--- Linear Queue using Array ---\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontElement();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
