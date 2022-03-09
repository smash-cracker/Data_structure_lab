#include<stdio.h>
#include<stdlib.h>
int visited[10], G[10][10],v;

void DFS(int i) {
    printf("%d ",i);
    visited[i]=1;
    for(int j=0; j<v;j++) {
        if(G[i][j] && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    int s;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            scanf("%d",&G[i][j]);
        }
    } 
    printf("Enter starting vertex: ");
    scanf("%d",&s);
    DFS(s-1);
 }
