/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval> merged_interval;
        
        bool has_inserted = false;
        int new_start = newInterval.start;
        int new_end = newInterval.end;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start <= new_end && new_start <= intervals[i].end) {
                new_start = min(new_start, intervals[i].start);
                new_end = max(new_end, intervals[i].end);
            }
            else {
                if (!has_inserted && new_end < intervals[i].start) {
                    has_inserted = true;
                    merged_interval.push_back(Interval(new_start, new_end));
                }
                merged_interval.push_back(intervals[i]);
            }
        }
        if (!has_inserted)
            merged_interval.push_back(Interval(new_start, new_end));
        return merged_interval;
    }
};