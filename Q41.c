/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, count = 0;

    // Using simple array as hash (for small constraints)
    // Range assumed from -10000 to 10000
    int hash[20001] = {0};

    // To handle negative index
    int offset = 10000;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            count++;

        if(hash[sum + offset] > 0)
            count += hash[sum + offset];

        hash[sum + offset]++;
    }

    printf("%d", count);

    return 0;
}