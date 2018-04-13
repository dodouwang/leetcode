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

        while (b < c.size()) {
            int cur_value = c[b];
            // 算出当前c[b]的值在之后重复了多少次，并且将b推至下一个不重复的位置
            int times = 0;
            do {
                times++;
                b++;
            } while (b < c.size() && c[b] == cur_value);

            // 重复多少次，就分别用几次当前的cur_value去凑，
            vector<int> cur_added;
            for (int cur_times = 1; cur_times <= times; ++cur_times) {
                int value_sum = cur_value * cur_times;
                if (value_sum > t) {
                    break;
                }
                cur_added.push_back(cur_value);
                vector<vector<int>> vv = this->calc(c, t - value_sum, b);
                if (!vv.empty()) {
                    // 若有合适的结果返回，就对每个结果都加上当前几次cur_value;
                    for (int j = 0; j < vv.size(); ++j) {
                        vv[j].insert(vv[j].end(), cur_added.begin(), cur_added.end());
                    }
                    // 把加入了cur_times次cur_value后的结果集加入到最终结果集中
                    ret.insert(ret.end(), vv.begin(), vv.end());
                }
            }
        }
        return ret;
    }};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
