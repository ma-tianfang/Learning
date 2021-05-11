class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int xorN = 0;
        
        switch((n+1)%4)
        {
            case 1:
            {
                xorN = 1;
                break;
            }
            case 2:
            {
                xorN = n+2;
                break;
            }
            case 3:
            {
                xorN = 0;
                break;
            }    
            default:
            {
                xorN = n+1;
                break;
            }
        }

        int exceptFirst = 0;
        for(int i = 1;i<n;i+=2)
        {
            exceptFirst^=encoded[i];
        }

        vector<int>decoded(n+1);
        decoded[0] = exceptFirst^xorN;

        for(int i = 1;i<=n;++i)
        {
            decoded[i] = decoded[i-1]^encoded[i-1];
        }
        
        return decoded;
    }
};
