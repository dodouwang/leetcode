/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.05%)
 * Total Accepted:    212.3K
 * Total Submissions: 513K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        return helper(nums, 0, n-1);
    }

    int helper(vector<int>& nums, int b, int e) {
        if (b == e) {
            return nums[b];
        }
        int m = (b+e)/2;
        if (nums[b] <= nums[m] && nums[m] <= nums[e]) {
            return nums[b];
        } else if (nums[b] <= nums[m] && nums[m] > nums[e]) {
            return helper(nums, m+1, e);
        } else {
            return helper(nums, b, m);
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
