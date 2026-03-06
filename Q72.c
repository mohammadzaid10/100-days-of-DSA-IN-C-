/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval()*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char s[]) {
    int stack[1000];
    int top = -1;
    int num = 0;
    char sign = '+';
    
    for (int i = 0; i < strlen(s); i++) {
        
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == strlen(s) - 1) {
            
            if (sign == '+') {
                stack[++top] = num;
            }
            else if (sign == '-') {
                stack[++top] = -num;
            }
            else if (sign == '*') {
                stack[top] = stack[top] * num;
            }
            else if (sign == '/') {
                stack[top] = stack[top] / num;
            }

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    char s[1000];

    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    printf("Result: %d\n", calculate(s));

    return 0;
}