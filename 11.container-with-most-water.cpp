/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.08%)
 * Total Accepted:    189K
 * Total Submissions: 509.7K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int sz = height.size();
        int b = 0, e = sz - 1;
        int cur_shorter = 0;
        while (b < e) {
            max_area = max(max_area, (e - b) * min(height[b], height[e]));
            if (height[b] < height[e]) {
                cur_shorter = height[b];
                while (b < e && height[b] <= cur_shorter) b++;
            } else {
                cur_shorter = height[e];
                while (b < e && height[e] <= cur_shorter) e--;
            }
        }
        return max_area;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
