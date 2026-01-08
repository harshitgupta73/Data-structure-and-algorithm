class Solution {
  public:
    int atMost(vector<int>& arr, int k) {
        // code here
        int odd=0;
        int l=0;
        int ans=0;
        for(int r=0;r<arr.size();r++){
            if(arr[r]%2==1) {
                odd++;
            }
            while(odd>k){
                if(arr[l]%2==1) odd--;
                l++;
            }
            ans+= r-l+1;
        }
        return ans;
    }
    int countSubarrays(vector<int>& arr, int k) {
        return atMost(arr,k) - atMost(arr,k-1);
    }
};