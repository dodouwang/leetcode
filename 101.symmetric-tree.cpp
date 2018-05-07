/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (40.55%)
 * Total Accepted:    252.6K
 * Total Submissions: 622.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    // 非递归方式
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            TreeNode *a = s.top();
            s.pop();
            TreeNode *b = s.top();
            s.pop();
            if (a == NULL && b == NULL) {
                continue;
            } else if (a == NULL || b == NULL) {
                return false;
            }

            if (a->val != b->val) {
                return false;
            }

            s.push(a->left);
            s.push(b->right);
            s.push(a->right);
            s.push(b->left);
        }
        return true;
    }

    // 递归方式
    bool helper(TreeNode* a, TreeNode* b) {
        if (a == NULL || b == NULL) return a == b;
        if (a->val != b->val) return false;
        return this->helper(a->left, b->right) && this->helper(a->right, b->left);
    }
    bool isSymmetric1(TreeNode* root) {
        if (!root) return true;
        return this->helper(root->left, root->right);
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
