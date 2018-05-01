/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (38.45%)
 * Total Accepted:    146.1K
 * Total Submissions: 380K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> r_in;
        vector<vector<int>> r(1, r_in);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int j = i+1;
            while (j < nums.size() && nums[j] == nums[j-1]) j++;
            int n = j-i;
            int sz = r.size();
            vector<int> tmp;
            for (int k = 0; k < n; k++) {
                tmp.push_back(nums[i]);
                for (int m = 0; m < sz; m++) r.push_back(r[m]);
                int nsz = r.size();
                for (int m = 0; m < sz; m++) r[nsz-1-m].insert(r[nsz-1-m].end(), tmp.begin(), tmp.end());
            }
            i = j;
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
