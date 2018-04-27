/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (36.90%)
 * Total Accepted:    148.7K
 * Total Submissions: 402.8K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,1,2,3,3],
 * 
 * Your function should return length = 7, with the first seven elements of
 * nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */
class Solution {
public:
    // 要写入的位置toW, 要读取的位置i，以及始终记录preV, accur_times
    // 进入循环时，保证上述均就位
    // 判断是否==preV，不等就写,位置加加,prevV更新,times= 1;
    // == prev的话,times++,若是2,就写,位置++ 若是3,就让i去找到比prevV大的第一个, 找不到时,就返回i
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int w = 1, r = 1, pre = nums[0], times = 1;
        while (r < n) {
            if (nums[r] != pre) {
                pre = nums[r];
                nums[w++] = nums[r++];
                times = 1;
            } else if (times == 1) {
                nums[w++] = nums[r++];
                times = 2;
            } else {
                bool found = false;
                for (int i = r+1; i < n; i++) {
                    if (nums[i] > nums[r]) {
                        r = i;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return w;
                }
            }
        }
        return w;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
