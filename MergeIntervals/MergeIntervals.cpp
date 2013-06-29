/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(const Interval& lhs, const Interval& rhs) {
    if (lhs.start == rhs.start)
        return lhs.end < rhs.end;
    return lhs.start < rhs.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (intervals.empty()) return vector<Interval>();
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<Interval> merged_interval;
        merged_interval.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            int start = merged_interval[merged_interval.size()-1].start;
            int end = merged_interval[merged_interval.size()-1].end;
            if (intervals[i].start <= end) {
                end = max(end, intervals[i].end);
                merged_interval.pop_back();
                merged_interval.push_back(Interval(start, end));
            }
            else {
                merged_interval.push_back(intervals[i]);
            }
        }
        return merged_interval;
    }
};