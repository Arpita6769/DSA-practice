class Solution {
public:
vector<vector<unsigned long long>>dp;
    int numDistinct(string s, string t) {
        int m = s.length() , n = t.length();

        dp.resize(m+1 , vector<unsigned long long>(n+1));
        for(int j = 0 ; j<=n ; j++){
            dp[0][j] = 0;
        }
        for(int i = 0 ; i<=m ; i++){
            dp[i][0] = 1;
        }
       

        for(int i = 1 ; i<=m ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (unsigned long long)dp[i-1][j-1] +(unsigned long long) dp[i-1][j];
                }
                else dp[i][j] =dp[i-1][j];
            }
        }
        return dp[m][n];
        
    }
};
