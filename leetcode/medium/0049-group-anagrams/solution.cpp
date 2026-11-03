class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
    vector<vector<string>> res;
    for(auto x:strs){
        string t=x;
        sort(t.begin(),t.end());
        mpp[t].push_back(x);
    }
    for(auto x:mpp){
        res.push_back(x.second);
    }
    return res;
    }
};