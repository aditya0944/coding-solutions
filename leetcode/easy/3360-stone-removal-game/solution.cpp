class Solution {
public:
    bool canAliceWin(int n) {
        int t=0;
        for(int i=10;n>=i;i--){
            n-=i;
            t++;
        }
        return t%2==1;
    }
};