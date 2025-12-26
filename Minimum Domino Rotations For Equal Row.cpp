#include<iostream>
#include<vector>
using namespaec std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        int f = tops[0] , top = 0 , bot = 0 , com = 0;
        int ans = INT_MAX;
        for(int i = 0 ; i<n ; i++){
            if(tops[i] == f && bottoms[i] == f)com++;
            else{
                if(tops[i] == f)top++;
                if(bottoms[i] == f)bot++;
            }
        }
        if(top+com+bot == n){
            ans = min(top , bot);
        }
       

     f = bottoms[0] , top = 0 , bot = 0 , com = 0;
        for(int i = 0 ; i<n ; i++){
            if(tops[i] == f && bottoms[i] == f)com++;
            else{
                if(tops[i] == f)top++;
                if(bottoms[i] == f)bot++;
            }
        }
        int fb = INT_MAX , sb = INT_MAX ;
        if(top+bot+com == n) {
             ans = min(ans , min(top , bot));}

             if(ans == INT_MAX)return -1;
             else return ans;

           


        
    }
};
