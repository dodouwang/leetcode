/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.10%)
 * Total Accepted:    241.1K
 * Total Submissions: 1M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
    // 搜索二叉树的中序遍历是递增序列
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;
        bool is_first = true;
        int pre = 0;

        while(!stack.empty() || pCurrent) {
            if(pCurrent) {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            } else {
                TreeNode *pNode = stack.top();
                if (is_first) {
                    pre = pNode->val;
                    is_first = false;
                } else {
                    if (pNode->val > pre) {
                        pre = pNode->val;
                    } else {
                        return false;
                    }
                }
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return true;
    }
    bool isValidBST1(TreeNode* root) {
        TreeNode *pre = NULL;
        return helper(root, pre);
    }

    bool helper(TreeNode *cur, TreeNode *&pre) {
        if (cur == NULL) return true;
        if (!helper(cur->left, pre)) return false;
        if (pre != NULL && cur->val <= pre->val) return false;
        pre = cur;
        return helper(cur->right, pre);
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
