class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j,l=0,m=0,n=s.size();
    vector<int> mpp(256,-1);
    for(j=0;j<n;j++){
        if(mpp[s[j]]>=i){
            i=mpp[s[j]]+1;
        }
        mpp[s[j]]=j;
        l=j-i+1;
        m=max(l,m);
    }
    return m;
    }
};