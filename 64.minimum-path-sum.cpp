/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (40.93%)
 * Total Accepted:    148.5K
 * Total Submissions: 362.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 1;
        }
        int m = grid[0].size();

        vector<int> v(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    v[j] = grid[i][j];
                } else if (j == 0) {
                    v[j] += grid[i][j];
                } else if (i == 0) {
                    v[j] = grid[i][j] + v[j-1];
                } else {
                    v[j] = grid[i][j] + min(v[j-1], v[j]);
                }
            }
        }
        return v[m-1];
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
