#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX], front=-1, rear=-1;

void enqueue(int x){
    if((front==0 && rear==MAX-1) || (rear+1)%MAX==front)
        printf("Overflow\n");
    else{
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        cq[rear]=x;
        printf("%d enqueued\n",x);
    }
}
void dequeue(){
    if(front==-1) printf("Underflow\n");
    else{
        printf("%d dequeued\n",cq[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}
void display(){
    if(front==-1) printf("Empty\n");
    else{
        int i=front;
        while(1){
            printf("%d ",cq[i]);
            if(i==rear) break;
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Enq 2.Deq 3.Display 4.Exit : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}




