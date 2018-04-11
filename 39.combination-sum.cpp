/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (41.40%)
 * Total Accepted:    214.6K
 * Total Submissions: 518.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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

        for (int i = b; i < c.size(); ++i) {
            if (c[i] <= t) {
                vector<vector<int>> vv = this->calc(c, t - c[i], i);
                if (!vv.empty()) {
                    for (int j = 0; j < vv.size(); ++j) {
                        vv[j].push_back(c[i]);
                    }
                    ret.insert(ret.end(), vv.begin(), vv.end());
                }
            } 
        }
        return ret;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
