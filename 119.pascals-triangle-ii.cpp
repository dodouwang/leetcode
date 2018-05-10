/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (38.42%)
 * Total Accepted:    146.4K
 * Total Submissions: 381K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1, 1);
        for (int i = 1; i < rowIndex ; ++i) {
            for (int j = i; j > 0; --j) {
                r[j] += r[j-1];
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
