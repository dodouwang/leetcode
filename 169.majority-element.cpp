/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (48.37%)
 * Total Accepted:    295.1K
 * Total Submissions: 596.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
            if (i >= nums.size()/2) {
                if (m[nums[i]] > nums.size()/2) {
                    return nums[i];
                }
            }
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

