/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.97%)
 * Total Accepted:    318.9K
 * Total Submissions: 938.9K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                v.push_back(s[i]);
            } else {
                if (v.size() == 0) {
                    return false;
                }
                char c = v.back();
                if (s[i] == '}' && c == '{') {
                    v.pop_back();
                } else if (s[i] == ']' && c == '[') {
                    v.pop_back();
                } else if (s[i] == ')' && c == '(') {
                    v.pop_back();
                } else {
                    return false;
                }
            }
        }

        return v.size() == 0;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
