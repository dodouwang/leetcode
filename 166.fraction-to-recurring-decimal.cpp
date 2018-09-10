/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (18.21%)
 * Total Accepted:    71.6K
 * Total Submissions: 387.4K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        map<long, int> m;
        vector<int> v;
        string r = "";
        int sign = 1;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            sign = -1;
        }

        long n = numerator;
        long d = denominator;

        n = abs(n);
        d = abs(d);

        long first_part = n / d;
        long yushu = n % d;

        if (sign == -1) {
            r += "-";
        }
        r += to_string(first_part);

        if (yushu == 0) {
            return r;
        }

        r += ".";

        int loc = 0;
        int old_loc = -1;
        while (yushu > 0) {
            auto iter = m.find(yushu);
            if (iter != m.end()) {
                old_loc = iter->second;
                break;
            }
            m[yushu] = loc++;
            yushu *= 10;
            long cur = yushu / d;
            v.push_back(cur);
            yushu = yushu % d;
        }

        for (int i = 0; i < v.size(); ++i) {
            if (i == old_loc) {
                r += "(";
            }
            r += to_string(v[i]);
        }
        if (old_loc != -1) {
            r += ")";
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

