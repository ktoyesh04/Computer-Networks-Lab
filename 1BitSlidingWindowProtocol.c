#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int no;
    bool ack;
}Packet;

int main(){
    int i, n, x;

    printf("1-Bit Sliding Window\n");
    printf("Number of Packets to be transmitted: ");
    scanf("%d",&n);

    Packet pkt[n];
    for(i=0; i<n; i++){
        pkt[i].no = i+1;
        pkt[i].ack = 0;
    }

    srand(time(NULL));

    x = rand()%n;
    pkt[x].no = -1;

    i = 0;
    while(i<n){
        printf("%d ",pkt[i].no);
        if(pkt[i].no==-1 && pkt[i].ack==0){
            pkt[i].no=i+1;
            pkt[i].ack=true;
            printf("\nRe-Transmit Packet %d\n",pkt[i].no);
            continue;
        }
        i++;
    }
    printf("\nTransmission Completed!");
    return 0;
}
