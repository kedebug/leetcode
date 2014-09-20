/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool operator<(const Point& x, const Point& y) {
    if (x.x == y.x) {
        return x.y < y.y;
    }
    return x.x < y.x;
}

bool operator==(const Point& x, const Point& y) {
    if (x.x == y.x && x.y == y.y) {
        return true;
    }
    return false;
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int result = 2;
        sort(points.begin(), points.end());
        for (int i = 0; i < n; i++) {
            int dup = 1;
            while (i + 1 < n && points[i+1] == points[i]) {
                i++;
                dup++;
            }
            result = max(result, dup);
            if (i + 1 == n) {
                return result;
            }
            vector<double> slopes;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x) {
                    slopes.push_back(numeric_limits<double>::max());
                } else {
                    slopes.push_back((double)(points[j].y - points[i].y) / (points[j].x - points[i].x));
                }
            }
            sort(slopes.begin(), slopes.end());
            int count = 1;
            result = max(result, dup + 1);
            for (int k = 1; k < slopes.size(); k++) {
                if (slopes[k] == slopes[k-1]) {
                    count++;
                } else {
                    count = 1;
                }
                result = max(result, count + dup);
            }
        }
        return result;
    }
};
