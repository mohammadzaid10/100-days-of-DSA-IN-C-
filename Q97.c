#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) { // only non-leaf nodes
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left])
            return false;

        // Check right child
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}