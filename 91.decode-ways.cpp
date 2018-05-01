/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.37%)
 * Total Accepted:    171.1K
 * Total Submissions: 840.1K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        // calc s[2];
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        int pp = 1;
        int p = 1;
        int r = 1;

        for (int i = 1; i <= n-1; i++) {
            int one = (p > 0 && s[i] != '0') ? p : 0;
            int two =  (pp > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))) ? pp : 0;
            r = one + two;
            if (r == 0) break;
            pp = p;
            p = r;
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
