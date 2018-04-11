/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (31.90%)
 * Total Accepted:    249.8K
 * Total Submissions: 783.1K
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int b = 0, e = sz - 1;
        while (b <= e) {
            int m = (b + e) / 2;
            if (nums[b] == target) {
                return b;
            } else if (nums[e] == target) {
                return e;
            } else if (nums[m] == target) {
                return m;
            } else if (nums[m] < nums[e] && nums[m] > nums[b]) {
                if (target < nums[m]) {
                    e = m - 1;
                    b++;
                    continue;
                } else {
                    b = m + 1;
                    e--;
                    continue;
                }
            } else if (nums[m] < nums[e]) {
                if (target > nums[m] && target < nums[e]) {
                    b = m + 1;
                    e--;
                    continue;
                } else {
                    e = m - 1;
                    b++;
                    continue;
                }
            } else if (nums[m] > nums[b]) {
                if (target > nums[b] && target < nums[m]) {
                    e = m - 1;
                    b++;
                    continue;
                } else {
                    b = m + 1;
                    e--;
                    continue;
                }
            } else {
                return -1;
            }
        }
        return -1;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
