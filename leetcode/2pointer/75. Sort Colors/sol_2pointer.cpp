class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int cur = 0;
        int hi = nums.size()-1;
        while(cur<=hi){
            if(nums[cur]==0){
                swap(nums[lo],nums[cur]);
                lo++;
                cur++;
            }
            else if(nums[cur]==1){
                cur++;
            }
            else{
                swap(nums[cur],nums[hi]);
                hi--;
            }
        }
    }
};