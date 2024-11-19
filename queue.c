#include <stdio.h>
#include <stdlib.h>

int front=-1 , rear=-1;

int queue[10];


void enqueue(int data) {
    if(rear>=9) {
        printf("Queue is full\n");
        return;
    }
    if(front ==-1 && rear==-1) {
        front=rear=0;
        queue[rear]=data;
    }
    else {
        rear=rear+1;
        queue[rear]=data;
        printf("successful\n");
    }

}

void dequeue() {
    if(front==-1 && rear==-1) {
        printf("Queue is empty\n");
        return;
    }
    int ele=queue[front];
    front=front+1;
    printf("successful %d dequeued!\n",ele);
}

void display() {
    if(front==-1 && rear==-1) {
        printf("Queue is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, val;
    while(1) {
        printf("1.enqueue\n2. dequeue\n3. display\n4. exit\nenter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("enter value to enqueue:");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting...\n");
            exit(0);
            default:
                printf("wrong choice\n");
        }
    }
}
