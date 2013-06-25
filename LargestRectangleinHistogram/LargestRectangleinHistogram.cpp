class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = height.size();
        int width[n];
        stack<int> minHeight;
        
        for (int i = 0; i < n; i++) {
            while (!minHeight.empty() && height[i] <= height[minHeight.top()])
                minHeight.pop();
            int left = minHeight.empty() ? -1 : minHeight.top();
            width[i] = i - left - 1;
            minHeight.push(i);
        }
        
        while (!minHeight.empty())
            minHeight.pop();
            
        for (int i = n - 1; i >= 0; i--) {
            while (!minHeight.empty() && height[i] <= height[minHeight.top()])
                minHeight.pop();
            int right = minHeight.empty() ? n : minHeight.top();
            width[i] += right - i - 1;
            minHeight.push(i);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) 
            result = max(result, height[i] * (width[i] + 1));
        return result;
    }
};