/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.*/
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct ListNode
{
    int data;
    struct ListNode *next;
};

// Function to detect cycle and return starting node
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)   // Cycle detected
        {
            // Step 2: Find starting node of cycle
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Start of cycle
        }
    }

    return NULL;  // No cycle
}

int main()
{
    struct ListNode *head = NULL, *temp = NULL, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++)
    {
        newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // For testing purpose: manually create a cycle
    // Example: connect last node to 2nd node
    if (head != NULL && head->next != NULL)
    {
        temp->next = head->next;  // Creates cycle
    }

    struct ListNode *cycleStart = detectCycle(head);

    if (cycleStart != NULL)
        printf("Cycle starts at node with data: %d\n", cycleStart->data);
    else
        printf("No cycle found\n");

    return 0;
}