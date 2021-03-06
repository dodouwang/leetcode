/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.66%)
 * Total Accepted:    119.5K
 * Total Submissions: 365.8K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    // 优化思路, 切一刀至少有一段有序,那就以此判断即可, 无需关注be大小
    // 除非三点相等, 此时左右夹逼即可.
    
    // 若三点有碰上的,直接返回/
    // 若b<e, 那么全序列有序,直接根据中值二分
    // 若b>e, 那么是一个中间只有一次降的序列
    //    若m在后半段上,那么me有序, 可以此为两端来判断左右
    //    若m在前半段上,那么bm有序, 可以此为两端来判断左右
    // 若b=e, 那么根据t的高低来决定从哪头开始找.
    bool search(vector<int>& nums, int target) {
        int sz = nums.size();
        int b = 0, e = sz - 1;
        while (b <= e) {
            int m = (b + e) / 2;
            if (nums[b] == target) {
                return true;
            } else if (nums[e] == target) {
                return true;
            } else if (nums[m] == target) {
                return true;
            } else if (nums[b] < nums[e]) {
                if (target < nums[m]) {
                    e = m - 1;
                    b++;
                    continue;
                } else {
                    b = m + 1;
                    e--;
                    continue;
                }
            } else if (nums[b] > nums[e]) {
                if (nums[m] <= nums[e]) {
                    if (target > nums[m] && target < nums[e]) {
                        b = m + 1;
                        e--;
                        continue;
                    } else {
                        e = m - 1;
                        b++;
                        continue;
                    }
                } else {
                    if (target > nums[b] && target < nums[m]) {
                        e = m - 1;
                        b++;
                        continue;
                    } else {
                        b = m + 1;
                        e--;
                        continue;
                    }
                }
            } else { // b = e
                if (target - nums[b] > 0) {
                    for (int i = b+1; i < e; i++) {
                        if (nums[i] < nums[i-1]) {
                            return false;
                        }
                        if (nums[i] == target) {
                            return true;
                        } else if (nums[i] > target) {
                            return false;
                        }
                    }
                    return false;
                } else { // target < b
                    for (int i = e-1; i > b; i--) {
                        if (nums[i] > nums[i+1]) {
                            return false;
                        }
                        if (nums[i] == target) {
                            return true;
                        } else if (nums[i] < target) {
                            return false;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
