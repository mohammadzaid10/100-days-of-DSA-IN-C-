/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1)Open brackets must be closed by the same type of brackets.
2)Open brackets must be closed in the correct order.
3)Every close bracket has a corresponding open bracket of the same type.*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for(int i = 0; i < len; i++) {
        
        // If opening bracket, push
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            // If stack empty → invalid
            if(top == -1) {
                return false;
            }

            // Check matching pair
            if((s[i] == ')' && stack[top] == '(') ||
               (s[i] == '}' && stack[top] == '{') ||
               (s[i] == ']' && stack[top] == '[')) {
                top--; // pop
            }
            else {
                return false;
            }
        }
    }

    // If stack empty → valid
    return top == -1;
}