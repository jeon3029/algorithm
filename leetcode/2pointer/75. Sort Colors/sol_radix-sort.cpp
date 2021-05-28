class Solution {
public:
    void sortColors(vector<int>& nums) {
        int radix[3]={0,0,0};
        for(int i=0;i<nums.size();i++){
            radix[nums[i]]++;
        }
        int x = 0;
        int counter = 0;
        
        for(int x=0;x<=2;x++){
            for(int k=0;k<radix[x];k++){
                nums[counter++] = x;
            }
        }
        
    }
};