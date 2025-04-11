class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        
        vector<string> mapping = {
            "",     "",     "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        backtrack(0, digits, mapping, current, result);
        return result;
    }

private:
    void backtrack(int index, const string& digits, const vector<string>& mapping, 
                   string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, mapping, current, result);
            current.pop_back(); // backtrack
        }
    }
};
