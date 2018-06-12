/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (47.26%)
 * Total Accepted:    239.9K
 * Total Submissions: 506.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    // 非递归解法，把上一层的右子树放到左儿子一直往右下去的尽头。
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        while (root) {
            r.push_back(root->val);
            if (root->left) {
                TreeNode *l = root->left;
                while (l->right) {
                    l = l->right;
                }
                l->right = root->right;
                // 不加上下边这句的话，内存回收会有问题
                root->right = NULL;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return r;
    }
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> r;
        if (!root) {
            return r;
        }

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            r.push_back(tmp->val);
            if (tmp->right) {
                s.push(tmp->right);
            }
            if (tmp->left) {
                s.push(tmp->left);
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
