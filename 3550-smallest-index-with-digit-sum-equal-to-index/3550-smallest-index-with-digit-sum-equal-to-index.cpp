class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans= -1;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int num  = nums[i];
            long long sum = 0;

            while(num!=0){
                int digit = num%10;
                num = num/10;
                sum+=digit;
                if(sum>i){
                    continue;
                }
            }

            if(sum==i){
                return i;
            }
        }

        return -1;

    }
};