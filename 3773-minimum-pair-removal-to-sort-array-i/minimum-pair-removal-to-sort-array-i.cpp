class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0, n = nums.size();
        while(!is_sorted(nums.begin(),nums.begin()+n)) {
            ans += 1;
            int min_sum = INT_MAX, pos = -1;
            for(int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if(sum < min_sum) {
                    min_sum = sum;
                    pos = i;
                }
            }
            nums[pos - 1] = min_sum;
            for(int i = pos; i < n - 1; i++) nums[i] = nums[i + 1];
            n--;
        }
        return ans;
    }
};