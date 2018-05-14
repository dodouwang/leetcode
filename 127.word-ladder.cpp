/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (20.18%)
 * Total Accepted:    165.3K
 * Total Submissions: 819.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
//#include <vector>
//#include <string>
//#include <iostream>
//#include <set>
//#include <queue>
//using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ll = 0;
        unordered_set<string> us;
        for (auto word : wordList) {
            us.insert(word);
        }

        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int qsize = q.size();
            ll++;
            for (int i = 0; i < qsize; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return ll;
                }
                //cout << "FINDNEXT WORD"<<endl;
                findNextWords(word, endWord, us, q);
            }

        }
        return 0;

    }

    void findNextWords(string curWord, string endWord, unordered_set<string>& wordSet, queue<string>& q) {
        wordSet.erase(curWord);
        for (int i = 0; i < curWord.size(); i++) {
            char tmp = curWord[i];
            for (int j = 0; j < 26; j++) {
                curWord[i] = 'a' + j;
                if(wordSet.find(curWord) != wordSet.end()) {
                    //cout << curWord << endl;
                    q.push(curWord);
                    wordSet.erase(curWord);
                }
            }
            curWord[i] = tmp;
        }
    }
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        set<string> pushed;
        queue<string> q;
        pushed.insert(beginWord);
        q.push(beginWord);
        int qn = q.size();
        int len = 1;
        while (qn) {
            len++;
            while (qn--) {
                string tmp = q.front();
                q.pop();
                for (auto word : wordList) {
                    if (!canMatch(tmp, word)) continue;
                    if (word == endWord) return len;
                    if (pushed.find(word) != pushed.end()) continue;
                    pushed.insert(word);
                    q.push(word);
                }
            }
            qn = q.size();
        }
        return 0;
    }
//    // 从当前单词cur去寻找aim，used是已用过的集合
//    // 遍历words，若已use，跳过，若够不到，跳过，若等于aim，直接返回true
//    // 剩下相当于是对于所有unused且够得着的。
//    // used 添加这个，cur更新为这个，aim不变，words不变。若true则返回true，若false则used要删掉回这个
//    // 都false了就返回false
//    bool find(set<string> &used, string cur, string aim, vector<string>& words) {
//        for (auto word : words) {
//            if (word == aim) return true;
//            if (used.find(word) != used.end()) continue;
//            if (!canMatch(cur, word)) continue;
//            used.insert(word);
//            if (find(used, word, aim, words)) return true;
//            used.erase(word);
//        }
//        return false;
//    }
    map<pair<string,string>, bool> connect;
    bool canMatch(string a, string b) {
        int l = a.length();
        int diffs = 0;
        for (int i = 0; i < l; ++i) {
            if (a[i] != b[i]) {
                diffs++;
                if (diffs > 1) {
                    return false;
                }
            }
        }
        return true;
    }
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//        set<string> used;
//        return find(used, beginWord, endWord, wordList);
//    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

//int main() {
//    string b = "hit";
//    string e = "cog";
//    string s[6] = {"hot","dot","dog","lot","log","cog"};
//    vector<string> words(s, s+6);
//    Solution s1;
//    int l = s1.ladderLength(b, e, words);
//    cout << l << endl;
//}
