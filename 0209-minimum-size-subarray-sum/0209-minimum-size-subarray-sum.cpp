class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0;
        int sum = 0;
        int mini = 1e9;

        int n = nums.size();

        while(right < n) {

            sum += nums[right];
            while(sum >= target) {

                mini = min(mini, right-left+1);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        return mini == 1e9 ? 0 : mini;
    }
};