//find the index of the first occurence in a string
int strStr(char* haystack, char* needle) {
    if (!*needle) return 0; 
    for (int i = 0; haystack[i]; i++) {
        int j = 0;
        while (needle[j] && haystack[i + j] == needle[j]) {
            j++;
        }
        if (!needle[j]) return i;
    }
    return -1;  
}