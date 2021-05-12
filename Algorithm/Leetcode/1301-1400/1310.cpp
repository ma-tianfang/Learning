class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>xors(n+1);
        for(int i = 0;i<n;++i)
        {
            xors[i+1] = xors[i]^arr[i]; 
        }
        int m = queries.size();
        vector<int>result(m);

        for(int i = 0;i<m;++i)
        {
            result[i] = xors[queries[i][0]]^xors[queries[i][1]+1];
        }

        return result;
    }
};
