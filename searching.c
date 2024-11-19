#include <stdio.h>

void binarysearch(int arr[],int key,int low,int high) {
    int found=0;
    while(low<=high) {
        int mid=(low+high)/2;
        if(arr[mid]==key) {
            found=1;
            printf("element found at %d index!",mid);
        }
        if(key<arr[mid]){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    if(!found) {
        printf("element not found");
    }
}

int main() {
    int n=6;
    printf("enter array:\n");
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("\n");

    int key=12;

    binarysearch(arr,key,0,n-1);
}