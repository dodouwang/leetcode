/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.92%)
 * Total Accepted:    153.1K
 * Total Submissions: 562.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    // Fist we assume there is no zero in the A[]. The answer must be A[0] A[1] .... A[i] OR A[j] *A[j+1] A[n - 1]. (Try to prove yourself)
    // Then when we have zero in the A[] (assum A[k] == 0). We could see A[0],A[1]...A[k - 1 ] As An Array and A[k + 1] A[k + 2]...A[n-1] is another.
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = INT_MIN;
        int front = 0;
        int back = 0;
        for (int i=0; i<n; i++) {
            front = front ? front*nums[i] : nums[i];
            back = back ? back*nums[n-1-i] : nums[n-1-i];
            ans = max(ans, max(front, back));
        }
        return ans;
    }
    
    int maxProduct1(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];

        int maxp = nums[0];
        int i = 0;
        while (i < sz) {
            if (nums[i] == 0) {
                maxp = max(maxp, 0);
                i++;
                continue;
            }
            int b = i;
            int p = 1;
            while (i < sz && nums[i] != 0) {
                p *= nums[i];
                i++;
            }

            // 本来是需要判断while的退出状况的，但是后来发现无论什么原因退出，都需要更新一下maxp。同时把是否退出交给外层while即可，因此此处只留一句。
            maxp = max(maxp, helper(nums, b, i, p));
        }
        return maxp;
    }

    int helper(vector<int> &nums, int b, int e, int p) {
        if (p > 0 || b == e-1) {
            return p;
        }
        int head = 1;
        int bb = b;
        while (bb < e && nums[bb] > 0) {
            head *= nums[bb];
            bb++;
        }
        head *= nums[bb];

        int tail = 1;
        int ee = e;
        while (b <= ee-1 && nums[ee-1] > 0) {
            tail *= nums[ee-1];
            ee--;
        }
        tail *= nums[ee-1];

        int smaller = max(head, tail);
        return p / smaller;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
