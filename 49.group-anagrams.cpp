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
            unordered_map<string, vector<string>> m;
            for (string s : strs) {
                m[strSort(s)].push_back(s);
            }
            vector<vector<string>> r;
            for (auto p : m) { 
                r.push_back(p.second);
            }
            return r;
        }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
            unordered_map<string, multiset<string>> mp;
            for (string s : strs) {
                string t = strSort(s);
                mp[t].insert(s);
            }
            vector<vector<string>> anagrams;
            for (auto m : mp) { 
                vector<string> anagram(m.second.begin(), m.second.end());
                anagrams.push_back(anagram);
            }
            return anagrams;
        }

    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 

    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
                sort(t.begin(), t.end());
                mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
            for (auto m : mp) { 
                vector<string> anagram(m.second.begin(), m.second.end());
                anagrams.push_back(anagram);
            }
            return anagrams;
    }
    
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
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
