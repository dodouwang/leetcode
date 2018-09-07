/*
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (39.18%)
 * Total Accepted:    173.9K
 * Total Submissions: 439.2K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakLoc(nums, 0, nums.size());
    }

    int findPeakLoc(vector<int>& nums, int b, int e) {
        if (b >= e) {
            return -1;
        }
        int m = (b+e)/2;
        if (isPeak(nums, m)) {
            return m;
        }

        int left = findPeakLoc(nums, b, m);
        if (left > -1) {
            return left;
        }

        int right = findPeakLoc(nums, m+1, e);
        if (right > -1) {
            return right;
        }

        return -1;
    }
    bool isPeak(vector<int>& nums, int m) {
        bool bigger_than_left = m == 0 ? true : nums[m] > nums[m-1];
        bool bigger_than_right = m == nums.size()-1 ? true : nums[m] > nums[m+1];
        return bigger_than_right && bigger_than_left;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

