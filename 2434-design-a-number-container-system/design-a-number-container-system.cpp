#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

class NumberContainers {
public:
    unordered_map<int, int> v;
    map<int, set<int>> m;

    NumberContainers() {}

    void change(int index, int number) {
        if (v.count(index)) {
            int oldNumber = v[index];
            m[oldNumber].erase(index);
            if (m[oldNumber].empty()) m.erase(oldNumber);
        }
        v[index] = number;
        m[number].insert(index);
    }

    int find(int number) {
        if (m.count(number) && !m[number].empty()) return *m[number].begin();
        return -1;
    }
};
