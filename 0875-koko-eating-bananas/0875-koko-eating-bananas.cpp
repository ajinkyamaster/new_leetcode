class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }

        int low = 1, high = maxi;

        while(low<=high) {
            int mid = low + (high-low)/2;

            long long hrs = 0;

            for (int pile : piles) {
                hrs += (pile + mid - 1) / mid;
            }

            if(hrs<=h){
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        }

        return low;
    }
};