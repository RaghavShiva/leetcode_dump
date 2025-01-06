class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(i!=j){
                    c += abs(i-j)*(boxes[j]-'0');
                }
            }
            v[i] = c;
        }
        return v;
    }
};