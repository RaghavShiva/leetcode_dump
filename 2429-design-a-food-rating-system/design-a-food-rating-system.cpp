class FoodRatings {
public:
    unordered_map<string,int> fmr;
    unordered_map<string,string> fmc;
    unordered_map<string,set<pair<int,string>>> cmf;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            fmr[foods[i]] = ratings[i];
            fmc[foods[i]] = cuisines[i];
            cmf[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = fmc[food];
        auto it = cmf[c].find({-fmr[food],food});
        cmf[c].erase(it);
        fmr[food] = newRating;
        cmf[c].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it = cmf[cuisine].begin();
        string ans = (*it).second;
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */