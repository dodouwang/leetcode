/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (40.33%)
 * Total Accepted:    172.2K
 * Total Submissions: 426.8K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rr;
        for (int i = 0; i < numRows; ++i) {
            vector<int> r;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    r.push_back(1);
                    continue;
                }                     
                r.push_back(rr[i-1][j-1] + rr[i-1][j]);
            }
            rr.push_back(r);
        }
        return rr;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
