class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int length = matrix.size();
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }

        for (int i = 0, j = length - 1; i < j; ++i, --j) {
            for (int k = 0; k < length; ++k)
                swap(matrix[k][i], matrix[k][j]);
        }
    }
};
