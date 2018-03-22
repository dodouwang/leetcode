/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.79%)
 * Total Accepted:    306.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
                    /*
                      注意如果一定要做，那就do while，如果还用的是while，就需要变成
                      while (b < c - 1 && nums[c] == nums[c-1]) {
                          c--;
                      }
                      c--; // 最后还需要做一次，比较笨拙。
                     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int sz = nums.size();
        vector<int> tmp(3, 0);
        sort(nums.begin(), nums.end());
        for (int a = 0; a < sz - 2; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) {
                continue;
            }
            int b = a + 1, c = sz - 1;
            while (b < c) { // b和c在此循环中相向而行，寻找和为0的情况
                if (nums[a] + nums[b] + nums[c] > 0) { // 超了，需要在内部找到下一个c，以再入外层while验证
                    c--;
                } else if (nums[a] + nums[b] + nums[c] < 0) {
                    b++;
                } else {
                    tmp[0] = nums[a];
                    tmp[1] = nums[b];
                    tmp[2] = nums[c];
                    ret.push_back(tmp);
                    do {
                        c--;
                    } while (b < c && nums[c] == nums[c+1]);
                    do {
                        b++;
                    } while (b < c && nums[b] == nums[b-1]);
                }
            }
            // 需要跳过相同的a，在循环头部条件中
        }
        return ret;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
