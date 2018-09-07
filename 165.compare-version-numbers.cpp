/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (20.98%)
 * Total Accepted:    109.6K
 * Total Submissions: 510.9K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Example 1:
 * 
 * 
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * 
 * Example 2:
 * 
 * 
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 * 
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length();
        int l2 = version2.length();
        int b1 = 0;
        int b2 = 0;
        while (b1 != l1 || b2 != l2) {
            long v1 = 0;
            while (b1 < l1 && version1[b1] != '.') {
                v1 = v1 * 10 + (version1[b1]-'0');
                b1++;
            }
            if (b1 < l1) {
                b1++;
            }

            long v2 = 0;
            while (b2 < l2 && version2[b2] != '.') {
                v2 = v2 * 10 + (version2[b2]-'0');
                b2++;
            }
            if (b2 < l2) {
                b2++;
            }

            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }
        return 0;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

