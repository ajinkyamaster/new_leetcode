class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini=1e9, maxi=-1;

         if ((long long)m * k > n)
            return -1;

        for(int i=0;i<n;i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini, high = maxi;
        int bou = m;

        while(low<=high){
            int mid = low+ (high-low)/2;
            bou = m;

            int count = 0;

            for (int i = 0; i < n; i++) {

                if (bloomDay[i] <= mid) {
                    count++;

                    if (count == k) {
                        bou--;
                        count = 0;
                    }
                }
                else {
                    count = 0;
                }

                if (bou == 0)
                    break;
            }

            if(bou<=0){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};