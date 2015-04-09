bool isPalindrome(char *s) {
    if (s == NULL || *s == '\0')
        return true;

    int len = strlen(s);
    int i = 0, j = len - 1;

    while (i < j) {
        while (i < j && isalnum(s[i]) == false)
            ++i;
        while (i < j && isalnum(s[j]) == false)
            --j;
        if (i < j && tolower(s[i++]) != tolower(s[j--]))
            return false;
    }

    return true;
}
