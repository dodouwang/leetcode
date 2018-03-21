/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.66%)
 * Total Accepted:    456.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    // 两种窗口思路，一种是遇到阻力才记录最长，最后需要补一次head到tail的max。
    int lengthOfLongestSubstring(string s) {
        vector<int> location(256, -1);
        int max_len = 0;
        int head = 0, tail = 0;
        while (tail < s.size()) {
            if (location[s[tail]] >= head) {
                max_len = max(max_len, tail-head);
                head = location[s[tail]] + 1;
            }
            location[s[tail]] = tail;
            tail++;
        }
        max_len = max(max_len, tail-head);
        return max_len;
    }

    // 另一种是没遇到阻力时记录最长，遇到阻力反而不计了，最后不需补max
    int lengthOfLongestSubstring1(string s) {
        vector<int> location(256, -1);
        int max_len = 0;
        int head = 0, tail = 0;
        while (tail < s.size()) {
            if (location[s[tail]] >= head) {
                head = location[s[tail]] + 1;
            } else {
                max_len = max(max_len, tail-head+1);
            }
            location[s[tail]] = tail;
            tail++;
        }
        return max_len;
    }

};
