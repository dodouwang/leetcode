/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (15.66%)
 * Total Accepted:    212.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * Example:  
 * 
 * 
 * Input: "the sky is blue",
 * Output: "blue is sky the".
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * Follow up: For C programmers, try to solve it in-place in O(1) space.
 * 
 */
class Solution {
public:
    void reverseWords(string &s) {
        // 先翻转整体，再局部翻转
        reverse(s.begin(), s.end());
        auto i = s.begin();
//        while (i != s.end()) {
//            if (*i != ' ') break;
//            else i = s.erase(i);
//        }
        while (i < s.end()) {
            // 上边循环外的删头部空白放到了这里，虽然看起来代码少了，但是实际上不必要每次都如此判断头部空白，因为尾部有处理了。
            while (i < s.end() && *i == ' ') {
                // 注意string的erase会导致全部的迭代器失效，让后边的前进一位
                // 所以不能像map那样erase(iter++)，那样一次性跳两位了。改用返回值。
                i = s.erase(i);
            }
            auto head = i;
            // 这种两个条件，循环外逐一判断是因为哪个条件退出的，体会一下。
            while (i < s.end() && *i != ' ') {
                i++;
            }
            if (i == s.end()) {
                reverse(head, s.end());
                return;
            }
            reverse(head, i++);
            while (i < s.end() && *i == ' ') {
                i = s.erase(i);
            }
            if (i == s.end()) {
                s.erase(--i);
                return;
            }
        }
    }

    void reverseWords1(string &s) {
        size_t n = s.length();
        helper(s, 0, n);
    }
    void helper(string &s, int b, int e) {
        while (b < e && s[b] == ' ') {
            b++;
        }
        while (b < e && s[e] == ' ') {
            e--;
        }

        int first_blank = -1;
        for (int i = b; i < e; ++i) {
            if (s[i] == ' ') {
                first_blank = i;
                break;
            }
        }
        if (first_blank == -1) {
            s = s.substr(b, e-b);
            return;
        }

        int second_head = -1;
        for (int i = first_blank; i < e; ++i) {
            if (s[i] != ' ') {
                second_head = i;
                break;
            }
        }
        if (second_head == -1) {
            s = s.substr(b, first_blank-b);
            return;
        }

        string tmp = s.substr(b, first_blank-b);
        helper(s, second_head, e);
        s = s + " " + tmp;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
