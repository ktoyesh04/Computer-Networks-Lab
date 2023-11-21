#include<stdio.h>
#include<stdlib.h>

int main(){
    int pkt_size = 5000, header_size = 20, MTU = 1500, offset, f_no = 1, sent=0;
    // printf("Enter packet size: ");
    // scanf("%d", &pkt_size);
    // printf("Enter header size: ");
    // scanf("%d", &header_size);
    // printf("Enter MTU: ");
    // scanf("%d", &MTU);
    pkt_size -= header_size;
    MTU -= header_size;

    int n = pkt_size/MTU;
    n = pkt_size % MTU != 0?  n+1: n;
    printf("Number of fragments: %d\n", n);

    for(f_no = 1; f_no <n; f_no++){
        printf("Fragment number: %d, Packet Size: %d, Offset: %d, MF: %d\n", f_no, MTU, sent, 1);
        sent += MTU;
    }
    printf("Fragment number: %d, Packet Size: %d, Offset: %d, MF: %d", f_no, pkt_size-sent, sent, 0);
    return 0;
}
