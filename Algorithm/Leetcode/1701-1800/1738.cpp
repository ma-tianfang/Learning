class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>pre(m+1,vector<int>(n+1));

        vector<int>result;

        for(int i = 1;i<=m;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                pre[i][j] = pre[i-1][j]^pre[i][j-1]^pre[i-1][j-1]^matrix[i-1][j-1];
                result.push_back(pre[i][j]);
            }
        }

        nth_element(result.begin(),result.begin()+k-1,result.end(),greater<int>());
        
        return result[k-1];
    }
};
