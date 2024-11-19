#include <stdio.h>

int power(int base, int exp) {
    int res=1;
    for(int i=1;i<=exp;i++) {
        res=res*base;
    }
    return res;
}
int power_rec(int base, int exp) {
    if (exp==0) {
        return 1;
    }
    if(exp==1) {
        return base;
    }
    return base*power_rec(base,exp-1);
}

int main() {
    int base,exp;
    printf("Enter base number: ");
    scanf("%d",&base);
    printf("Enter exponent: ");
    scanf("%d",&exp);
    printf("%d ^ %d=%d",base,exp,power(base,exp));
    printf("\n");
    printf("%d^%d=%d",base,exp,power_rec(base,exp));
}