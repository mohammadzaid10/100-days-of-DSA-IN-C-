/*Given the head of a singly linked list, reverse the list, and return the reversed list. leet  code version*/
#include <stdio.h>
#include <stdlib.h>

// Definition of ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;   // store next
        curr->next = prev;      // reverse pointer
        prev = curr;            // move prev
        curr = nextNode;        // move current
    }

    return prev;   // new head
}

// Function to insert at end
struct ListNode* insert(struct ListNode* head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct ListNode* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Original List: ");
    printList(head);

    // Reverse list
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}