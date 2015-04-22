int myAtoi(char* str) {
    int ret = 0, i = 0, len = strlen(str), sign = 1;

    while (i < len && str[i] == ' ') ++i;
    if (str[i] == '+') ++i;
    else if (str[i] == '-') {
        sign = -1; ++i;
    }

    for ( ; i < len; ++i) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10) {
            if (-1 == sign) return INT_MIN;
            else return INT_MAX;
        }

        ret = ret * 10 + str[i] - '0';
    }

    return sign * ret;
}
