// Time Complexity: O(m∗4^n) Where m is the number of cells in the board and n is the length of the word.
// This is because in the worst case, we might explore all possible paths in the board (4 directions for each cell) for each character in the word. 
// Space Complexity: O(n) for the recursive call stack, where n is length of the word. In the worst case, we might have to explore a path that is as long as the length of the word, which would require O(n) space for the call stack. 
// Additionally, we are modifying the board in place, so we are not using any extra space for storing the visited cells.
class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        board[r][c] = '#';
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];
        return res;
    }
};