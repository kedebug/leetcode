class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int delta = INT_MAX;
        int closest = 0;
        for (int i = 0; i < num.size(); i++) {
            int start = i + 1;
            int limit = num.size() - 1;
            while (start < limit) {
                int sum = num[i] + num[start] + num[limit];
                if (abs(sum - target) < delta) {
                    delta = abs(sum - target);
                    closest = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    start++;
                } else {
                    limit--;
                }
            }
        }
        return closest;
    }
};
