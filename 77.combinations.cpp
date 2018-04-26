/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (41.43%)
 * Total Accepted:    143.3K
 * Total Submissions: 346K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    // 优化一下，记录下自顶向下的结果备查
    vector<vector<int>> combine(int n, int k) {
        vector<int> used;
        vector<vector<int>> r;
        if (k == 0 || n < k) {
            return r;
        }

        this->combineR(used, r, n, 0, k);
        return r;
    }
    void combineR(vector<int> &used, vector<vector<int>> &result, int n, int used_max, int left_k) {
        if (left_k == 0) {
            result.push_back(used);
            return;
        }

        for (int i = used_max+1; i <= n ; ++i) {
            used.push_back(i);
            this->combineR(used, result, n, i, left_k-1);
            used.pop_back();
        }
    }
    
    map<pair<int,int>, vector<vector<int> > > m;
    vector<vector<int>> combine2(int n, int k) {
        vector<int> r_in;
        vector<vector<int>> r;
        pair<int,int> p;
        if (k == 0) {
            r.push_back(r_in);
            return r;
        }

        if (n < k) {
            return r;
        } else if (n == k) {
            for (int i = 0; i < n; ++i) {
                r_in.push_back(i+1);
            }
            r.push_back(r_in);
            return r;
        } else {
            auto x = this->m.find(make_pair(n-1,k));
            if (x!= this->m.end()) {
                r = x->second;
            } else {
                r = this->combine2(n-1, k);
                this->m[make_pair(n-1,k)] = r;
            }

            vector<vector<int>> tmp;
            x = this->m.find(make_pair(n-1,k-1));
            if (x!= this->m.end()) {
                tmp = x->second;
            } else {
                tmp = this->combine2(n-1, k-1);
                this->m[make_pair(n-1,k-1)] = tmp;
            }

            for (auto &a :tmp) {
                a.push_back(n);
            }
            r.insert(r.end(), tmp.begin(), tmp.end());
            return r;
        }
    }    
    // 递归方式，f(n,k) = f(n-1,k) + f(n-1,k-1)[n]
    vector<vector<int>> combine1(int n, int k) {
        vector<int> r_in;
        vector<vector<int>> r;
        if (k == 0) {
            r.push_back(r_in);
            return r;
        }

        if (n < k) {
            return r;
        } else if (n == k) {
            for (int i = 0; i < n; ++i) {
                r_in.push_back(i+1);
            }
            r.push_back(r_in);
            return r;
        } else {
            r = this->combine(n-1, k);
            vector<vector<int>> tmp = this->combine(n-1,k-1);
            for (auto &a :tmp) {
                a.push_back(n);
            }
            r.insert(r.end(), tmp.begin(), tmp.end());
            return r;
        }
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
