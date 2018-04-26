/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (36.56%)
 * Total Accepted:    138.4K
 * Total Submissions: 378.4K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    // O(2),还可以继续优化到O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        if (n == 0) {
            return;
        }
        size_t m = matrix[0].size();
        if (m == 0) {
            return;
        }
        bool row_0_has_0 = false;
        bool col_0_has_0 = false;

        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) {
                row_0_has_0 = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) {
                col_0_has_0 = true;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = n-1; i > 0; --i) {
            for (int j = m-1; j > 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row_0_has_0) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col_0_has_0) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
    void setZeroes1(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        if (n == 0) {
            return;
        }
        size_t m = matrix[0].size();
        if (m == 0) {
            return;
        }

        vector<int> row(n, 1);
        vector<int> col(m, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (row[i] == 0) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (col[i] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        return;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
