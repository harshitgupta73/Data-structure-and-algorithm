class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int maxi=0,wSum=0;
        for(int i=0;i<k;i++){
            wSum^=arr[i];
        }
        maxi=wSum;
        for(int i=k;i<arr.size();i++){
            wSum^=arr[i-k];
            wSum^=arr[i];
            maxi=max(maxi,wSum);
        }
        return maxi;
    }
};