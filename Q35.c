/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;   // If k > n

    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    printf("Rotated array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
