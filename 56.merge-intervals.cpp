/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (32.05%)
 * Total Accepted:    196.2K
 * Total Submissions: 612.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//struct Interval {
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
//};

bool comp(Interval a, Interval b) {
    return a.start < b.start ? true : false;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> r;
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        if (n == 0) {
            return r;
        }

        r.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            Interval &j = r.back();
            if (intervals[i].start > j.end) {
                r.push_back(intervals[i]);
            } else if (intervals[i].end > j.end) {
                    j.end = intervals[i].end;
            }
        }
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
