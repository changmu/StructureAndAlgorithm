/************************************************************* 
 * 输出一个字符串的全排列
 * Edit by changmu
 *************************************************************/ 

void PermutationImpl(char *begin_ptr, const char *ori_str)
{
    if (*begin_ptr == '\0') {
        printf("%s\n", ori_str);
        return;
    }

    for (char *cur_ptr = begin_ptr; *cur_ptr != '\0'; cur_ptr++) {
        swap(*cur_ptr, *begin_ptr);
        PermutationImpl(begin_ptr + 1, ori_str);
        swap(*cur_ptr, *begin_ptr);
    }
}

void Permutation(char *str)
{
    if (str == NULL || *str == '\0')
        return;

    PermutationImpl(str, str);
}
