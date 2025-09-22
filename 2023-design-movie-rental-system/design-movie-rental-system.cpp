class MovieRentingSystem {
    map<int, set<pair<int,int>>> avail;
    set<tuple<int,int,int>> rentd;
    map<pair<int,int>, int> cost;

public:
    MovieRentingSystem(int n, vector<vector<int>>& e) {
        for (auto& x : e) {
            int s = x[0], m = x[1], p = x[2];
            cost[{s,m}] = p;
            avail[m].insert({p,s});
        }
    }

    vector<int> search(int m) {
        vector<int> r;
        if (avail.count(m)) {
            int c = 0;
            for (auto& x : avail[m]) {
                if (c++ == 5) break;
                r.push_back(x.second);
            }
        }
        return r;
    }

    void rent(int s, int m) {
        int p = cost[{s,m}];
        avail[m].erase({p,s});
        rentd.insert({p,s,m});
    }

    void drop(int s, int m) {
        int p = cost[{s,m}];
        rentd.erase({p,s,m});
        avail[m].insert({p,s});
    }

    vector<vector<int>> report() {
        vector<vector<int>> r;
        int c = 0;
        for (auto& t : rentd) {
            if (c++ == 5) break;
            r.push_back({get<1>(t), get<2>(t)});
        }
        return r;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */