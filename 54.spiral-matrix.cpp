/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.32%)
 * Total Accepted:    141.1K
 * Total Submissions: 516.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if (m == 0) {
            return r;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return r;
        }
        r.assign(matrix[0].begin(), matrix[0].end());
        int mi = 0, ni = n - 1, gap = 1;
        while (true) {
            int down = m - gap;
            if (down == 0) {
                break;
            }
            while (down--) {
                r.push_back(matrix[++mi][ni]);
            }

            int left = n - gap;
            if (left == 0) {
                break;
            }
            while (left--) {
                r.push_back(matrix[mi][--ni]);
            }

            gap++;
            int up = m - gap;
            if (up == 0) {
                break;
            }
            while (up--) {
                r.push_back(matrix[--mi][ni]);
            }

            int right = n - gap;
            if (right == 0) {
                break;
            }
            while (right--) {
                r.push_back(matrix[mi][++ni]);
            }
            gap++;
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
