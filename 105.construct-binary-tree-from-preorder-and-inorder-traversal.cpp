/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (34.47%)
 * Total Accepted:    141K
 * Total Submissions: 409K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTree(vector<int>::iterator ps, vector<int>::iterator pe,
                        vector<int>::iterator is, vector<int>::iterator ie) {
        if (is == ie) {
            return NULL;
        }

        vector<int>::iterator root_loc_in_inorder;
        vector<int>::iterator i;
        for (i = ps; i < pe; ++i) {
            root_loc_in_inorder = find(is, ie, *i);
            if (root_loc_in_inorder != ie) {
                break;
            }
        }

        TreeNode *root = new TreeNode(*i);
        root->left = buildTree(i+1, pe, is, root_loc_in_inorder);
        root->right = buildTree(i+1, pe, root_loc_in_inorder+1, ie);
        return root;
    }
    
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
