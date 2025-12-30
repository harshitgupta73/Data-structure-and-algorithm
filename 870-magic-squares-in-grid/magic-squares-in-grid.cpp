class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        vector<int> count(16, 0); 
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                int val = grid[i + r][j + c];
                if (val < 1 || val > 9) return false;
                count[val]++;
                if (count[val] > 1) return false; 
            }
        }
        int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != s) return false;
        if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != s) return false;

        if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != s) return false;
        if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != s) return false;
        if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != s) return false;

        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) return false;
        if (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != s) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3) return 0;
        
        int cnt = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (grid[i + 1][j + 1] != 5) continue; 
                
                if (isValid(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};