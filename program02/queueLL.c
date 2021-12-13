#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node *head = NULL,*temp,*temp2, *new_node;

//Deletion at end
void deQueue() {
    if( head==NULL ) {
        printf("Queue is empty!");
    } else if(head->next == NULL) {
        head=NULL;
    } else {
        temp = head;
        while(temp->next!=NULL) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    }
}

//Insertion at beginning
void enQueue(int d) {
    struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}

void print() {
    temp = head;
    printf("\n");
    if(head==NULL) {
        printf("Empty Queue!");
    } else {
        while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	    }
    }
}

void main() {
    int ch,num;
    while(1) {
        printf("\n1. insertion\n2. deletion\n3. Display Queue\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    enQueue(num);
                    break;
            case 2: deQueue();
                    break;
            case 3: print();
        }
    }
}