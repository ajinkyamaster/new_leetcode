class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        int currGas = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {

            totalGas += gas[i] - cost[i];

            currGas += gas[i] - cost[i];

            if(currGas < 0) {

                start = i + 1;

                currGas = 0;
            }
        }

        if(totalGas >= 0)
            return start;

        return -1;
    }
};