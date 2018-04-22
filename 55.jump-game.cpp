/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.53%)
 * Total Accepted:    164.2K
 * Total Submissions: 556.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    map<int, int> s;
    bool canJump(vector<int>& nums) {
        int i = 0;
        for (int m = 0; i < nums.size() && i <= m; i++) {
            m = max(m, i + nums[i]);
        }
        return i == nums.size();
    }
    // 递归会层数太多溢出，还是用主动前推吧
    bool canJump2(vector<int>& nums) {
        int n = nums.size() - 1;

        if (n == 0) return true;
        
        int checked = -1;
        int to_check = 0;
        while (to_check > checked) {
            int max_check = checked;
            for (int i = checked+1; i <= to_check; i++) {
                int new_check = i + nums[i];
                if (new_check >= n) {
                    return true;
                }
                max_check = max(max_check, new_check);
            }
            checked = to_check;
            to_check = max_check;
        }
        return false;
    }
    bool canJump1(vector<int>& nums) {
        return this->canJumpinner(nums, nums.size() - 1);
    }
    bool canJumpinner(vector<int>& nums, int k) {
        cout << "======" << k << " judge start==" << endl;
        if (k <= 0) {
            s[k] = 1;
            cout << "======" << k << " judged, true" << "==" << endl;
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (i + nums[i] >= k) {
                if (s[i] == 1) {
                    cout << "---when " << k << " find " << i << " old, true" << endl;
                    cout << "======" << k << " judged, true" << "==" << endl;
                    return true;
                } else if (s[i] == 2) {
                    cout << "---when " << k << " find " << i << " old, false" << endl;
                } else {
                    cout << "---when " << k << " find " << i << " unknown" << endl;
                    if (this->canJumpinner(nums, i)) {
                        s[k] = 1;
                        cout << "---when " << k << " find " << i << " true" << endl;
                        cout << "======" << k << " judged, true" << "==" << endl;
                        return true;
                    }
                }
            } else {
                cout << "---when " << k << " find " << i << " not suit" << endl;
            }
        }
        s[k] = 2;
        cout << "======" << k << " judged, false" << "==" << endl;
        return false;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
