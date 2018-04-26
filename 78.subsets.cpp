/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (44.98%)
 * Total Accepted:    233.3K
 * Total Submissions: 518.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> used;

        // 已用过的used，当前的结果r，数组nums，当前可用的最小下标
        this->combineRR(used, r, nums, 0);
        return r;
    }
    void combineRR(vector<int> &used, vector<vector<int>> &result, vector<int>& nums, int can_used) {
        result.push_back(used);
        int n = nums.size();
        if (can_used == n) {
            return;
        }

        for (int i = can_used; i < n ; ++i) {
            used.push_back(nums[i]);
            this->combineRR(used, result, nums, i+1);
            used.pop_back();
        }
    }

};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
