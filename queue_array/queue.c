#include<stdio.h>
#define MAX 5
int queue[MAX],front = -1, rear = -1;
void enqueue(int num) {
    if(rear == MAX-1) {
        printf("Queue full!");
        return;
    }
    if(front==-1 && rear==-1) {
        front++;
        rear++;
    } else {
        rear++;
    }
    queue[rear]=num;
}
void dequeue() {
    if(front==rear || front == -1) {
        printf("queue is now empty");
        front=rear=-1;
        return;
    }
    int data = queue[front];
    front++;
}

void print() {
    if(front == -1 & rear == -1) {
        printf("Empty Queue");
    } else {
        for(int i=front; i<=rear; i++) {
        printf(" %d ",queue[i]);
        }
    }
}

void main() {
    int ch, num;
    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display queue\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    enqueue(num);
                    break;
            case 2: dequeue();
                    break;
            case 3: print();
        }
    }
}
