const char g_Empty = '.';
const vector<char> full = {
        '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

bool isSolved(const vector<vector<char>> &board) {
    int sum = 0;
    int i,j;
    for (i = 0; i < 9; ++i)
       sum += board[8][i] - '0';
    if (sum != 45)
        return 0;
    sum = 0;

    for (i = 0; i < 9; ++i)
        sum += board[i][8] - '0';
    if (sum != 45)
        return false;
    sum = 0;

    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            sum += board[2 * 3 + i][2 * 3 + j]-'0';
    if(sum != 45)
        return false;
    return true;
}

bool isValid(const vector<vector<char>> &board, int x, int y, const char ch) {
    int i,j;
    for (i = 0; i < 9; ++i) {
        auto val = board[x][i];
        if(y != i && ch == val) {
            return false;
        }
    }

    for (i = 0; i < 9; ++i)
        if(x != i && board[i][y] == ch) {
            return false;
        }

    int startX = x / 3;
    int startY = y / 3;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            auto val = board[3 * startX + i][3 * startY + j];
            if(3*startX+i != x && 3*startY+j != y && val == ch) {
               return false;
            }
        }
    }
    return true;
}

class Solution {
public:
    bool solve(vector<vector<char>> &board, int i, int j) {
        if (i > 8)
            if (isSolved(board))
                return true;

        if (board[i][j] == g_Empty) {
            for (auto &c: full) {
                board[i][j] = c;
                if (isValid(board, i, j, c)) {
                    if (j == 8) {
                        if (solve(board, i + 1, 0))
                            return true;
                    } else {
                        if (solve(board, i, j + 1))
                            return true;
                    }
                }
                board[i][j] = g_Empty;
            }
            return false;
        }
        if (j == 8) {
            if (solve(board, i + 1, 0))
                return true;
        } else {
            if (solve(board, i, j + 1))
                return true;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        solve(board, 0, 0);
    }
};
