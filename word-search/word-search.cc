class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> acc(board.size(), vector<bool>(board[0].size(), false));
        int d = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    acc[i][j] = true;
                    if (tryNeighbors(i, j, board, acc, word, d+1)) {
                        return true;
                    }
                    acc[i][j] = false;
                }
            }
        }
        return false;
    }

    bool
    tryNeighbors(const int x, const int y, const vector<vector<char>> &board, vector<vector<bool>> &acc, const string &word, int d) {
        if (d == word.length()) {
            return true;
        }
        int rowLen = board.size();
        int colLen = board[0].size();
        if (x - 1 >= 0 && acc[x - 1][y] == false && board[x - 1][y] == word[d]) {
            acc[x - 1][y] = true;
            if (tryNeighbors(x - 1, y, board, acc, word, d + 1)) {
                return true;
            }
            acc[x - 1][y] = false;
        }
        if (x + 1 < rowLen && acc[x + 1][y] == false && board[x + 1][y] == word[d]) {
            acc[x + 1][y] = true;
            if (tryNeighbors(x + 1, y, board, acc, word, d + 1)) {
                return true;
            }
            acc[x + 1][y] = false;
        }
        if (y - 1 >= 0 && acc[x][y - 1] == false && board[x][y - 1] == word[d]) {
            acc[x][y - 1] = true;
            if (tryNeighbors(x, y - 1, board, acc, word, d + 1)){
                return true;
            }
            acc[x][y - 1] = false;
        }
        if (y + 1 < colLen && acc[x][y + 1] == false && board[x][y + 1] == word[d]) {
            acc[x][y + 1] = true;
            if (tryNeighbors(x, y + 1, board, acc, word, d + 1)){
                return true;
            }
            acc[x][y + 1] = false;
        }
        return false;
    }

};