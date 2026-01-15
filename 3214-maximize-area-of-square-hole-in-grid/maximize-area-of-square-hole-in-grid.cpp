class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int hx=1;
        int hMax=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-1==hBars[i-1]){
                hx++;
                hMax=max(hMax,hx);
            }
            else{
                hx=1;
            }
        }

        int vx=1;
        int vMax=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-1==vBars[i-1]){
                vx++;
                vMax=max(vMax,vx);
            }
            else{
                vx=1;
            }
        }

        return (min(hMax,vMax)+1)*(min(hMax,vMax)+1);

    }
};