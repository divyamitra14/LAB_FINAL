#include <stdio.h>

int gcd(int a,int b) {
    while(b!=0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int gdc_rec(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("GCD of %d and %d is %d",a,b,gcd(a,b));
    printf("\n");
    printf("GCD of %d and %d is %d",a,b,gdc_rec(a,b));

}