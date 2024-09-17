class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        vector<vector<string>> ans;
        string w = "";
        for(char ch : searchWord){
            w += ch;
            vector<string> t;
            int ind = lower_bound(products.begin(), products.end(), w) - products.begin();
            for(int i = 0; i < 3 && i + ind < n; i++){
                string s = products[i + ind];
                if(s.find(w)){
                    break;
                }
                t.push_back(s);
            }
            ans.push_back(t);
        }
        return ans;
    }
};