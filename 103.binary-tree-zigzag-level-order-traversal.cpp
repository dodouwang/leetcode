/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (36.96%)
 * Total Accepted:    137.9K
 * Total Submissions: 373.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        deque<TreeNode*> s;
        if (!root) {
            return r;
        }
        s.push_back(root);
        int n = s.size();
        bool to_right = false;
        TreeNode *t;
        while (n) {
            vector<int> tmpv;
            while (n--) {
                if (to_right) {
                    t = s.back();
                    s.pop_back();
                    if (t->right) {
                        s.push_front(t->right);
                    }
                    if (t->left) {
                        s.push_front(t->left);
                    }
                } else {
                    t = s.front();
                    s.pop_front();
                    if (t->left) {
                        s.push_back(t->left);
                    }
                    if (t->right) {
                        s.push_back(t->right);
                    }
                }
                tmpv.push_back(t->val);
            }
            to_right = !to_right;
            r.push_back(tmpv);
            n = s.size();
        }
        return r;
        
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
