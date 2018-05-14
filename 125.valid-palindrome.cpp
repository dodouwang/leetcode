/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.27%)
 * Total Accepted:    228.5K
 * Total Submissions: 838K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isValid(char c) {
        if ((c >= '0' && c <= '9')
            || (c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z')) {
            return true;
        }
        return false;
    }

    bool isEqual(char c, char b) {
        if (c >= '0' && c <= '9')
            return c == b;
        if (c >= 'A' && c <= 'Z')
            return c == b || b-c == 32;
        if (c >= 'a' && c <= 'z')
            return c == b || c-b == 32;
        return false;
    }

    bool isPalindrome(string s) {
        int b = 0;
        int e = s.length() - 1;
        while (b < e) {
            while (b < e && !isValid(s[b])) {
                b++;
            }
            while (b < e && !isValid(s[e])) {
                e--;
            }
            if (b >= e) {
                return true;
            } else if (!isEqual(s[b], s[e])) {
                return false;
            }
            b++;
            e--;
        }
        return true;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
