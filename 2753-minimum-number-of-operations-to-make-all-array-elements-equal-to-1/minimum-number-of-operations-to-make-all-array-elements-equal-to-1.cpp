class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int countOnes = 0;
        int overallGcd = 0;

        for (int val : nums) {
            if (val == 1) {
                countOnes++;
            }
            overallGcd = gcd(overallGcd, val);
        }

        if (countOnes > 0) {
            return size - countOnes;
        }
        if (overallGcd > 1) {
            return -1;
        }

        int minSubarray = size;
        for (int left = 0; left < size; left++) {
            int currGcd = 0;
            for (int right = left; right < size; right++) {
                currGcd = gcd(currGcd, nums[right]);
                if (currGcd == 1) {
                    minSubarray = min(minSubarray, right - left + 1);
                    break;
                }
            }
        }

        return minSubarray + size - 2;
    }
};
