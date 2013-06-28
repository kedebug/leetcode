class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        combination_set.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        DFS(nums, target, candidates, 0);
        return move(combination_set);
    }
    
    void DFS(vector<int>& nums, int target, vector<int>& candidates, int position) {
        if (target < 0) return;
        
        if (target == 0) {
            combination_set.push_back(nums);
            return;
        }
        
        if (position >= candidates.size())
            return;
            
        DFS(nums, target, candidates, position + 1);
        
        int value = candidates[position];
        
        for (int i = 1; i * value <= target; i++) {
            for (int j = 0; j < i; j++)
                nums.push_back(value);
                
            DFS(nums, target - i * value, candidates, position + 1);
            
            for (int j = 0; j < i; j++)
                nums.pop_back();
        }
    }

private:
    vector<vector<int>> combination_set;
};