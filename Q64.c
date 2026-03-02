/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 1000

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int stack1[MAX], stack2[MAX];
    int top1 = -1, top2 = -1;
    
    // Push all digits of l1 into stack1
    while(l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    // Push all digits of l2 into stack2
    while(l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* head = NULL;
    
    // Pop from stacks and add
    while(top1 >= 0 || top2 >= 0 || carry != 0) {
        
        int sum = carry;
        
        if(top1 >= 0)
            sum += stack1[top1--];
        
        if(top2 >= 0)
            sum += stack2[top2--];
        
        carry = sum / 10;
        
        // Create new node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        
        // Insert at beginning
        newNode->next = head;
        head = newNode;
    }
    
    return head;
}