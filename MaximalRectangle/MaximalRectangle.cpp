class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        
        int result = 0;
        int height[col];
        memset(height, 0, sizeof(int)*col);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else 
                    height[j] = 0;
            }
            int rect = getLargestRectInHistogram(height, col);
            result = max(result, rect);
        }
        return result;
    }
    
    int getLargestRectInHistogram(const int height[], int n) {
        int width[n];
        stack<int> minHeight;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            while (!minHeight.empty() && height[i] <= height[minHeight.top()])
                minHeight.pop();
            int left = minHeight.empty() ? -1 : minHeight.top();
            width[i] = i - left - 1;
            minHeight.push(i);
        }
        
        while (!minHeight.empty())
            minHeight.pop();
            
        for (int i = n-1; i >= 0; i--) {
            while (!minHeight.empty() && height[i] <= height[minHeight.top()])
                minHeight.pop();
            int right = minHeight.empty() ? n : minHeight.top();
            width[i] += right - i - 1;
            minHeight.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            result = max(result, height[i] * (width[i] + 1));
        }
        return result;
    }
};

