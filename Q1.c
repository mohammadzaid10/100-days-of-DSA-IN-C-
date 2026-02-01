/**Insert an Element in an Array

//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

//Input:
//- First line: integer n
//- Second line: n space-separated integers (the array)
//- Third line: integer pos (1-based position)
//- Fourth line: integer x (element to insert)

//Output:
//- Print the updated array (n+1 integers) in a single line, space-separated

//Example:
//Input:
//5
//1 2 4 5 6
//3
//3

//Output:
//1 2 3 4 5 6

//Explanation: Insert 3 at position 3, elements [4,5,6] shift right **/

#include <stdio.h>

int main() {
    int n, pos, x;

    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    // Size n+1 to accommodate the new element
    int arr[n + 1]; 

    // 2. Read the initial array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read the position and the value to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // 4. Shift elements to the right
    // We start from the end and move backwards to avoid overwriting values
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // 5. Insert the new element at (pos - 1) because C uses 0-based indexing
    arr[pos - 1] = x;

    // 6. Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
