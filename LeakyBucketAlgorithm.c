#include<stdio.h>

int main(){
    int bucketSize, pktsLost, pktsTransmitted, pktsInBucket, leakRate, 
        transmissionRate, extraPkts, remainingPkts, choice=1;
    
    printf("Enter bucket size:");
    scanf("%d", &bucketSize);
    printf("Enter leak rate:");
    scanf("%d", &leakRate);

    pktsInBucket = 0;

    do{
        printf("Enter transmission rate: ");
        scanf("%d", &transmissionRate);

        if(transmissionRate >= leakRate){
            remainingPkts = transmissionRate - leakRate;
            pktsTransmitted = leakRate;
            pktsLost = remainingPkts - (bucketSize - pktsInBucket);
            pktsInBucket += remainingPkts;
            if(pktsLost>0) pktsInBucket -= pktsLost;
            else pktsLost = 0;
        }
        else{
            extraPkts = leakRate - transmissionRate;
            pktsLost = 0;
            if(pktsInBucket < extraPkts){
                pktsTransmitted = pktsInBucket + transmissionRate;
                pktsInBucket = 0;
            }
            else{
                pktsTransmitted = extraPkts + transmissionRate;
                pktsInBucket -= extraPkts;
            }
        }
        printf("Packets Transmitted:%d\tPackets Lost:%d\tPackets in Bucket:%d\n", pktsTransmitted, pktsLost, pktsInBucket);
        printf("Another transmission?0/1: ");
        scanf("%d", &choice);
    }while(choice);
    printf("Successfully executed!");
    return 0;
}
