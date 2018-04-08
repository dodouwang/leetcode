/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (36.32%)
 * Total Accepted:    342.4K
 * Total Submissions: 942.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array, remove the duplicates in-place such that each element
 * appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * 
 * Example:
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 * 
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }

        int old = nums[0];
        int cur_loc = 1;
        for (int i = 1; i < sz; ++i) {
            if (nums[i] == old) {
                continue;
            }
            nums[cur_loc] = nums[i];
            old = nums[i];
            cur_loc++;
        }

        return cur_loc;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
