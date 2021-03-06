/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.33%)
 * Total Accepted:    305.5K
 * Total Submissions: 757.3K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    // DP法的核心在于找出公式，监控tail_max，并与total_max区分。无需如fun1先行分段
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        
        int total_max = nums[0];
        int tail_max = nums[0];

        for (int i = 1; i < sz; i++) {
            tail_max = max(nums[i], nums[i] + tail_max);
            total_max = max(tail_max, total_max);
        }

        return total_max;
    }

    int maxSubArray1(vector<int>& nums) {
        int total_max = 0;
        int tail_max = 0;
        int i = 0;
        int max = INT_MIN;
        
        while (i < nums.size() && nums[i] >= 0) {
            total_max += nums[i];
            tail_max += nums[i];
            max = nums[i] > max ? nums[i] : max;
            i++;
        }

        while (i < nums.size()) {
            int fu = 0;
            while (i<nums.size() && nums[i] < 0) {
                fu += nums[i];
                max = nums[i] > max ? nums[i] : max;
                i++;
            }

            int zh = 0;
            while (i<nums.size() && nums[i] >= 0) {
                zh += nums[i];
                max = nums[i] > max ? nums[i] : max;
                i++;
            }

            if (tail_max + fu > 0) {
                tail_max = tail_max + fu + zh;
            } else {
                tail_max = zh;
            }
            total_max = tail_max > total_max ? tail_max : total_max;
        }
        if (max < 0) {
            return max;
        }
        return total_max;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
