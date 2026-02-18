/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.*/
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n], answer[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Step 1: Store prefix products in answer[]
    answer[0] = 1;
    for(int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with suffix products
    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix = suffix * nums[i];
    }

    // Print result
    printf("Output array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}
