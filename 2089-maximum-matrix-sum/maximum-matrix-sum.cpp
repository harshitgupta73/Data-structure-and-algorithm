class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int neg=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<=0){
                    neg++;
                }
                mini=min(abs(matrix[i][j]),mini);
            }
        }
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int el=abs(matrix[i][j]);
                sum+=el;
            }
        }
        if(neg%2==1){
            sum-=2*mini;
        }
        return sum;
    }
};