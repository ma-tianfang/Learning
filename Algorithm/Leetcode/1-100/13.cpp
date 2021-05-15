class Solution {
public:
    unordered_map<char,int> hashMap = 
    {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int romanToInt(string s) {
        int result = 0;
        int n = s.size();

        for(int i = 0;i<n;++i)
        {
            int value = hashMap[s[i]];
            if(i+1<n&&value<hashMap[s[i+1]])
            {
                result-=value;
            }
            else
            {
                result+=value;
            }
        }
        return result;
    }
};
