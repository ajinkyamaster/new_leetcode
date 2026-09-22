class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        int maxDiff= -1;

        for(int i=0;i<nums.size()-1;i++){
            maxDiff = max(maxDiff, nums[i+1]-nums[i]);
        }

        return maxDiff;
    }
};