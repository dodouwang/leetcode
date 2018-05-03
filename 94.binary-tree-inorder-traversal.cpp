/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.97%)
 * Total Accepted:    281.7K
 * Total Submissions: 563K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
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
    // 之前的思路仅靠栈顶一个元素来推进, 必导致某些元素会两次出现在栈顶,就必须有标记.
    // 换一个思路, 记录当前要判断的pc, 同时栈里放的只是因为往左走了还没有来的及输出的
    // 每次判断一下当前要判断的pc, 如果是空的,那就pop一个,记录之,把pc更新为其右
    // 如果不空,那就push进去,吧pc更新为其左
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent) {
            if(pCurrent) {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            } else {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }

    // 换个思路，记录下左子树是否已访问过，
    // 若有左且否，就往里放左，标记已访问
    // 若有左且是，就输出自己，pop自己，往里放右
    // 若无左，就输出自己，pop自己，往里放右
    // 分析之后，上述就变成了：
    // 若有左且否，就往里放左，标记已访问
    // 否则（不需要考虑左了），就输出自己，pop自己，往里放右
    
    vector<int> inorderTraversal3(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        unordered_map<TreeNode *, bool> map;
        if (root == NULL) return vector;
        
        stack.push(root);
        while(!stack.empty()) { 
            TreeNode *tmp = stack.top();
//            if (tmp->left) {
//                if (!map[tmp]) {
//                    stack.push(tmp->left);
//                    map[tmp] = true;
//                } else {
//                    vector.push_back(tmp->val);
//                    stack.pop();
//                    if (tmp->right) {
//                        stack.push(tmp->right);
//                    }
//                }
//            } else {
//                vector.push_back(tmp->val);
//                stack.pop();
//                if (tmp->right) {
//                    stack.push(tmp->right);
//                }
//            }
            if (tmp->left && !map[tmp]) {
                stack.push(tmp->left);
                map[tmp] = true;
            } else {
                vector.push_back(tmp->val);
                stack.pop();
                if (tmp->right) {
                    stack.push(tmp->right);
                }
            }

        }
        return vector;
    }

    // 换个思路，不更改节点，用map来记录，每个节点都是两进两出，比较繁琐
    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> r;
        unordered_map<TreeNode *, bool> map;
        
        if (root == NULL) return r;
        s.push(root);
        while (!s.empty()) {
            TreeNode *i = s.top();
            s.pop();
            if (map[i]) {
                r.push_back(i->val);
                continue;
            }
            if (i->right) s.push(i->right);
            map[i] = true;
            s.push(i);
            if (i->left) s.push(i->left);
        }
        return r;
    }

    // 简单思维，先放root进去，然后只要不空就pop出来，放右中左进去，放中时做好标记。空就打印当前value
    vector<int> inorderTraversal1(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> r;
        if (root == NULL) return r;
        s.push(root);
        while (!s.empty()) {
            TreeNode *i = s.top();
            s.pop();
            TreeNode *ll = i->left;
            TreeNode *rr = i->right;
            if (!ll && !rr) {
                r.push_back(i->val);
                continue;
            }
            if (rr) s.push(rr);
            i->left = NULL;
            i->right = NULL;
            s.push(i);
            if (ll) s.push(ll);
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
