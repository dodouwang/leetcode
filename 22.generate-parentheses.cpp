/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (47.93%)
 * Total Accepted:    203.5K
 * Total Submissions: 424.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string pre = "";
        vector<char> v;
        return this->getR(pre, v, 2*n, n);
    }

    vector<string> getR(string pre, vector<char> v, int aim_len, int left) {
        int pre_len = pre.length();
        if (pre_len == aim_len) {
            vector<string> r = {pre};
            return r;
        }
        if (left == 0) {
            for (int i = 0; i < aim_len - pre_len; ++i) {
                pre += ')';
            }
            vector<string> r = {pre};
            return r;
        }

        vector<char> v1 = v;
        v1.push_back('(');
        vector<string> a1 = this->getR(pre+'(', v1, aim_len, left-1);

        if (v.size() == 0 || v.back() != '(') {
            return a1;
        }

        v.pop_back();
        vector<string> a2 = this->getR(pre+')', v, aim_len, left);
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
