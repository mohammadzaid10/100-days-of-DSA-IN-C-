/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to calculate length
int getLength(struct node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection
struct node* findIntersection(struct node* head1, struct node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            head1 = head1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            head2 = head2->next;
    }

    // Traverse both together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;  // Intersection found
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;  // No intersection
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp1 = NULL, *temp2 = NULL, *newnode;
    int n, m, i;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head1 == NULL) {
            head1 = temp1 = newnode;
        } else {
            temp1->next = newnode;
            temp1 = newnode;
        }
    }

    // Second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head2 == NULL) {
            head2 = temp2 = newnode;
        } else {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    /*
      For demonstration:
      Create intersection manually
      Connect last node of second list to 3rd node of first list
    */
    struct node* ptr = head1;
    for (i = 1; i < 2; i++)  // Move to 3rd node (0-based index 2)
        ptr = ptr->next;

    temp2->next = ptr;  // Creating intersection

    // Find intersection
    struct node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}