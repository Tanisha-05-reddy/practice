#include <string.h>
#include <stdlib.h>

char * removeOuterParentheses(char * s){
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int result_index = 0;
    int balance = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            if (balance > 0) {
                result[result_index++] = s[i];
            }
            balance++;
        } else {
            balance--;
            if (balance > 0) {
                result[result_index++] = s[i];
            }
        }
    }
    
    result[result_index] = '\0';
    return result;
}