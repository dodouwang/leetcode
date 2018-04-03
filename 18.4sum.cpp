/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.49%)
 * Total Accepted:    152.4K
 * Total Submissions: 554.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> ret;
        int sz = nums.size();
        vector<int> tmp(4, 0);
        sort(nums.begin(), nums.end());
        for (int a = 0; a < sz - 3; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) {
                continue;
            }
            // 此处剪枝格外重要，未剪枝60ms，剪枝15ms
            if (nums[a] + nums[sz - 3] + nums[sz - 2] + nums[sz - 1] < target) {
                continue;
            }
            if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) {
                return ret;
            }

            for (int b = a + 1; b < sz - 2; ++b) {            
                if (b > a + 1 && nums[b] == nums[b-1]) {
                    continue;
                }

                // 此处剪枝可从15ms到12ms，要注意若>target, 不能直接return了，只是内层b循环不必再试，外层a循环还要继续
                if (nums[a] + nums[b] + nums[sz - 2] + nums[sz - 1] < target) {
                    continue;
                }
                if (nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) {
                    break;
                }

                int c = b + 1, d = sz - 1;
                while (c < d) { // c和d在此循环中相向而行，寻找和为t的情况
                    if (nums[a] + nums[b] + nums[c] + nums[d] > target) { // 超了，需要在内部找到下一个c，以再入外层while验证
                        d--;
                    } else if (nums[a] + nums[b] + nums[c] + nums[d] < target) {
                        c++;
                    } else {
                        tmp[0] = nums[a];
                        tmp[1] = nums[b];
                        tmp[2] = nums[c];
                        tmp[3] = nums[d];
                        ret.push_back(tmp);
                        do {
                            d--;
                        } while (c < d && nums[d] == nums[d+1]);
                        do {
                            c++;
                        } while (c < d && nums[c] == nums[c-1]);
                    }
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
