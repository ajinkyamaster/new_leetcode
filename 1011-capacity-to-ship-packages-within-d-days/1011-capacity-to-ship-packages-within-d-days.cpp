class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int totalWeight = 0;

        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight += weight;
        }

        int low = maxWeight;
        int high = totalWeight;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int payload = 0;
            int num_days = 1;

            for (int weight : weights) {
                if (payload + weight <= mid) {
                    payload += weight;
                }
                else {
                    num_days++;
                    payload = weight;
                }
            }

            if (num_days <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};