class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        map<int,int> mp;
        int maxi=0,wSum=0;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        vector<int> ans(arr.size()-k+1);
        ans[0]=mp.size();
        for(int i=k;i<arr.size();i++){
            mp[arr[i-k]]--;
            if(mp[arr[i-k]]==0) mp.erase(arr[i-k]);
            mp[arr[i]]++;
            ans[i-k+1]=mp.size();
        }
        return ans;
    }
};