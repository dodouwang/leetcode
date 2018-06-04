/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.74%)
 * Total Accepted:    216.1K
 * Total Submissions: 680.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
class Solution {
public:
    // 改用动态规划
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // can_reach[i] = true 理解为: i-1的那个位置可以通过，最终就看can_reach[n]即可。
        vector<bool> can_reach(n+1, false);
        // 默认初始状态可通过
        can_reach[0] = true;
        for (int i = 1; i <= n; ++i) { // 计算从1到n的位置，看0到i-1是否能通过
            for (int j = 0; j < i; ++j) { //j是从0到i-1，其实也就是看-1到i-2的位置是否已经通过了。
                if (can_reach[j]) {
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                        can_reach[i] = true;
                        break;
                    }
                }
//                if (!can_reach[j]) continue;
//                for (string cur_s : wordDict) {
//                    if (s.substr(j, i-j) == cur_s) {
//                        can_reach[i] = true;
//                        break;
//                    }
//                }
//                // 只要能够到，那么就不需要管后续的j了。
//                if (can_reach[i] == true) break;
            } // 退出时can_reach[i] 已更新为当前i-1的位置是否能通过
        }
        return can_reach[n];
    }
    
    // 这种做法用的是递归，但是效率太低，浪费了很多重复实验的时间，比如aaaaaaaaab 和 a
    bool wordBreak1(string s, vector<string>& wordDict) {
        return helper(s, 0, s.length(), wordDict);
    }
    bool helper(string &s, int i, int len, vector<string>& wordDict) {
        if (i == len) {
            return true;
        }
        for (string cur_s : wordDict) {
            if (s.find(cur_s, i) == i) {
                if (helper(s, i+cur_s.length(), len, wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
