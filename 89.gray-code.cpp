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
//        cout << "========== r =========" << endl;
//        for (auto a : r) {
//            cout << a << endl;
//        }
//        cout << "========== m =========" << endl;
//        for (auto a : m) {
//            if (a.second == 1) cout << a.first << endl;
//        }

        if (r.size() == (1<<n)) return;
        int cur = r.back();
        for (int i = 0; i<n; i++) {
            int t = cur ^ (1<<i);
            if (m[t] == 1) continue;
            r.push_back(t);
            m[t] = 1;
            this->helper(r, m, n);
            if (r.size() == (1<<n)) return;
            m[t] = 0;
            r.pop_back();
        }
        return;
    }
};
