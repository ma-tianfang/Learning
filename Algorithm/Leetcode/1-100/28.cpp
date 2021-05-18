class Solution {
public:
    void BuildMatch(const string &pattern,vector<int>&match)
    {
        int m = pattern.size();

        for(int j = 1;j<m;++j)
        {
            int i = match[j-1];
            while(i>=0&&pattern[i+1]!=pattern[j])
            {
                i = match[i];
            }
            if(pattern[i+1]==pattern[j])
            {
                match[j] = i+1;
            }
            else
            {
                match[j]=-1;
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        int p1 = 0,p2 = 0;

        if(n<m)
        {
            return -1;
        }

        vector<int>match(m,-1);
        BuildMatch(needle,match);

        while(p1<n&&p2<m)
        {
            if(haystack[p1]==needle[p2])
            {
                p1+=1;
                p2+=1;
            }
            else if(p2>0)
            {
                p2 = match[p2-1]+1;
            }
            else
            {
                p1+=1;
            }
        }

        return p2==m?p1-m:-1;
    }
};
