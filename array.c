#include <stdio.h>
#include <stdlib.h>

int size=100;
int array[100];

void insertion(int arr[],int val, int *s) {
    if(*s>size) {
        printf("Error in insertion\n");
        return;
    }
    arr[*s]=val;
    (*s)++;
    printf("pushed!!\n");
}

void insertionatpos(int arr[],int val,int pos, int *s) {
    if(*s>size) {
        printf("Error in insertion\n");
        return;
    }
    if(pos>=size || pos<0) {
        printf("Error in insertion\n");
    }
    for(int i=*s;i>pos;i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    *s=*s+1;
    printf("pushed!!\n");

}

void deletion(int arr[],int val,int *s) {
    if(*s==0) {
        printf("array is empty!");
    }
    for(int i=0;i<*s;i++){
        if(arr[i]==val) {
            for(int j=i;j<*s-1;j++) {
                arr[j]=arr[j+1];
            }
            (*s)--;
            printf("deleted!!\n");
            break;
        }
    }
}

void display(int arr[],int s) {
    printf("The elements in the array are:\n");
    for(int i=0;i<s;i++) {
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

int main() {
    int s;
    printf("enter the size of array:");
    scanf("%d", &s);
    printf("enter the elements of array:\n");
    for(int i=0;i<s;i++) {
        scanf("%d",&array[i]);
    }
    printf("Array is:");
    for(int i=0;i<s;i++) {
        printf("%d ",array[i]);
    }
    printf("\n");

    int choice, val;
    while(1) {
        printf("1.insertion\n2. deletion\n3. print\n4. exit\nenter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("enter value to insert:");
                scanf("%d", &val);
                insertion(array,val,&s);
                int pos;
                printf("enter position:");
                scanf("%d", &pos);
                insertionatpos(array,val,pos,&s);
                break;
            case 2:
                printf("enter value to deletion:");
                scanf("%d", &val);
                deletion(array,val,&s);
                break;
            case 3:
                display(array,s);
                break;
            case 4:
                printf("exiting...\n");
                exit(0);
            default:
                printf("wrong choice\n");
        }
    }

}