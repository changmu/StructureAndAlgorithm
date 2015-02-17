/*************************************************************
 * Implement next permutation, which rearranges numbers into 
 * the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as
 * the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and
 * its corresponding outputs are in the right-hand column.
 * 1,2,3 ¡ú 1,3,2
 * 3,2,1 ¡ú 1,2,3
 * 1,1,5 ¡ú 1,5,1
 *************************************************************/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int last = num.size();
        if (last == 0) return;

        int index = last - 2;
        while (index >= 0 && num[index] >= num[index + 1])
            --index;

        if (index == -1) sort(num.begin(), num.end());
        else {
            int index2 = last - 1;
            while (num[index2] <= num[index]) --index2;
            swap(num[index2], num[index]);
            sort(num.begin() + index + 1, num.end());
        }
    }
};
