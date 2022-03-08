#include<stdio.h>
#include<stdlib.h>
int visited[10];
int a[10][10] = {
    {0,1,1,1,1,0,0,0},
    {1,0,0,0,0,1,0,0},
    {1,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,1,0},
    {0,1,1,0,0,0,0,1},
    {0,0,0,1,1,0,0,1},
    {0,0,0,0,0,1,1,0}
};

void DFS(int i) {
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(int j=0; j<9;j++) {
        if(a[i][j]==1 && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    DFS(0);
 }
