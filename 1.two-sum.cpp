/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (37.71%)
 * Total Accepted:    845K
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    // 暴力法，时间n方，空间1
    // 186ms
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }

    // 遍历过程中插入map，看前边是否已有合适的
    // 相当于遍历的是后一个元素，去找map里是否有前一个。
    // 时间n，空间n
    // 9ms
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator iter = m.find(target - nums[i]);
            if (iter != m.end()) {
                ret.push_back(iter->second);
                ret.push_back(i);
                return ret;
            } else {
                m[nums[i]] = i;
            }
        }
        return ret;
    }

};
