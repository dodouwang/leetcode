/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (36.74%)
 * Total Accepted:    188K
 * Total Submissions: 511.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        string r = "1";
        for (int i = 1; i < n; ++i) {
            int sz = r.size();
            string cur = "";
            int len = 0;
            for (int j = 0; j < sz; ++j) {
                len++;
                if (j == sz - 1) {
                    cur += ('0' + len);
                    cur += r[j];
                } else {
                    if (r[j] != r[j+1]) {
                        cur += ('0' + len);
                        cur += r[j];
                        len = 0;
                    }
                }
            }
            r = cur;
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
