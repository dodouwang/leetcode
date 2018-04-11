/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.03%)
 * Total Accepted:    249.1K
 * Total Submissions: 622.2K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        int b = 0, e = sz - 1;
        while (b <= e) {
            if (target <= nums[b]) {
                return b;
            } else if (target > nums[e]) {
                return e + 1;
            } else if (target == nums[e]) {
                return e;
            }

            int m = (b + e) / 2;
            if (target == nums[m]) {
                return m;
            } else if (target < nums[m]) {
                e = m - 1;
                continue;
            } else if (target > nums[m]) {
                b = m + 1;
                continue;
            }
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
