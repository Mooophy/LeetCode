class Solution {
    int next[1001][26];
public:
    int shortestWay(string source, string target) 
    {
        int n = source.size();
        source = "#" + source;
        
        for (int k=0; k<26; k++)
            next[n][k] = -1;
        
        for (int i=n-1; i>=0; i--)        
            for (int k=0; k<26; k++)
            {
                if (k == source[i+1]-'a')
                    next[i][k] = i+1;
                else
                    next[i][k] = next[i+1][k];                
            }
        
        int j = 0;
        int count = 0;
        for (int i=0; i<target.size();)
        {            
            if (next[j][target[i]-'a'] != -1)  
            {
                j = next[j][target[i]-'a'];
                i += 1;
                if (i==target.size())
                {
                    count++;
                    break;
                }                    
            }                
            else
            {
                if (j == 0)
                    return -1;
                else
                {
                    count++;
                    j = 0;
                }
            }
        }
        return count;        
    }
};
