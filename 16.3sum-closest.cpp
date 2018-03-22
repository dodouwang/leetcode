/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.62%)
 * Total Accepted:    168.6K
 * Total Submissions: 533K
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = 0;
        bool is_first = true;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < sz - 2; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) {
                continue;
            }
            int b = a + 1, c = sz - 1;
            while (b < c) { // b和c在此循环中相向而行，寻找当前a的最好情况
                int gap = nums[a] + nums[b] + nums[c] - target;
                if (is_first) {
                    best = gap;
                    is_first = false;
                } else {
                    if (abs(gap) < abs(best)) {
                        best = gap;
                    }
                }
                // 决定下一步怎么移动bc
                if (gap == 0) {
                    return target;
                } else if (gap > 0) {
                    c--;
                } else if (gap < 0) {
                    b++;
                }
            }
        }
        return target+best;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
