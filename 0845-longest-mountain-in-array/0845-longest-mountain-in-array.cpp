
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int left = 0;

        while (left < n - 1) {
            int right = left;

            // Find the uphill portion
            while (right < n - 1 && arr[right] < arr[right + 1]) {
                right++;
            }

            // No uphill: not a mountain
            if (right == left) {
                left++;
                continue;
            }

            int peak = right;

            // Find the downhill portion
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // A valid mountain must have downhill too
            if (right > peak) {
                maxi = max(maxi, right - left + 1);
            }

            left = max(right, left + 1);
        }

        return maxi;
    }
};
