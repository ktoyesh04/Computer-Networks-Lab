#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

typedef struct{
    int no;
    bool ack;
}Packet;

int main(){
    int i,j,N,windowSize,n,st=0,p=0;
    printf("Go-Back N\n");
    printf("Number of Packets to be transmitted: ");
    scanf("%d",&N);

    Packet pkt[N];
    for(i=0;i<N;i++){
        pkt[i].no=i+1;
        pkt[i].ack=false;
    }
    
    srand(time(NULL));

    printf("Window Size: ");
    scanf("%d",&windowSize);

    int x=rand()%N;
    pkt[x].no=-1;
 
    i=0;
    j=i+windowSize-1;
    while(i<N && j<N){
        int k=i;
        printf("\nWindow %d\n",++p);
        while(k<=j){
            printf("%d ",pkt[k].no);
            if(pkt[k].no==-1 && pkt[k].ack==0){
                pkt[k].no=k+1;
                n=k;
                st=1;
            }
            else{
                pkt[k].ack=(k>=windowSize)?true:false;
            }
            k++;
        }
        if(st==1){
            printf("\nRe-Transmission from Frame %d",n+1);
            i = n;
        }
        else{
            i += windowSize;
        }

        st=0;
        j=((i+windowSize-1)>N-1)?N-1:(i+windowSize-1);
    }
    return 0;
}
