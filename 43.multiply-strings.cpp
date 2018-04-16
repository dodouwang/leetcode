/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (28.01%)
 * Total Accepted:    135.9K
 * Total Submissions: 485K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string r = "";
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2;
        vector<int> v(len, 0);
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                int aim = i + j;
                int loc1 = len1-1-i;
                int loc2 = len2-1-j;
                int n1 = num1[loc1] - '0';
                int n2 = num2[loc2] - '0';
                int p = n1 * n2;
                int a = p % 10;
                int aa = p / 10;
                int tmp = aim;
                int added = a;
                while (tmp < len) {
                    v[tmp] += added;
                    if (v[tmp] < 10) {
                        break;
                    }
                    v[tmp] -= 10;
                    added = 1;
                    tmp++;
                }
                tmp = aim + 1;
                added = aa;
                while (tmp < len) {
                    v[tmp] += added;
                    if (v[tmp] < 10) {
                        break;
                    }
                    v[tmp] -= 10;
                    added = 1;
                    tmp++;
                }
            }
        }

        int i = len - 1;
        while (i >= 0 && v[i] == 0) {
            i--;
        }

        for (; i >= 0; --i) {
            r += ('0' + v[i]);
        }

        if (r == "") {
            return "0";
        }

        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
