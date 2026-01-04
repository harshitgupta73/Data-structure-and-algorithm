class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int el=nums[i];
            int cnt=0;
            int sum=0;
            for(int j=1;j<=el;j++){
                if(el%j==0){
                    cnt++;
                    sum+=j;
                }
                if(cnt>4) break;
            }
            if(cnt==4){
                ans+=sum;
            }
        }
        return ans;
    }
};