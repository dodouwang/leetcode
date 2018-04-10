/*
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (46.16%)
 * Total Accepted:    138.9K
 * Total Submissions: 300.6K
 * Testcase Example:  '1'
 *
 * Given an integer, convert it to a roman numeral.
 * 
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int num) {
        int a = num / 1000;
        int b = (num / 100) % 10;
        int c = (num / 10) % 10;
        int d = num % 10;
        string a_r[] = {"", "M", "MM", "MMM"};
        string b_r[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string c_r[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string d_r[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string s = "";
        s += a_r[a];
        s += b_r[b];
        s += c_r[c];
        s += d_r[d];
        return s;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
