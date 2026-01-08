class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;

    // Helper to get total sum and store all possible subtree sums
    long long getSubtreeSums(TreeNode* root, vector<long long>& sums) {
        if (!root) return 0;
        
        long long currentSubtreeSum = root->val + 
                                     getSubtreeSums(root->left, sums) + 
                                     getSubtreeSums(root->right, sums);
        
        sums.push_back(currentSubtreeSum);
        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        vector<long long> sums;
        totalSum = getSubtreeSums(root, sums);
        
        for (long long s : sums) {
            long long currentProd = s * (totalSum - s);
            if (currentProd > maxProd) {
                maxProd = currentProd;
            }
        }
        
        return maxProd % 1000000007;
    }
};