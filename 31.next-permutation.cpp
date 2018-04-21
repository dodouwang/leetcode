/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.04%)
 * Total Accepted:    147.8K
 * Total Submissions: 508.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();

        int j = sz - 1;
        while (j > 0 && nums[j] <= nums[j-1]) {
            j--;
        }
        int b = j;
        int e = sz - 1;
        int t;
        //右侧重排序
        while (b < e) {
            swap(nums[b++], nums[e--]);
        }

        if (j > 0) {
            //找到排序后第一个比nums[j-1]大的元素，并交换之。
            for (int k = j; k < sz; ++k) {
                if (nums[k] > nums[j-1]) {
                    swap(nums[j-1], nums[k]);
                    break;
                }
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
