/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (47.29%)
 * Total Accepted:    232K
 * Total Submissions: 489.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> sub_p(vector<int> &nums, int i) {
        vector<vector<int>> r;
        vector<int> inner_r;
        if (i == nums.size()) {
            r.push_back(inner_r);
            return r;
        }

        vector<vector<int>> sub_r = this->sub_p(nums, i+1);
        for (auto a = sub_r.begin(); a < sub_r.end(); ++a) {
            vector<int> tmp = *a;
            tmp.push_back(nums[i]);
            r.push_back(tmp);
            int cur = tmp.size() - 1;
            while (cur > 0) {
                int tt = tmp[cur];
                tmp[cur] = tmp[cur-1];
                tmp[cur-1] = tt;
                r.push_back(tmp);
                cur--;
            }
        }
        return r;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return this->sub_p(nums, 0);
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
