#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pre;
    struct node *next;
    int data;
};
struct node *head = NULL;
void insertion_beginning();
void insertion_last();
void insert_pos();
void deletion_beginning();
void deletion_last();
void del_pos();
void display();
void main()
{
    int choice = 0, item, loc;
    printf("Enter number of nodes: ");
    scanf("%d",&loc);
    for(int i=0; i<loc;i++) {
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&item);
        if(i==0)
            insertion_beginning(item);
        else
            insertion_last(item);
    }
    while (choice < 9)
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node at position\n7.Display\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Item value: ");
            scanf("%d", &item);
            insertion_beginning(item);
            break;
        case 2:
            printf("\nEnter Item value: ");
            scanf("%d", &item);
            insertion_last(item);
            break;
        case 3:
            printf("Enter the location: ");
            scanf("%d", &loc);
            printf("Enter value");
            scanf("%d", &item);
            insert_pos(item, loc);
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            printf("Enter the location");
            scanf("%d", &loc);
            del_pos(loc);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning(int item)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = head;
    ptr->pre = NULL;
    if (head != NULL)
        head->pre = ptr;
    head = ptr;
}

void insertion_last(int item)
{
    struct node *ptr, *temp = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    if (head == NULL)
    {
        insertion_beginning(item);
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        ptr->pre = temp;
        ptr->next = NULL;
    }
}

void insert_pos(int num, int loc)
{
    int i;
    struct node *newNode, *temp;
    if (head == NULL){
        printf("Error, List is empty!\n");
    } else {
        temp = head;
        i = 1;
        while (i < loc - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (loc == 1) {
            insertion_beginning(num);
        }
        else if (temp != NULL) {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = num;
            newNode->next = temp->next;
            newNode->pre = temp;
            if (temp->next != NULL) {
                temp->next->pre = newNode;
            }
            temp->next = newNode;
            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", loc);
        }
        else{
            printf("Error, Invalid position\n");
        }
    }
}

void deletion_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n Linked List is empty!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->pre = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void deletion_last()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("Node Deleted!\n\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->pre->next = NULL;
        free(temp);
    }
}
void del_pos(int pos)
{
    struct node *temp;
    int i;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    if (pos==1) {
        deletion_beginning();
    } else if(temp != NULL) {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    } else {
        printf("Enter valid position!\n");
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}