/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (42.09%)
 * Total Accepted:    149.9K
 * Total Submissions: 356.2K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:
    int numTrees(int n) {
        int r[n+1] = {0};
        r[0] = 1;        
        r[1] = 1;
        for (int i = 2; i < n+1; ++i) {
            for (int j = 0; j < i ; ++j) {
                r[i] += r[j] * r[i-1-j];
            }
        }
        return r[n];
    }


    // 下边这种做法是考虑到所有真实数字，但其实没有必要，只需要考虑一共有几个数即可，数的值不重要
    int getVTn(int b, int e, map<pair<int, int>, int> &mp) {
        if (b > e) {
            return 1;
        }
        return mp[make_pair(b,e)];
    }

    int numTrees1(int n) {
        map<pair<int, int>, int> mp;
        if (n < 1) {
            return 0;
        }

        pair<int, int> p;
        for (int gap = 0; gap < n; ++gap) { // 遍历所有gap，递推
            // 内部处理当前跨度=gap下的事
            for (int b = 1; b <= n - gap; ++b) { // 遍历所有小段
                int e = b + gap;
                // 内部处理当前小段的问题，要记录下当前的结果集
                p = make_pair(b,e);
                mp[p] = 0;
                for (int m = b; m <= e; ++m) { // 遍历当前小段的所有中点
                    // 内部处理当前中点m
                    mp[p] += this->getVTn(b, m-1, mp) * this->getVTn(m+1, e, mp);
                }
            }
        }
        return mp[p];
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
