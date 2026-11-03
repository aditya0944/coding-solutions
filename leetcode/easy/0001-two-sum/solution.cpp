class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mpp;
    int i,diff,n=nums.size();
    for(i=0;i<n;i++){
        diff=target-nums[i];
        if(mpp.find(diff)!=mpp.end()){
            return{mpp[diff],i};
            }
        mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};