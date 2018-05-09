/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (36.79%)
 * Total Accepted:    166.4K
 * Total Submissions: 452.2K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten1(TreeNode *root) {
		while (root) {
			if (root->left && root->right) {
				TreeNode* t = root->left;
				while (t->right)
					t = t->right;
				t->right = root->right;
			}

            if(root->left)
			    root->right = root->left;
			root->left = NULL;
			root = root->right;
		}
	}

    TreeNode* flatten(TreeNode* root) {
        flat_and_get_tail(root);
        return root;
    }
    TreeNode* flat_and_get_tail(TreeNode *cur) {
        if (!cur) {
            return NULL;
        }
        if (!cur->left && !cur->right) {
            return cur;
        }
        TreeNode *right_tail = flat_and_get_tail(cur->right);
        TreeNode *left_tail = flat_and_get_tail(cur->left);
        if (left_tail) {
            left_tail->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        if (right_tail) {
            return right_tail;
        } else {
            return left_tail;
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
