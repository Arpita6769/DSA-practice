#include<iostream>
#include>vector>
using namespace std;


Class Solution{
public:
    int jump(vector<int>& nums) {
        int l = 0 , r = 0 , jumps = 0;
        int n = nums.size();
        while(r < n-1){
            int farthest = 0;
            for(int i = l ; i<=r ; i++){
                farthest = max(farthest , i+nums[i]);
            } 
             jumps++;
               l  = r+1;
                r = farthest;
       }
       return jumps;
    }
};
