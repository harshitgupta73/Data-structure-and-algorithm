class Solution {
public:
    const int mod = 1e9+7;
    int solve(int i,int n,int p1,int p2, int p3,vector<vector<vector<vector<int>>>> &dp){
        if(i==n) return 1;
        if(dp[i][p1+1][p2+1][p3+1] != -1) return  dp[i][p1+1][p2+1][p3+1];
        int ans=0;
        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                for(int c3=0;c3<3;c3++){
                    if(c1!=p1&&c2!=p2&&c3!=p3&&c1!=c2&&c2!=c3){
                        ans=(ans+solve(i+1,n,c1,c2,c3,dp))%mod;
                    }
                }
            }
        }
        return dp[i][p1+1][p2+1][p3+1] = ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n + 1,vector<vector<vector<int>>>( 4, vector<vector<int>>(4, vector<int>(4, -1))));
        return solve(0,n,-1,-1,-1,dp);
    }
};