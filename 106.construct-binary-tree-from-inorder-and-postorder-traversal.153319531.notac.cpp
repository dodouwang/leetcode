/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (33.91%)
 * Total Accepted:    108.5K
 * Total Submissions: 319.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());        
    }
    TreeNode* buildTree(vector<int>::iterator ps, vector<int>::iterator pe,
                        vector<int>::iterator is, vector<int>::iterator ie) {
        if (is == ie) {
            return NULL;
        }

        vector<int>::iterator root_loc_in_inorder;
        vector<int>::iterator i;
        for (i = pe-1; i >= ps; --i) {
            root_loc_in_inorder = find(is, ie, *i);
            if (root_loc_in_inorder != ie) {
                break;
            }
        }

        TreeNode *root = new TreeNode(*i);
        root->left = buildTree(ps, i, is, root_loc_in_inorder);
        root->right = buildTree(ps, i, root_loc_in_inorder+1, ie);
        return root;
    }

};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

