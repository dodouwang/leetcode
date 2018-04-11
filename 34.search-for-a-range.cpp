/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.60%)
 * Total Accepted:    186.2K
 * Total Submissions: 589.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r;
        int sz = nums.size();
        int b = 0, e = sz - 1;
        // while需要保证内部不能死循环，
        // 要么内部首先需要有判断退出的逻辑。
        // 否则每一次调整边界必须要缩小，不能不变
        while (b <= e) {
            int m = (b + e) / 2;
            if (target < nums[m]) {
                e = m - 1; // 缩小边界
                continue;
            } else if (target > nums[m]) {
                b = m + 1; // 缩小边界
                continue;
            } else {
                int lb = b, le = m;
                while (lb < le) {
                    int lm = (lb + le) / 2;
                    if (nums[lm] < target) {
                        lb =  lm + 1;
                        continue;
                    } else {
                        le = lm;
                        continue;
                    }
                }
                int rb = m, re = e;
                while (rb < re) {
                    int rm = (rb + re + 1) / 2; // 注意中点的选择，为了保证缩小边界
                    if (nums[rm] > target) {
                        re = rm - 1;
                        continue;
                    } else {
                        rb =  rm;
                        continue;
                    }
                }
                r.push_back(lb);
                r.push_back(rb);
                return r;
            }
        }
        // 若内部没能找到，最后边界已不合法，就是没找到了。
        r.push_back(-1);
        r.push_back(-1);
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
