/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (38.61%)
 * Total Accepted:    196.5K
 * Total Submissions: 508.7K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
        map<vector<int>, vector<string>> m;
        vector<int> v(26, 0);
        for (auto& str : strs) {
            memset(&v[0], 0, sizeof(v[0])*v.size());
            for (int i = 0; i< str.length(); i++) {
                v[str[i] - 'a']++;
            }
            m[v].push_back(str);
        }

        for (auto& a : m) {
            r.push_back(a.second);
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
