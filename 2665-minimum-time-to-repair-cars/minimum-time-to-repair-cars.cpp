class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1LL * cars * cars * ranks[0];

        while (l < r) {
            long long mid = l + (r-l) / 2, carsRepaired = 0;

            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);
            if (carsRepaired < cars)
                l = mid + 1;
            else
                r = mid;  
        }

        return l;
    }
};