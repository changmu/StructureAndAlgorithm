// Determine if a Sudoku is valid 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool blocks[9][9] = {false};
        
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                int x = board[i][j] - '1';

                if (rows[i][x]) return false;
                rows[i][x] = true;
                if (cols[j][x]) return false;
                cols[j][x] = true;

                int y = i / 3 * 3 + j / 3;
                if (blocks[y][x]) return false;
                blocks[y][x] = true;
            }

        return true;
    }
};
