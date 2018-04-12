/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (35.96%)
 * Total Accepted:    149.3K
 * Total Submissions: 415.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return this->calc(candidates, target, 0);
    }
    vector<vector<int>> calc(vector<int>& c, int t, int b) {
        vector<vector<int>> ret;
        if (t == 0) {
            vector<int> tmp;
            ret.push_back(tmp);
            return ret;
        }

        for (int i = b; i < c.size();) {
            int k = i;
            while (k + 1 < c.size() && c[k] == c[k+1]) {
                k++;
            }
            int times = 1;
            while (times <= k - i + 1) {
                if (c[i] * times <= t) {
                    vector<vector<int>> vv = this->calc(c, t - c[i] * times , k+1);
                    if (!vv.empty()) {
                        for (int j = 0; j < vv.size(); ++j) {
                            int times_tmp = times;
                            while (times_tmp--) {
                                vv[j].push_back(c[i]);
                            }
                        }
                        ret.insert(ret.end(), vv.begin(), vv.end());
                    }
                } else {
                    break;
                }
                times++;
            }
            i = k + 1;
        }
        return ret;
    }};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
