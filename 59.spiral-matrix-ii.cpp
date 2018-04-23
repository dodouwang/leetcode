/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (41.11%)
 * Total Accepted:    100.6K
 * Total Submissions: 244.7K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
        vector<int> r_in(n, 0);
        vector<vector<int>> r(n, r_in);
        for (int i = 0; i < n; ++i) {
            r[0][i] = i+1;
        }

        int row = 0, col = n-1, step = n - 1, af = 0;
        int cur_left_step = n - 1;
        int step_played = 0;
        for (int i = n; i < n*n; ++i) {
            row += a[af][0];
            col += a[af][1];
            r[row][col] = i+1;
            cur_left_step--;
            if (cur_left_step == 0) {
                af = (af + 1) % 4;

                step_played++;
                if (step_played == 2) {
                    step_played = 0;
                    step--;
                }
                cur_left_step = step;
            }
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
