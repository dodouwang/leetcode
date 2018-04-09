/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.74%)
 * Total Accepted:    130.1K
 * Total Submissions: 827.1K
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor ==0 || (dividend == -2147483648 && divisor == -1)) {
            return INT_MAX;
        }

        // 用异或来判断是否相同
        int sign = (divisor < 0) ^ (dividend < 0) ? -1 : 1;
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long bb = b;
        int ret = 0;
        while (b <= a) { // 每一次循环的目的是算出b的1还是2还是4倍接近a，然后ret加上这个倍数，然后a减去b的这个倍数。b不变
            int z = 1;
            while ((b<<=1) <= a) {
                z <<= 1;
            }
            ret += z;
            a -= (b>>1);
            b = bb;
        }
        return ret * sign;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
