class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int diff = nums[k-1]-nums[0];
        for(int i=k;i<nums.size();i++){
            diff = min(diff,abs(nums[i]-nums[i-k+1]));
        }
        return diff;
    }
};