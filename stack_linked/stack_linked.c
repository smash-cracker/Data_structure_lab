#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node *head = NULL,*temp,*temp2, *new_node;

//Deletion at end
void pop() {
    if(head->next == NULL) {
        head=NULL;
    } else if( head==NULL ) {
        printf("Stack is empty!");
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
void push(int d) {
    if(head == NULL) {
         struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
    } else {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new_node;
    }
}

void print(struct Node* n)
{
    printf("\n");
    if(head==NULL) {
        printf("Empty Stack!");
    } else {
        while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
    }
}

void main() {
    int ch,num;
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display stack\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: print(head);
        }
    }
}