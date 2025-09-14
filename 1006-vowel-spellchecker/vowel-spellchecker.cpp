class Solution {
    unordered_set<string> exact;
    unordered_map<string, string> cap, vow;

    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string lower(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return tolower(c); });
        return s;
    }

    string mask(string s) {
        for (char& c : s) if (isVowel(c)) c='*';
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& words, vector<string>& queries) {
        for (auto& w : words) {
            exact.insert(w);
            string lw = lower(w);
            cap.emplace(lw, w);
            vow.emplace(mask(lw), w);
        }

        vector<string> res;
        res.reserve(queries.size());
        for (auto& q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; }
            string lq = lower(q);
            if (cap.count(lq)) { res.push_back(cap[lq]); continue; }
            string mq = mask(lq);
            if (vow.count(mq)) { res.push_back(vow[mq]); continue; }
            res.push_back("");
        }
        return res;
    }
};
