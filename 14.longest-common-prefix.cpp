/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.60%)
 * Total Accepted:    257.7K
 * Total Submissions: 815.5K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    // 数组一般先看看0个1个的特例，然后有时候要区别头元素对待。
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        if (sz == 0) {
            return "";
        } else if (sz == 1) {
            return strs[0];
        }

        string r = "";
        int i = 0;
        while (true) {                                
            for (int j = 0; j < sz; ++j) {
                if (j == 0) {
                    if (i >= strs[j].length()) {
                        return r;
                    }
                } else {
                    if (i >= strs[j].length()) {
                        return r;
                    } else {
                        if (strs[j-1][i] != strs[j][i]) {
                            return r;
                        }
                    }
                }
            }
            r += strs[0][i];
            i++;
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
