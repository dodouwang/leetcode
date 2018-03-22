/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.71%)
 * Total Accepted:    311.4K
 * Total Submissions: 871.8K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
public:
    // 可以直接全部反向，然后看是否相等。
    // 也可以采取反向一半的算法，注意32123到最后是32和321，要判断一下这种
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long ori = x;
        long long ret = 0;
        while (x > 0) {
            ret = ret * 10 + x % 10;
            x = (x - x % 10) / 10;
        }
        return ori == ret;
    }
    
    bool isPalindrome1(int x) {
        if (x<0 || (x%10==0 && x!=0)) {
            return false;
        }

        int r = 0;
        while (x>r) {
            r = r*10+x%10;
            x /= 10;
        }

        return x == r || x == r / 10;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
