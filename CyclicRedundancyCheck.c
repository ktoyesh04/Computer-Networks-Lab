#include<stdio.h>
#include<string.h>
#define MAX 25

char message[MAX], generator[MAX], checkValue[MAX];
int msgLen, genLen;

void XOR(){
    int i;
    for(i=0; i<genLen; i++){
        checkValue[i] = (checkValue[i]==generator[i])? '0':'1';
    }
}

void CRC(){
    int i, j, k;

    for(i=0; i<genLen ;i++){
        checkValue[i] = message[i];
    }

    do{
        if(checkValue[0]=='1'){
            XOR();
        }
        for(j=0; j<genLen-1; j++){
            checkValue[j]=checkValue[j+1];
        }
        checkValue[j]=message[i++];
    }while(i<=msgLen+genLen-1);
}


void receiveMessage(){
    int i;

    printf("\nEnter the received message: ");
    scanf("%s", message);

    CRC();

    for(i=0; (i<genLen-1) && checkValue[i]!='1'; i++);

    if(i<genLen-1){
        printf("\nError Detected");
    }
    else{
        printf("\nNo error");
    }
}

int main(){
    int i;

    printf("Enter message: ");
    scanf("%s", message);
    printf("EFnter gfn: ");
    scanf("%s", generator);

    msglen = strlen(message);
    genLen = strlen(generator);

    for(i=msgLen; i<msgLen+genLen-1; i++){
        message[i] = '0';
    }
    printf("\nmessage after appending zeroes: %s", message);

    CRC();
    printf("\nCRC is: %s", checkValue);

    for(i=msgLen; i<msgLen+genLen-1; i++){
        message[i] = checkValue[i-msgLen];
    }

    printf("\nFinal message to be sent: %s", message);

    receiveMessage();

    return 0;
}
