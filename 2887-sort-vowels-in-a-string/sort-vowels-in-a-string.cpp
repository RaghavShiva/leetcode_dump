class Solution {
public:
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }
    
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        for (char c : s) if (isVowel(c)) freq[c]++;

        string order = "AEIOUaeiou", res;
        int idx = 0;

        for (char c : s) {
            if (!isVowel(c)) res += c;
            else {
                while (idx < order.size() && !freq[order[idx]]) idx++;
                res += order[idx];
                freq[order[idx]]--;
            }
        }
        return res;
    }
};
