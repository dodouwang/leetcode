/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (32.34%)
 * Total Accepted:    101.9K
 * Total Submissions: 314.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> getVTn(int b, int e, map<pair<int, int>, vector<TreeNode*>> &mp) {
        vector<TreeNode*> r;
        if (b > e) {
            r.push_back(NULL);
            return r;
        }
        return mp[make_pair(b,e)];
    }
    
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> mp;
        if (n < 1) {
            vector<TreeNode*> r;
            return r;
        }

        pair<int, int> p;
        for (int gap = 0; gap < n; ++gap) { // 遍历所有gap，递推
            // 内部处理当前跨度=gap下的事
            for (int b = 1; b <= n - gap; ++b) { // 遍历所有小段
                int e = b + gap;
                // 内部处理当前小段的问题，要记录下当前的结果集
                p = make_pair(b,e);
                vector<TreeNode*> t;
                for (int m = b; m <= e; ++m) { // 遍历当前小段的所有中点
                    // 内部处理当前中点m
                    for (auto aa: this->getVTn(b, m-1, mp)) {
                        for (auto bb: this->getVTn(m+1, e, mp)) {
                            TreeNode *mid = new TreeNode(m);
                            mid->left = aa;
                            mid->right = bb;
                            t.push_back(mid);
                        }
                    }
                }
                if (b == 1 && e == n) {
                    return t;
                }
                mp[p] = t;
            }
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
