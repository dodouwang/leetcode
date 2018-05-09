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
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

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
//        if (!right_tail) {
//            cout << "RNULL" << endl;
//        } else {
//            cout << right_tail->val << endl;
//        }
        TreeNode *left_tail = flat_and_get_tail(cur->left);
//        if (!left_tail) {
//            cout << "LNULL" << endl;
//        } else {
//            cout << left_tail->val << endl;
//        }
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
//int main() {
//    TreeNode *a = new TreeNode(1);
//    TreeNode *b = new TreeNode(2);
//    TreeNode *c = new TreeNode(3);
//    a->left = b;
//    a->right = c;
//    Solution s;
//    s.flatten(a);
//    cout << a << endl;
//    cout << b << endl;
//    cout << c << endl;
//    
//    cout << a->val << endl;
//    cout << a->left << endl;
//    cout << a->right->val << endl;
//    cout << a->right->left << endl;
//    cout << a->right->right->val << endl;
//    cout << a->right->right->left << endl;
//    cout << a->right->right->right << endl;
//    return 0;
//}
