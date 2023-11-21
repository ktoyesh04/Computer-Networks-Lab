#include<stdio.h>
#define MAX 20
#define INF __INT_MAX__


struct node
{
    unsigned dist[MAX], from[MAX];
}rt[MAX];


int main(){
    int cost[MAX][MAX]={{0, 2, INF, INF, 11, 5},
                        {2, 0, 3, INF, INF, 6},
                        {INF, INF, 12, 0, 10, 8},
                        {INF, 3, 0, 12, INF, 4},
                        {11, INF, INF, 10, 0, 7},
                        {5, 6, 4, 8, 7, 0}}, nodes=6, i, j, k, count;
    // printf("Enter number of nodes:");
    // scanf("%d",&nodes);
    // printf("Enter cost matrix:");
    for(i=0; i<nodes; i++)
        for(j=0; j<nodes; j++){
            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }

    do{
        count = 0;
        for(i=0; i<nodes; i++)
            for(j=0; j<nodes; j++)
                for(k=0; k<nodes; k++)
                    if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j]){
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }

    }while(count!=0);

    for(i=0;i<nodes;i++){
        printf("\n\nfor router %d\n", i+1);
        for(j=0; j<nodes; j++)
            printf("\t\nnode %d via %d distance %d", j+1, rt[i].from[j]+1, rt[i].dist[j]);
    }

    return 0;
}
