class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            if(s.contains(i)) return i;
            s.insert(i);
        }
        return 0;
    }
};