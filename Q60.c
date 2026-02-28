/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to check palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Step 1: Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* secondHalf = reverse(slow);
    struct ListNode* firstHalf = head;

    // Step 3: Compare both halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    struct ListNode *head = NULL, *temp = NULL, *newnode;
    int n, i;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++) {
        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newnode->val);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Check palindrome
    if (isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}