class Solution {
  private:
    void solve(vector<int> &nums, vector<vector<int>> &answer, vector<int> output, int index){
        if(index >= nums.size()){
            answer.push_back(output);
            
            return;
        }
        
        solve(nums, answer, output, index+1);
        
        int element = nums[index];
        output.push_back(element);
        
        solve(nums, answer, output, index+1);
    }
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        int index = 0;
        
        solve(nums, answer, output, index);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
