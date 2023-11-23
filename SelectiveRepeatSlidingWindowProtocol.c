#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct{
    int no;
    int ack;
}Packet;

int main(){
    int i,j,N,M,n,st=0,p=0;
    printf("Selective Repeat\n");
    printf("Number of Packets to be transmitted: ");
    scanf("%d",&N);

    printf("Window Size: ");
    scanf("%d",&M);

    Packet pkt[N];
    for(i=0;i<N;i++){
        pkt[i].no=i+1;
        pkt[i].ack=0;
    }

    srand(time(NULL));
    int x=rand()%N;

    pkt[x].no=-1;
    
    i=0;
    j=i+M-1;
    while(i<N){
        int k=i;
        printf("\nWindow %d\n",++p);
        if(st==1){
            printf("%d ",pkt[n].no);
            i--;
            j--;
            st=0;
        }
        while(k<=j){
            printf("%d ",pkt[k].no);
            if(pkt[k].no==-1 && pkt[k].ack==0){
                pkt[k].no=k+1;
                n=k;
                st=1;
            }
            else{
                pkt[k].ack=(k>=M)?pkt[k-M].no:0;
            }
            k++;
        }
        if(st==1){
            printf("\nRe-Transmission of Frame %d",n+1);
        }
        i=i+M;
        j=((i+M-1)>N-1)?N-1:(i+M-1);
    }
    return 0;
}
