/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (38.97%)
 * Total Accepted:    220K
 * Total Submissions: 564.5K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t n = nums.size();
        int b = 0, e = n-1, i = 0;
        // <b为0, >e为2.
        // i一直走到e，超过b的原因是值为1
        // i前边不可能有2, 0也是全部排好序的，那么剩下超过b的都是1了。
        while (i <= e) {
            if (nums[i] == 0) {
                swap(nums[i], nums[b]);
                b++;
                i++;// 不需回头，0001110 => 0000111 可继续前行
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[e--]);
            }
        }
        return;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
