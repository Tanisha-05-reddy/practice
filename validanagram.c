bool isAnagram(char* s, char* t) {
    int i, n, m;
    int count[256] = {0};

    n = strlen(s);
    m = strlen(t);

    if (n != m)
        return false;

    for (i=0; i<n; i++)
    {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }

    for (i=0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
    
}