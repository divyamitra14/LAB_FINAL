#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front=-1;
int rear=-1;

void enqueue(int data) {
    if((rear+1)%5==front) {
        printf("Queue is full\n");
        return;
    }
    if(front ==-1 && rear==-1) {
        front=rear=0;
        queue[rear]=data;
        printf("%d is enqueued.\n",queue[rear]);
    }
    else {
        rear=(rear+1)%5;
        queue[rear]=data;
        printf("%d is enqueued.\n",queue[rear]);
    }

}

void dequeue() {
    if(front==-1 && rear==-1) {
        printf("Queue is empty\n");
        return;
    }
    int ele=queue[front];
    printf("%d is dequeued.\n", ele);
    front=(front+1)%5;
}

void display() {
    if(front==-1 && rear==-1) {
        printf("Queue is empty\n");
    }
    else {
        int i=front;
        while(1) {
            printf("%d ",queue[i]);
            if(i==rear) {
                break;
            }
            i=(i+1)%5;
        }
        printf("\n");
    }
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
