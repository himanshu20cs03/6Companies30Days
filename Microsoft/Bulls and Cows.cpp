/* 3. Bulls and Cows */


class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>Unorderedmap;
        int Bulls=0,Cows=0,n=secret.length();
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                Bulls++;
            }
            else
            {
                Unorderedmap[secret[i]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                continue;
            }
            if(Unorderedmap[guess[i]])
            {
                Unorderedmap[guess[i]]--;
                Cows++;
            }
        }
        return (to_string(Bulls)+"A"+to_string(Cows)+"B");
    }
};
