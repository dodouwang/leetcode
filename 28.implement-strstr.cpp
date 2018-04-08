/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (28.92%)
 * Total Accepted:    263.1K
 * Total Submissions: 909.2K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 
 * Implement strStr().
 * 
 * 
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 注意如果不用alen blen，会导致size_t相减溢出得不到负数的问题出现。
        int alen = haystack.length();
        int blen = needle.length();
        for (int i = 0; i < alen - blen + 1; ++i) {
            int j = 0;
            for (j = 0; j < blen; ++j) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == blen) {
                return i;
            }
        }
        return -1;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
