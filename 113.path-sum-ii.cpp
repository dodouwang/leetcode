/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (35.93%)
 * Total Accepted:    164.9K
 * Total Submissions: 459K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        vector<int> path;
        if (!root) {
            return r;
        }
        helper(path, root, r, sum);
        return r;
    }
    void helper(vector<int> &path, TreeNode *t, vector<vector<int>> &r, int sum) {
        if (!t->left && !t->right && t->val == sum) {
            path.push_back(t->val);
            r.push_back(path);
            path.pop_back();
            return;
        }
        if (t->left) {
            path.push_back(t->val);
            helper(path, t->left, r, sum - t->val);
            path.pop_back();
        }
        if (t->right) {
            path.push_back(t->val);
            helper(path, t->right, r, sum - t->val);
            path.pop_back();
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
