/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (27.47%)
 * Total Accepted:    148.3K
 * Total Submissions: 531.9K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 * 
 */
class Solution {
public:
    // 注意必须加char，否则是int类型。
    // string + char会直接追加，无需先把char转换为string
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)('A' + (n - 1) % 26);
    }
    
    string convertToTitle1(int n) {
        string ret = "";
        do{
            int cur = (n-1) % 26;
            string tmp(1, ('A' + cur));
            ret = tmp + ret;
            n = (n-1) / 26;
        } while (n>0);
        
        return ret;
    }

};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

