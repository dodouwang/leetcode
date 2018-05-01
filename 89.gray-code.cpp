/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (42.52%)
 * Total Accepted:    106.8K
 * Total Submissions: 251.2K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 * 
 */
class Solution {
public:
    // 不用递归了
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
    
//    vector<int> grayCode(int n) {
//        int nums = (1<<n);
//        int r[nums] = {0};
//        map<int, int> m;
//
//        int cur = 0;
//        int next_write = 0;
//        r[next_write++] = cur;
//        m[cur] = 1;
//        while (next_write < nums) {
//            cur = r[next_write-1];
//            bool found_next = false;
//            for (int i = 0; i<n; i++) {
//                int t = cur ^ (1<<i);
//                if (m[t] == 1) {
//                    continue;
//                } else {
//                    r[next_write++] = t;
//                    m[t] = 1;
//                    found_next = true;
//                    break;
//                }
//            }
//            if (found_next) {
//                continue;
//            } else {
//                next_write--;
//                m[cur] = 0;
//            }
//            
//
//            
//        }
//        vector<int> rr(r, r+nums);
//        return rr;
//    }
    
    // vector pop push可能费时,尝试改用vector,但也没啥效果,性能差距不在这里
    vector<int> grayCode2(int n) {
        int nums = (1<<n);
        int r[nums] = {0};
        map<int, int> m;
        r[0] = 0;
        m[0] = 1;
        int p = 0;
        this->helper(r, m, n, p);
        vector<int> rr(r, r+nums);
        return rr;
    }
    bool helper(int *r, map<int,int> &m, int n, int p) {
        int cur = r[p];
        for (int i = 0; i<n; i++) {
            int t = cur ^ (1<<i);
            if (m[t] == 1) continue;
            r[++p] = t;
            m[t] = 1;
            if (p == (1<<n) - 1) return true;
            bool suc = this->helper(r, m, n, p);
            if (suc) return true;
            p--;
            m[t] = 0;
        }
        return false;
    }


    // 要用递归时,需要先想好递归函数helper的进入和退出状态, 7~8ms
    vector<int> grayCode1(int n) {
        vector<int> r;
        map<int, int> m;
        r.push_back(0);
        m[0] = 1;
        this->helper(r, m, n);
        return r;
    }
    // 进入状态: r承载当前已正确链接的code列表,m用来速查哪些已经正确链接
    // 退出条件: 若当前层能再找到一个可用的凑够了code个数, 就返回true到上一层. 若找不到可用的, 返回false
    // 内部要求: 若下一层调用返回了true, 就立马也返回, 若下一层返回了false,就去掉刚加上的这一步,换另外的
    bool helper(vector<int> &r, map<int,int> &m, int n) {
        int cur = r.back();
        for (int i = 0; i<n; i++) {
            int t = cur ^ (1<<i);
            if (m[t] == 1) continue;
            r.push_back(t);
            m[t] = 1;
            if (r.size() == (1<<n)) return true;
            bool suc = this->helper(r, m, n);
            if (suc) return true;
            m[t] = 0;
            r.pop_back();
        }
        return false;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
