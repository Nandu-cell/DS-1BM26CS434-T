#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        // Circular increment
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted: %d\n", element);
    }
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        element = items[front];
        // Queue has only one element, reset the queue after deleting it
        if (front == rear) {
            front = -1;
            rear = -1; 
        } else {
            // Circular increment
            front = (front + 1) % SIZE;
        }
        return element;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Front -> %d\n", front);
        printf("Items: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[i]);
        printf("Rear -> %d\n", rear);
    }
}

int main() {
    
    dequeue();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);


    enqueue(60);

    display();


    printf("Deleted element: %d\n", dequeue());

    display();

    enqueue(60);

    display();

    return 0;
}
