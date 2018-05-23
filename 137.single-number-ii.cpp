/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (42.88%)
 * Total Accepted:    135.9K
 * Total Submissions: 317K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution {
public:
    // 避免进位造成的问题，为啥我没想到呢，后边的做法还是个错误的。
    int singleNumber(vector<int>& s) 
    {
        vector<int> t(32);////Made a array contain 32 elements.
        int sz = s.size();
        int i, j, n;
        for (i = 0; i < sz; ++i)
        {
            n = s[i];
            for (j = 31; j >= 0; --j)
            {
                t[j] += n & 1;//Find the last digit.
                n >>= 1;
                if (!n)
                    break;
            }
        }
    	int res = 0;
    	for (j = 31; j >= 0; --j)
    	{
    		n = t[j] % 3;//"3" represents k times. 
    		if (n)
    			res += 1 << (31 - j);
    	}
    	return res;
    }

    int threeAdd(int a, int b) {
        int r = 0;
        int base = 1;
        while (a!=0 && b!=0) {
            r += (a%3+b%3)%3 * base;
            base *= 3;
            a /= 3;
            b /= 3;
        }
        if (a!=0) {
            r += a * base;
        }
        if (b!=0) {
            r += b * base;
        }
        return r;
    }
    int singleNumber1(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[0] = threeAdd(nums[0], nums[i]);
            cout << nums[0] << endl;
        }
        cout << "------------" << endl;
        return nums[0];
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
