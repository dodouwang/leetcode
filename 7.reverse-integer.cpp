/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.37%)
 * Total Accepted:    382.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output:  321
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range. For the purpose of this problem,
 * assume that your function returns 0 when the reversed integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        long long t = 0;
        while (x != 0) {
            t = t * 10 + x % 10;
            x = (x - x % 10) / 10;
        }
        if (t > INT_MAX || t < INT_MIN) {
            return 0;
        }
        return t;
    }
};
