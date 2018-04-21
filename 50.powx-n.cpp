/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.06%)
 * Total Accepted:    209.5K
 * Total Submissions: 803.9K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        double r = 1;
        double zheng1 = 1;
        double fu1 = -1;
        double z = 0;
        if (n == 0) {
            return 1;
        }

        if (x == z) {
            return 0;
        } else if (x == zheng1) {
            return r;
        } else if (x == fu1) {
            if (n % 2) {
                return fu1;
            } else {
                return zheng1;
            }
        }

        unsigned long long p = n;
        if (n < 0) {
            p = -n;
            x = 1 / x;
        }

        while (p > 0 && r != z) {
            if (p & 1)
                r *= x;
            x *= x;
            p >>= 1;
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
