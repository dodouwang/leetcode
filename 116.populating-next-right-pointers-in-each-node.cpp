/*
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (36.80%)
 * Total Accepted:    174.4K
 * Total Submissions: 473.9K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 * 
 * 
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 * 
 * 
 * Example:
 * 
 * Given the following perfect binary tree,
 * 
 * 
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \  / \
 * 4  5  6  7
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * 
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \  / \
 * 4->5->6->7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // 利用了上一层的next，来进行逐层扫描
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        while(root -> left)
        {
            TreeLinkNode *p = root;
            while(p)
            {
                p -> left -> next = p -> right;
                if(p -> next)
                    p -> right -> next = p -> next -> left;
                p = p -> next;
            }
            root = root -> left;
        }
    }

    void connect1(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            return;
        } else if (root->left && !root->right) {
            connect(root->left);
            return;
        } else if (!root->left && root->right) {
            connect(root->right);
            return;
        } else {
            connect(root->left);
            connect(root->right);
            TreeLinkNode *l = root->left;
            TreeLinkNode *r = root->right;
            while (l) {
                l->next = r;
                l = l->right;
                r = r->left;
            }
            return;
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
