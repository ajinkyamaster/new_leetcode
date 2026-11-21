class Solution {
public:
    long long ans = LLONG_MIN;

    void f(vector<int>& nums, int i, long long product, bool taken) {
        if(i < 0) {
            if(taken) {
                ans = max(ans, product);
            }
            return;
        }

        f(nums, i-1, product * nums[i], true);

        f(nums, i-1, product, taken);
    }

    long long maxStrength(vector<int>& nums) {
        int n = nums.size();

        f(nums, n-1, 1, false);

        return ans;
    }
};