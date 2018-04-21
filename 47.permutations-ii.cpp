/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (35.16%)
 * Total Accepted:    162.1K
 * Total Submissions: 460.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    bool needContAfterP(vector<int>& nums) {
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
            return true;
        } else {
            return false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        while (this->needContAfterP(nums)) {
            ret.push_back(nums);
        }
        return ret;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
