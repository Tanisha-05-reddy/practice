#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }
    
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (top >= 0 && s[i] == ')' && stack[top] == '(') {
            top--;
        } else if (top >= 0 && s[i] == '}' && stack[top] == '{') {
            top--;
        } else if (top >= 0 && s[i] == ']' && stack[top] == '[') {
            top--;
        } else {
            return false;
        }
    }
    
    return top == -1;
}