// CIRCULAR QUEUE USSING ARRAY

#include <stdio.h>
#define SIZE 5

int cQueue[SIZE];
int front = -1, rear = -1;

void enQueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Circular Queue is Full! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cQueue[rear] = value;
        printf("%d inserted into Circular Queue.\n", value);
    }
}

void deQueue() {
    if (front == -1) {
        printf("Circular Queue is Empty! Cannot delete.\n");
    } else {
        printf("%d removed from Circular Queue.\n", cQueue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is Empty!\n");
    } else {
        printf("Circular Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", cQueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("\n--- Circular Queue using Array ---\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
