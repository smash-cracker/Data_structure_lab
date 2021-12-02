#include<stdio.h>
#define MAX 50
void push(int *stack, int *top, int num) {
    if(*top == MAX-1) {
        printf("Stack overflow");
        return;
    } 
    (*top)++;
    *(stack+(*top)) = num;
    printf("Inserted successfully!");
    printf("\n");
}
void pop(int *stack,int *top) {
    if(*top == -1) {
        printf("Stack underflow");
        return;
    }  
    int data = *(stack+(*top));
    (*top)--;
    printf("%d Deleted successfully!",data);
    printf("\n");
}
void print(int *stack, int top) {
    if(top == -1) {
        printf("Empty stack");
        return;
    }
    printf("\n");  
    for(int i=0;i<=top; i++) {
        printf("%d ",*(stack+i));
    }
}

void main() {
    int stack[MAX],top=-1,ch,num;
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display stack\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    push(stack, &top, num);
                    break;
            case 2: pop(stack,&top);
                    break;
            case 3: print(stack,top);
        }
    }
}