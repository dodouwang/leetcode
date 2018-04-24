/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.79%)
 * Total Accepted:    238.8K
 * Total Submissions: 600.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        int added = 1;
        for (int i = n-1; i >= 0; i--) {
            v[i] = v[i] + added;
            if (v[i] > 9) {
                v[i] -= 10;
                added = 1;
            } else {
                added = 0;
                break;
            }
        }
        if (added == 0) {
            return v;
        } else {
            v.push_back(0);
            for (int i = n-1; i >= 0; i--) {
                v[i+1] = v[i];
            }
            v[0] = 1;
            return v;
        }

        
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
