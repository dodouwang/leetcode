/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (28.53%)
 * Total Accepted:    103.6K
 * Total Submissions: 362.8K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        this->helper("", s, 0, 4, r);
        return r;
    }
    // 返回就是当前要的结果
    // 内部需要根据开头三位来分别调用子段，若发现走到头且合法，就加入到结果中
    void helper(string pre, string s, int p, int segs, vector<string> &r) {
        if (p == s.length() && segs == 0) {
            r.push_back(pre.substr(1));
            return;
        } else if (p == s.length() || segs == 0) {
            return;
        }

        this->helper(pre + '.' + s[p], s, p+1, segs-1, r);

        if (p+1 < s.length() && s[p] != '0') {
            this->helper(pre + '.' + s[p] + s[p+1], s, p+2, segs-1, r);
        }

        if (p+2 < s.length() && (s[p] == '1'
                                 || (s[p] == '2' && s[p+1] >= '0' && s[p+1] <= '4')
                                 || (s[p] == '2' && s[p+1] == '5' && s[p+2] >= '0' && s[p+2] <= '5'))) {
            this->helper(pre + '.' + s[p] + s[p+1] + s[p+2], s, p+3, segs-1, r);
        }
        return;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
