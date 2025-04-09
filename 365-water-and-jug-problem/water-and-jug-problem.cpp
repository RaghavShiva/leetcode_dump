class Solution {
public:
    // Function to calculate the Greatest Common Divisor (GCD)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    bool canMeasureWater(int x, int y, int target) {
        // If the total capacity is less than the target, it's not possible
        if (x + y < target) return false;

        // If target is 0, we can always measure it (just don't fill)
        if (target == 0) return true;

        // Use Bézout’s theorem: z is measurable iff gcd(x, y) divides z
        return target % gcd(x, y) == 0;
    }
};
