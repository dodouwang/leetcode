/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.33%)
 * Total Accepted:    112.3K
 * Total Submissions: 426.2K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * 
 * 
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        size_t l = path.length();
        if (l == 0 || path[0] != '/') return path;
        size_t find_begin = 1;
        // 循环外先做一次
        size_t finded = path.find('/', find_begin);
        string cur;
        while (string::npos != finded) {
            cur = path.substr(find_begin, finded - find_begin);
            if (".." == cur) {
                if (v.size() > 0) {
                    v.pop_back();
                }
            } else if ("." == cur || "" == cur) {
            } else {
                v.push_back(cur);
            }
            find_begin = finded + 1;
            finded = path.find('/', find_begin);
        }
        if (find_begin != l) {
            cur = path.substr(find_begin);
            if (".." == cur) {
                if (v.size() > 0) {
                    v.pop_back();
                }
            } else if ("." == cur || "" == cur) {
            } else {
                v.push_back(cur);
            }

        }
        if (v.size() == 0) {
            return "/";
        } else {
            string r;
            for (string s: v) {
                r += "/";
                r += s;
            }
            return r;
        }


    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
