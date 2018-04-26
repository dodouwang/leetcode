/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.16%)
 * Total Accepted:    176.1K
 * Total Submissions: 625.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Node {
public:
    pair<int, int> p;
    set<pair<int, int>> pair_set;
};
class Solution {
public:
    // 前一种超时方案的问题在于：BFS割裂了单次搜寻的过程。
    // 每走一步记录当前的所有可行状态，每个状态里都要记录当前尾部和所有用过的位置。
    // 状态无法复用，复制占用空间和时间都多。
    // 现改用DFS，每次都尝试走到底
    bool exist(vector<vector<char>>& board, string word) {
        size_t n = board.size();
        if (n == 0) {
            return false;
        }
        size_t m = board[0].size();
        if (m == 0) {
            return false;
        }
        size_t l = word.length();
        if (l == 0 || l > n*m) {
            return false;
        }
        
        set<pair<int, int>> visited;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (this->can_go(i, j, word, 0, visited, board)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool can_go(int i, int j, string & word, int k, set<pair<int, int>> &visited, vector<vector<char>>& board) {
        // 调用时需保证ijk合法，若失败，要自行保持visited状态不变
        if (board[i][j] != word[k]) {
            return false;
        }
        pair<int, int> p = make_pair(i,j);
        if (visited.find(p) != visited.end()) {
            return false;
        }
        
        if (++k == word.length()) {
            return true;
        }
        visited.insert(p);
        int change[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int z = 0; z < 4; ++z) {
            int newi = i + change[z][0], newj = j + change[z][1];
            if (newi < 0 || newj < 0 || newi >= board.size() || newj >= board[0].size()) {
                continue;
            }
            if (this->can_go(newi, newj, word, k, visited, board)) {
                return true;
            }
        }
        visited.erase(p);
        return false;
    }
    
    // 采用递推而非递归
    // f(n) 要带有目前的所有可行性vector，每个元素一是要有当前位置，二是要有已用过的位置set
    // f(n+1) 要遍历fn的vector，看每个元素的周边四元素若一来没用过，二来是n+1的字符，则可以加入新字符后扩充vector，最后删掉旧元素。
    // 要先做一遍找出头来
    // 最后超时
    bool exist1(vector<vector<char>>& board, string word) {
        size_t n = board.size();
        if (n == 0) {
            return false;
        }
        size_t m = board[0].size();
        if (m == 0) {
            return false;
        }
        size_t l = word.length();
        if (l == 0 || l > n*m) {
            return false;
        }

        

        vector<Node> v;
        char c = word[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == c) {
                    Node n;
                    n.p = make_pair(i,j);
                    n.pair_set.insert(n.p);
                    v.push_back(n);
                }
            }
        }

        for (int i = 1; i < l; ++i) {
            int vl = v.size();
            if (vl == 0) {
                return false;
            }
            for (int j = vl-1; j >= 0; --j) {
                Node now = v[j];
                v.erase(v.begin() + j);
                this->handle_v_with_node(v, now, word[i], board);
            }
        }

        return v.size() != 0;
    }
    void handle_v_with_node(vector<Node> &v, Node &now, char c, vector<vector<char>>& board) {
        int change[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < 4; ++i) {
            pair<int, int> np = make_pair(now.p.first+change[i][0],now.p.second+change[i][1]);
            if (np.first < 0 || np.second < 0 || np.first >= board.size() || np.second >= board[0].size()) {
                continue;
            }
            if (board[np.first][np.second] != c) {
                continue;
            }
            if (now.pair_set.find(np) != now.pair_set.end()) {
                continue;
            }
            Node newp;
            newp.p = np;
            newp.pair_set = now.pair_set;
            newp.pair_set.insert(np);
            v.push_back(newp);
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
