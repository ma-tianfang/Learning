class Solution {
public:
    const int MOUDLO = 1000000007;

    int numWays(int steps, int arrLen) {
        int column = min(steps,arrLen-1);
        vector<int>dp(column+1);
        dp[0]=1;
        for(int i = 1;i<=steps;++i)
        {
            vector<int>dpNext(column+1);
            for(int j = 0;j<=column;++j)
            {
                dpNext[j]=dp[j];
                if(j-1>=0)
                {
                    dpNext[j] = (dpNext[j] + dp[j-1]) % MOUDLO;
                }
                if(j+1<=column)
                {
                    dpNext[j] = (dpNext[j] + dp[j+1]) % MOUDLO;
                }
            }
            dp = dpNext;
        }
        return dp[0];
    }
};
