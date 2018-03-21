/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.24%)
 * Total Accepted:    200.8K
 * Total Submissions: 737.2K
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string r = "";
        for (int i = 0; i < numRows; ++i) {
            r += this->getRow(s, numRows, i);
        }
        return r;
    }
    string getRow(string s, int n, int i) {
        string rr = "";
        for (int j = i; j < s.length(); j+=(2*n-2)) {
            rr += s[j];
            if (i != 0 && i != n-1) {
                int next = j+2*n-2*i-2;
                if (next < s.length()) {
                    rr += s[next];
                }
            }
        }
        return rr;
    }
};
