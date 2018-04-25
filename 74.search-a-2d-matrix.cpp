/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.64%)
 * Total Accepted:    157.4K
 * Total Submissions: 454.4K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    // 1维数组
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t n = matrix.size();
        if (n == 0) {
            return false;
        }
        size_t m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        int b = 0, e = m*n, mid;
        while (b<e) {
            mid = (b+e)/2;
            if (target == matrix[mid/m][mid%m]) {
                return true;
            } else if (target < matrix[mid/m][mid%m]) {
                e = mid;
            } else {
                b = mid+1;
            }
        }
        return false;
    }


    // 基本做法，也可以当成一个一纬数组
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        size_t n = matrix.size();
        if (n == 0) {
            return false;
        }
        size_t m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        int b = 0, e = n, mid;
        while (b<e) {
            mid = (b+e) / 2;
            if (target == matrix[mid][0]) {
                return true;
            } else if (target < matrix[mid][0]) {
                e = mid;
                continue;
            } else if (target > matrix[mid][0]) {
                if (target > matrix[mid][m-1]) {
                    b = mid + 1;
                    continue;
                } else {
                    int bb = 1, ee = m, mmid;
                    while (bb < ee) {
                        mmid = (bb+ee)/2;
                        if (target == matrix[mid][mmid]) {
                            return true;
                        } else if (target < matrix[mid][mmid]) {
                            ee = mmid;
                            continue;
                        } else {
                            bb = mmid + 1;
                            continue;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
