/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (37.59%)
 * Total Accepted:    152K
 * Total Submissions: 404.3K
 * Testcase Example:  '[[".","8","7","6","5","4","3","2","1"],["2",".",".",".",".",".",".",".","."],["3",".",".",".",".",".",".",".","."],["4",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".",".","."],["6",".",".",".",".",".",".",".","."],["7",".",".",".",".",".",".",".","."],["8",".",".",".",".",".",".",".","."],["9",".",".",".",".",".",".",".","."]]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for (int i = 0; i < 9; ++i) {
            s.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && ((board[i][j] - '0') < 1 || (board[i][j] - '0') > 9)) {
                    return false;
                } else if (board[i][j] == '.') {
                    continue;
                } else {
                    if (s.find(board[i][j]) == s.end()) {
                        s.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }
        for (int j = 0; j < 9; ++j) {
            s.clear();
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.' && ((board[i][j] - '0') < 1 || (board[i][j] - '0') > 9)) {
                    return false;
                } else if (board[i][j] == '.') {
                    continue;
                } else {
                    if (s.find(board[i][j]) == s.end()) {
                        s.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }
        for (int ii = 0; ii < 9; ii+=3) {
            for (int jj = 0; jj < 9; jj+=3) {
                s.clear();
                for (int i = ii; i < ii+3; ++i) {
                    for (int j = jj; j < jj+3; ++j) {
                        if (board[i][j] != '.' && ((board[i][j] - '0') < 1 || (board[i][j] - '0') > 9)) {
                            return false;
                        } else if (board[i][j] == '.') {
                            continue;
                        } else {
                            if (s.find(board[i][j]) == s.end()) {
                                s.insert(board[i][j]);
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
