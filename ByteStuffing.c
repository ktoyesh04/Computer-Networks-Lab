#include<stdio.h>
#define MAX 20
#define ESC 'E'
#define FLAG 'F'
#define NULL '\0'

void stuff(char ip[], char stuffed[]){
    int i, j;
    stuffed[0] = FLAG;
    for(i=0, j=1; ip[i] != NULL; i++, j++){
        if(ip[i] == ESC || ip[i] == FLAG) stuffed[j++] = ESC;
        stuffed[j] = ip[i];
    }
    stuffed[j] = FLAG;
    stuffed[j+1] = NULL;
}

void destuff(char ip[], char destuffed[]){
    int i, j;
    for(i=1, j=0; ip[i] != NULL; i++, j++){
        if(ip[i] == ESC) i++;
        destuffed[j] = ip[i];
    }
    destuffed[j-1] = NULL;
}

int main(){
    char ip[MAX], stuffed[MAX*2 + 2], destuffed[MAX];

    printf("Enter string: ");
    gets(ip);

    stuff(ip, stuffed);
    printf("String after stuffing: %s\n", stuffed);
    
    destuff(stuffed, destuffed);
    printf("String after de-stuffing: %s", destuffed);

    return 0;
}
