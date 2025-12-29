class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini=0;
        int diffi=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);

                if(diff < diffi){
                    diffi = diff;
                    mini = sum;
                }

                if(sum==target){
                    return sum;
                }
                else if(sum>target) {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return mini;
    }
};