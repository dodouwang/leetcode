/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (41.43%)
 * Total Accepted:    143.3K
 * Total Submissions: 346K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> r_in;
        vector<vector<int>> r;
        if (k == 0) {
            r.push_back(r_in);
            return r;
        }

        if (n < k) {
            return r;
        } else if (n == k) {
            for (int i = 0; i < n; ++i) {
                r_in.push_back(i+1);
            }
            r.push_back(r_in);
            return r;
        } else {
            r = this->combine(n-1, k);
            vector<vector<int>> tmp = this->combine(n-1,k-1);
            for (auto &a :tmp) {
                a.push_back(n);
            }
            r.insert(r.end(), tmp.begin(), tmp.end());
            return r;
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
