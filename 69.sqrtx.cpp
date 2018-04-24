/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (28.92%)
 * Total Accepted:    227.8K
 * Total Submissions: 787.7K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        long long h = x;
        long long l = 0;
        long long c = (h+l)/2;
        if (x == 1) {
            return 1;
        }
        while (h-l>1) {
            if (c*c > x) {
                h = c;
                c = (h+l)/2;
            } else if (c*c < x) {
                l = c;
                c = (h+l)/2;
            } else {
                return c;
            }
        }
        return l;
    }

};
