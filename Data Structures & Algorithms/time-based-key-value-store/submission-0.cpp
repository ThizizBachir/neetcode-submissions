class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if(!m.contains(key)) return "";
        auto & v = m[key];
        auto it = upper_bound(v.begin(),v.end(),timestamp,[](int t , const pair<int, string>& p ) {return t<p.first;});
        if (it == v.begin() ) return "";
        int pos = it - m[key].begin();
        return v[pos-1].second;

        
    }
};
