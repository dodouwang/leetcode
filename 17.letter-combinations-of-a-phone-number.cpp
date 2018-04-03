/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.32%)
 * Total Accepted:    227K
 * Total Submissions: 623.5K
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r;
        map<char, string> m = {{'2', "abc"},
                               {'3', "def"},
                               {'4', "ghi"},
                               {'5', "jkl"},
                               {'6', "mno"},
                               {'7', "pqrs"},
                               {'8', "tuv"},
                               {'9', "wxyz"}
        };
        for (int i = 0; i < digits.length(); ++i) {
            if (i == 0) {
                for (int j = 0; j < m[digits[i]].length(); ++j) {
                    string tmp = "";
                    r.push_back(tmp+m[digits[i]][j]);
                }
            } else {
                int cur_r_size = r.size();
                for (int j = 1; j < m[digits[i]].length(); ++j) {
                    for (int k = 0; k < cur_r_size; ++k) {
                        r.push_back(r[k]);
                    }
                }
                for (int j = 0; j < m[digits[i]].length(); ++j) {
                    for (int k = 0; k < cur_r_size; ++k) {
                        r[j*cur_r_size+k] += m[digits[i]][j];
                    }
                }
            }
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
