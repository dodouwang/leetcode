/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.23%)
 * Total Accepted:    297.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, left = 0, right = 0;
        for (int i=0; i<s.length(); ++i) {
            for (int l=i-1, r=i+1; l>=0&&r<s.length(); ++r,--l) {
                if (s[l] == s[r]) {
                    if (r-l+1 > max_len) {
                        max_len = r-l+1;
                        left = l;
                        right = r;
                    }
                } else {
                    break;
                }
            }
        }

        for (int i=0; i<s.length()-1; ++i) {
            for (int l=i, r=i+1; l>=0&&r<s.length(); ++r,--l) {
                if (s[l] == s[r]) {
                    if (r-l+1 >max_len) {
                        max_len = r-l+1;
                        left = l;
                        right = r;
                    }
                } else {
                    break;
                }
            }
        }

        return s.substr(left, right-left+1);

    }
};
