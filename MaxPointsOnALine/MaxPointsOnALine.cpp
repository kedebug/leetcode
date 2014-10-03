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
            vector<pair<int, int>> slopes;
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                int z = gcd(x, y);
                if (z != 0) {
                    x /= z, y /= z;
                }
                if (x == 0 && y == 0) {
                    count++;
                } else {
                    slopes.push_back(make_pair(x, y));
                }
            }
            if (slopes.empty()) {
                result = max(result, count + 1);
                continue;
            }
            sort(slopes.begin(), slopes.end());
            int curr = 2 + count;
            result = max(result, curr);
            for (int j = 1; j < slopes.size(); j++) {
                if (slopes[j] == slopes[j-1]) {
                    curr++;
                } else {
                    curr = 2 + count;
                }
                result = max(result, curr);
            }
        }
        return result;
    }
    
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};
