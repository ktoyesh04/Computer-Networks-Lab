#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 10

void printPath(int predecessor[], int j){
    if(predecessor[j] == -1){
        printf("%d ", j);
        return;
    }
    printPath(predecessor, predecessor[j]);
    printf("-> %d ", j);
}

int findMinDistanceIndex(bool visited[], int distance[], int n){
    int i, min_index=-1, min_distance = INT_MAX;
    for(i=0; i<n; i++)
        if(!visited[i] && distance[i]<min_distance){
            min_index = i;
            min_distance = distance[i];
        }
    return min_index;
}

void dijkstra(int matrix[][10], int source, int destination, int n){
    int i, j, min_index, min_val;
    int distance[n];
    bool visited[n];
    int predecessor[n];
    for(i=0; i<n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[source] = 0;
    predecessor[source] = -1;
    for(i=0; i<n-1 && !visited[destination]; i++){
        min_index = findMinDistanceIndex(visited, distance, n);
        visited[min_index] = true;
        for(j=0; j<n; j++)
            if(!visited[j] && matrix[min_index][j] != 0 && distance[min_index] != INT_MAX && distance[j]>matrix[min_index][j]+distance[min_index]){
                distance[j] = matrix[min_index][j]+distance[min_index];
                predecessor[j] = min_index;
            }
    }
    printf("Shortest path from %d to %d: ", source, destination);
    printPath(predecessor, destination);
    printf("\nShortest distance: %d", distance[destination]);
}

int main(){
    int matrix[V][V] = {{0, 4, 0, 0, 0, 0, 0, 0, 8},
                          {4, 0, 8, 0, 0, 0, 0, 0, 11},
                          {0, 8, 0, 0, 7, 4, 2, 0, 0},
                          {0, 0, 0, 0, 9, 10, 0, 0, 0},
                          {0, 0, 7, 9, 0, 14, 0, 0, 0},
                          {0, 0, 4, 10, 14, 0, 0, 2, 0},
                          {0, 0, 2, 0, 0, 0, 0, 6, 7},
                          {0, 0, 0, 0, 0, 2, 6, 0, 1},
                          {8, 11, 0, 0, 0, 0, 7, 1, 0}};
    int n = 9;
    int start = 0;
    int destination = 3;
    dijkstra(matrix, start, destination, n);
    return 0;
}
