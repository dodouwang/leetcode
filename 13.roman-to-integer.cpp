/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (47.98%)
 * Total Accepted:    223.3K
 * Total Submissions: 464.8K
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int sz = s.length();
        int r = 0;
        int prev = 0;
        for (int i = sz-1; i >= 0; --i) {
            if (m[s[i]] >= prev) {
                r += m[s[i]];
            } else {
                r -= m[s[i]];
            }
            prev = m[s[i]];
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
