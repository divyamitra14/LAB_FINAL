#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top=-1;

void push(int data) {
    if(top==9) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=data;
    printf("%d is pushed\n",data);
}

void pop() {
    if(top==-1) {
        printf("Stack Underflow\n");
        return;
    }
    int ele=stack[top];
    top--;
    printf("%d is popped\n",ele);
}
void display() {
    if(top==-1) {
        printf("Stack Underflow\n");
    }
    printf("stack elements are:\n");
    for(int i=top;i>=0;i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}


int main() {
    int choice, val;
    while(1) {
        printf("1.push\n2. pop\n3. display\n4. exit\nenter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("enter value to push:");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
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