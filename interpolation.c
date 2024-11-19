#include <stdio.h>

void interpolation(int arr[], int key, int low, int high) {
    int found = 0;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (arr[high] == arr[low]) {
            if (arr[low] == key) {
                printf("Element found at %d index!\n", low);
                return;
            } else {
                break;
            }
        }

        // Interpolation formula
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key) {
            printf("Element found at %d index!\n", pos);
            found = 1;
            break;
        }

        if (key < arr[pos]) {
            high = pos - 1;
        } else {
            low = pos + 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    interpolation(arr, key, 0, n - 1);
    return 0;
}
