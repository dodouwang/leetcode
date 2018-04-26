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
    // 最好的思路是：
    // 反正对于每个数，要么在要么不在，最终结果一共有2^n种。
    // 那么可以用0~2^n-1来判断每一个bit是否为1，来决定加不加
    vector<vector<int>> subsets(vector<int>& nums) {
        int nn = nums.size();
        int n = 1<<nn;
        vector<vector<int>> r(n);
        for (int i = 0; i < n; ++i) {
            int t = 1;
            for (int j = 0; j < nn; ++j) {
                if (i & t) {
                    r[i].push_back(nums[j]);
                }
                t<<=1;
            }
        }
        return r;
    }
    
    // 然后的思路是用f(n) = f(n-1)[n] + f(n)
    // 还可以继续用递归，之前有过类似，但是本次换个做法，复制追加
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> r(1);
        for (int i = 0; i < nums.size(); ++i) {
            size_t rn = r.size();
            for (int j = 0; j < rn; ++j) {
                r.push_back(r[j]);
                r[j].push_back(nums[i]);
            }
        }
        return r;
    }

    // 最开始的思路类似p78，递归。
    vector<vector<int>> subsets1(vector<int>& nums) {
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
