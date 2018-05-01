/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (42.52%)
 * Total Accepted:    106.8K
 * Total Submissions: 251.2K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 * 
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        int nums = (1 << n);
        vector<int> r;
        map<int, int> m;
        r.push_back(0);
        m[0] = 1;
        this->helper(r, m, n);
        return r;
    }
    void helper(vector<int> &r, map<int,int> &m, int n) {
        int cur = r.back();
        for (int i = 0; i<n; i++) {
            int t = cur ^ (1<<i);
            if (m[t] == 1) continue;
            r.push_back(t);
            m[t] = 1;
            if (r.size() == (1<<n)) return;
            this->helper(r, m, n);
            if (r.size() == (1<<n)) return;
            m[t] = 0;
            r.pop_back();
        }
        return;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
