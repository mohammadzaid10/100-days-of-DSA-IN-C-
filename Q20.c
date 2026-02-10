/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/
#include <stdio.h>
#include <stdlib.h>

// comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};

    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    int i = 0, j = 0, k = 0;
    int result[100];

    // sort both arrays
    qsort(nums1, n1, sizeof(int), cmp);
    qsort(nums2, n2, sizeof(int), cmp);

    // two-pointer comparison
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    // print result
    printf("[");
    for (i = 0; i < k; i++) {
        printf("%d", result[i]);
        if (i < k - 1)
            printf(", ");
    }
    printf("]");

    return 0;
}
