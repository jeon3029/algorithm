class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = 100000;
        for(int i=0;i<n && diff!=0;i++){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                int sum = nums[i] + nums[lo] + nums[hi];
                if(abs(sum-target) < abs(diff)){
                    diff = sum-target;
                }
                if(sum<target){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        return target+diff;
    }
};