class AuthenticationManager 
{
    int t;
    int uniques{};
    unordered_map<string, int> st;
    queue<pair<string, int>> q;
    
public:
    AuthenticationManager(int t) : t{t} 
    {   
    }
    
    void generate(string s, int ct) 
    {
        st[s] = ct+t-1;
        ++uniques;
        q.push({s, ct+t-1});
    }
    
    void drop(int ct)
    {
        for( ; !empty(q) and q.front().second<ct; q.pop())
            if(st[q.front().first]==q.front().second and  st[q.front().first]<ct) --uniques; 
    }
    
    void renew(string s, int ct) 
    {
        if(st[s]>=ct)
        {
            st[s] = ct+t-1;
            q.push({s, ct+t-1});
        }
    }
    
    int countUnexpiredTokens(int ct) 
    {
        drop(ct);
        return uniques;     
    }
};