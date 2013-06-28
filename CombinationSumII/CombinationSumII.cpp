class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (find(combination_set.begin(), combination_set.end(), nums) == combination_set.end())
                combination_set.push_back(nums);
            return;
        }
        
        if (position >= candidates.size())
            return;
            
        DFS(nums, target, candidates, position + 1);
        
        int value = candidates[position];
        if (value <= target) {
            nums.push_back(value);
            DFS(nums, target - value, candidates, position + 1);
            nums.pop_back();
        }   
    }
private:
    vector<vector<int>> combination_set;
};