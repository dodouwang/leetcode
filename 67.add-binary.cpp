/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (34.14%)
 * Total Accepted:    199.1K
 * Total Submissions: 583.1K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        string &r = la > lb ? a : b;
        int lr = la > lb ? la : lb;
        string &d = la > lb ? b : a;
        int ld = la > lb ? lb : la;
        int added = 0;
        int i = 0;
        for (; i < ld; ++i) {
            int tmp = (d[ld-1-i] - '0') + (r[lr-1-i] - '0') + added;
            if (tmp > 1) {
                r[lr-1-i] = '0' + tmp - 2;
                added = 1;
            } else {
                r[lr-1-i] = '0' + tmp;
                added = 0;
            }
        }

        if (added == 0) {
            return r;
        }
        for (; i < lr; ++i) {
            int tmp = (r[lr-1-i] - '0') + added;
            if (tmp > 1) {
                r[lr-1-i] = '0' + tmp - 2;
                added = 1;
            } else {
                r[lr-1-i] = '0' + tmp;
                added = 0;
                break;
            }
        }
        if (added > 0) {
            r = '1' + r;
        }

        return r;
        
    }
};
