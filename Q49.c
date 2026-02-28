/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure of ListNode
struct ListNode {
    int val;
    struct ListNode *next;
};

// Insert at end
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

// Create cycle at given position
void createCycle(struct ListNode* head, int pos) {
    if (pos == -1) return;

    struct ListNode *temp = head;
    struct ListNode *cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    temp->next = cycleNode;  // connect last node to cycleNode
}

// Detect cycle (Floyd’s Algorithm)
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n, value, pos;
    struct ListNode* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input node values
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    // Input position to create cycle
    // (Enter -1 if no cycle)
    scanf("%d", &pos);

    createCycle(head, pos);

    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}