#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> pos2;
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }

        vector<int> mapped(n);
        for (int i = 0; i < n; i++) {
            mapped[i] = pos2[nums1[i]];
        }

        BIT bitLeft(n);
        BIT bitRight(n);
        vector<int> rightCount(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            rightCount[i] = bitRight.query(n - 1) - bitRight.query(mapped[i]);
            bitRight.update(mapped[i], 1);
        }

        long long result = 0;

        for (int i = 0; i < n; i++) {
            int left = bitLeft.query(mapped[i] - 1);
            int right = rightCount[i];
            result += left *1ll* right;
            bitLeft.update(mapped[i], 1);
        }

        return result;
    }

private:
    class BIT {
    public:
        BIT(int size) {
            this->size = size;
            tree.resize(size + 2, 0);
        }

        void update(int index, int delta) {
            index += 1;
            while (index <= size + 1) {
                tree[index] += delta;
                index += index & -index;
            }
        }

        int query(int index) {
            int result = 0;
            index += 1;
            while (index > 0) {
                result += tree[index];
                index -= index & -index;
            }
            return result;
        }

    private:
        vector<int> tree;
        int size;
    };
};
