/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

inline bool operator < (const Interval& x, const Interval& y) {
    if (x.start == y.start) {
        return x.end < y.end;
    }
    return x.start < y.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval& back = result.back();
            if (back.end >= intervals[i].start) {
                back.end = max(back.end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
