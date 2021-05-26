class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size(),-1));
        return dfs(nums,-1,0,memo);
    }
    int dfs(vector<int> &nums,int beforePos,int curPos,vector<vector<int>> &memo){
        if(curPos == nums.size()){
            return 0;
        }
        if(memo[beforePos+1][curPos]>=0){
            return memo[beforePos+1][curPos];
        }
        int checked = 0;
        if(beforePos<0 || nums[curPos]>nums[beforePos]){
            checked = 1 + dfs(nums,curPos,curPos+1,memo);
        }
        int notChecked = dfs(nums,beforePos,curPos+1,memo);
        memo[beforePos+1][curPos] = max(checked,notChecked);
        return memo[beforePos+1][curPos];
    }
};