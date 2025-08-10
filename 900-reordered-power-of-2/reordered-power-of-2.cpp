class Solution {
public:
    bool isPow(int n){
        int t = log2(n);
        return (pow(2,t) == n);
    }
    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end()); 
        do {
            if (digits[0] != '0') {
                int t = stoi(digits);
                if(isPow(t)){
                    return true;
                }
            }
        } 
        while (next_permutation(digits.begin(), digits.end()));
        return false;
    }
};