#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node *head = NULL,*temp,*temp2, *new_node;

void insertBeg(int d) {
    struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}

void insertPos(int d, int pos) {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    temp = head;
    if(pos==1) {
        new_node->next = head;
        head = new_node;
        return;
    }
    for(int i=1; i<pos-1; i++) {
            temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertEnd(int d) {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new_node;
}
void printList(struct Node* n)
{
    printf("\n");
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

void delete(int d) {
    if(head->data==d) {
    head = head->next;
    return;
    }
    temp = head;
    while(temp->data!=d) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
} 

void deleteEnd() {
    temp = head;
    while(temp->next!=NULL) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
}

void main()
{
	int c,d,pos,n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n;i++) {
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&d);
        if(i==0)
            insertBeg(d);
        else
            insertEnd(d);
    }
    printf("\n1. Create a node at beginning\n2. Create node at position\n3. Create node at end\n4. Delete an element\n5. Delete an element from beginning\n6. Delete an element at end\n7. Display");
    while(1) {
    printf("\nchoice :");
    scanf("%d",&c);
    switch(c) {
            case 1: printf("Enter data of node: ");
                    scanf("%d",&d);
                    insertBeg(d);
                    break;
            case 2: printf("Enter data of node: ");
                    scanf("%d",&d);
                    printf("Enter position of node: ");
                    scanf("%d",&pos);
                    insertPos(d,pos);
                    break;
            case 3: printf("Enter data of node: ");
                    scanf("%d",&d);
                    insertEnd(d);
                    break;     
            case 4: printf("Enter data of node to delete: ");
                    scanf("%d",&d);
                    delete(d);
                    break;
            case 5:delete(head->data);
                    break;
            case 6:deleteEnd();
                    break;
            case 7: printList(head);
                    break;
            
        }
    }
}
