/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (42.91%)
 * Total Accepted:    190.2K
 * Total Submissions: 443K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
class Solution {
public:
    // 直接计算，时间O(m*n)，优化空间O(min(m,n))，空间可优化，考虑(n+m)! / m! / n!，O(1)即可
    int uniquePaths(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        vector<int> v(m, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                v[j] += v[j-1];
            }
        }
        return v[m-1];
    }
    // 直接计算，时间O(m*n)，空间O(m*n)，空间可优化
    int uniquePaths2(int m, int n) {
        vector<int> vv(m, 1);
        vector<vector<int>> v(n, vv);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[n-1][m-1];
    }
    // 递归做法，慢
    map<pair<int, int>, int> m;
    int uniquePaths1(int m, int n) {
        pair<int, int> p2w(m,n);
        pair<int, int> p2q;        
        if (m == 1 || n == 1) {
            this->m[p2w] = 1;
            return 1;
        }

        p2q = make_pair(m-1, n);
        int r1 = this->m[p2q] ? this->m[p2q] : this->uniquePaths(m-1,n);
            
        p2q = make_pair(m, n-1);
        int r2 = this->m[p2q] ? this->m[p2q] : this->uniquePaths(m,n-1);
            
        int r = r1 + r2;
        this->m[p2w] = r;
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
