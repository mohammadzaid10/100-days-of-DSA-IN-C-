/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 10^4*/
#include <stdio.h>
#include <limits.h>

// Function to find maximum circular subarray sum
int maxCircularSum(int arr[], int n) {
    int totalSum = 0;

    int currMax = arr[0], maxSum = arr[0];
    int currMin = arr[0], minSum = arr[0];

    for(int i = 0; i < n; i++) {
        totalSum += arr[i];

        if(i > 0) {
            // Kadane for maximum sum
            if(currMax + arr[i] > arr[i])
                currMax = currMax + arr[i];
            else
                currMax = arr[i];

            if(currMax > maxSum)
                maxSum = currMax;

            // Kadane for minimum sum
            if(currMin + arr[i] < arr[i])
                currMin = currMin + arr[i];
            else
                currMin = arr[i];

            if(currMin < minSum)
                minSum = currMin;
        }
    }

    // If all elements are negative
    if(maxSum < 0)
        return maxSum;

    // Return maximum of normal and circular case
    if(maxSum > totalSum - minSum)
        return maxSum;
    else
        return totalSum - minSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = maxCircularSum(arr, n);

    printf("%d\n", result);

    return 0;
}
