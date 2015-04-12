void getNext(char *str, int *next, int len) {
    int i = 0, j = -1;
    next[i] = j;

    while (i < len) {
        if (-1 == j || str[i] == str[j]) {
            if (str[++i] == str[++j]) next[i] = next[j];
            else next[i] = j;
        } else j = next[j];
    }
}

int KMP(char *haystack, char *needle) {
    if (*needle == '\0')
        return 0;
    int len = strlen(needle);
    int *next = (int *) malloc(sizeof(int) * (len + 1));

    getNext(needle, next, len);

    int i = 0, j = 0;
    while (haystack[i] != '\0') {
        if (j == -1 || haystack[i] == needle[j]) {
            ++i;
            if (++j == len)
                return i - len;
        } else j = next[j];
    }

    return -1;
}

int strStr(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL)
        return -1;

    return KMP(haystack, needle);
}
