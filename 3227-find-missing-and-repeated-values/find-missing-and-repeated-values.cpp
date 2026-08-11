class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> mp;
        int n = grid.size();
        vector<int> ans(2);
        for(auto i : grid){
            for(auto j:i){
                mp[j]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(mp[i]==2) ans[0]=i;
            if(mp[i]==0) ans[1]=i;
        }
        return ans;
    }
};