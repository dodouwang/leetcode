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
    // 如果满足什么条件就继续 可以变成如果满足什么条件就break。
    // 后者有时候会简单些，因为往往前者需要满足条件之后再做点什么再进入下一个循环
    void calc_in(vector<int> &v, int tmp, int pp) {
        int added = pp;
        while (tmp < v.size()) {
            v[tmp] += added;
            if (v[tmp] < 10) {
                break;
            }
            v[tmp] -= 10;
            added = 1;
            tmp++;
        }
    }
    void calc(vector<int> &v, int aim, int p) {
        this->calc_in(v, aim, p % 10);
        this->calc_in(v, aim+1, p / 10);
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        string r = "";
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2;
        vector<int> v(len, 0);
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                this->calc(v, i+j, (num1[len1-1-i] - '0')*(num2[len2-1-j] - '0'));
            }
        }

        int i = len - 1;
        while (i >= 0 && v[i] == 0) {
            i--;
        }

        for (; i >= 0; --i) {
            r += ('0' + v[i]);
        }

        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
