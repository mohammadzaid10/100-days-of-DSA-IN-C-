/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

// Function to remove cycle
bool removeCycle(struct node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct node *slow = head, *fast = head;

    // Step 1: Detect cycle using Floyd’s Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // Cycle detected

            // Step 2: Find start of cycle
            slow = head;

            // Special case: cycle starts at head
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Step 3: Break the cycle
            fast->next = NULL;
            return true;
        }
    }

    return false;  // No cycle
}

int main() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i;

    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    /*
      For testing: create a cycle manually
      Connect last node to 2nd node (index 1)
    */
    if (head != NULL && head->next != NULL) {
        temp->next = head->next;   // Creating cycle
    }

    if (removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}