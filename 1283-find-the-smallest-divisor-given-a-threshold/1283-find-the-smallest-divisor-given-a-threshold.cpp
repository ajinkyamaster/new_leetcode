class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = -1;
        for(int num: nums){
            maxi = max(maxi, num);
        }

        int low = 1, high = maxi, sum;

        while(low<=high){
            int mid = low+(high-low)/2;
            sum=0;

            for(auto ele: nums){
                sum+= (ele+mid -1)/mid;
            }

            if(sum<=threshold){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};