#include <stdio.h>

int fibonaci(int n) {
    if(n<=1 ) {
        return n;
    }
    return fibonaci(n-1)+fibonaci(n-2);
}

int main() {
    // int n=5;
    // int a=0;
    // int b=1;
    // int next;
    // printf("fibbo sereies:\n");
    // // printf("%d\n%d",a,b);
    // printf("%d\n",a);
    // for(int i=0;i<n;i++) {
    //     printf("%d\n",b);
    //     next=a+b;
    //     a=b;
    //     b=next;
    // }
    // printf("\n");

    int n=5;
    for(int i=0;i<n;i++) {
        printf("%d ",fibonaci(i));
    }
}