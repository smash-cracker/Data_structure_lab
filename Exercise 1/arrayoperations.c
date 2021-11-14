#include<stdio.h>

void create(int *arr,int *size) {
    printf("Enter the elements: ");
    for(int i =0; i < (*size); i++)
        scanf("%d",arr+i);
}

void insert(int *arr,int *size, int num, int pos) {
    for(int i=*size;i>=pos;i--)
        *(arr+i)=*(arr+(i-1));
    *(arr+(pos-1))=num;
}

void delete(int *arr, int size, int pos) {
    for(int i=pos-1;i<size-1;i++) {
        *(arr+i)=*(arr+(i+1));
    }
}

int search(int *arr, int size, int num) {
    for(int i=0; i<size; i++) {
        if(*(arr+i) == num)
            return i+1;
    }
    return -1;
}

void display(int *arr,int size) {
    for(int i=0;i<size;i++)
        printf("%d ",*(arr+i));
}

void main() {
    int arr[10],choice,size,num,pos,res;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    create(arr,&size);
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Quit\n Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted: ");
                scanf("%d",&num);
                printf("Enter the position to be inserted: ");
                scanf("%d",&pos);
                insert(arr,&size,num,pos);
                size++;
                break;
        case 2: printf("Enter the element to be deleted: ");
                scanf("%d",&num);
                res = search(arr,size,num);
                if(res!=-1) {
                    delete(arr,size,res);
                    size--;
                } else {
                    printf("Element not found");
                }
                break;
        case 3:  printf("Enter the element to be searched: ");
                scanf("%d",&num);
                res = search(arr,size,num);
                if(res!=-1) {
                    printf("element found at %d",res);
                } else {
                    printf("Element not found");
                }
                break;
        case 4: display(arr,size);
                break;  
        case 5: return;
        }
    }
}
