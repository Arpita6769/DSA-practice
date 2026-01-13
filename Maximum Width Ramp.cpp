class Solution {
public:
    int maxWidthRamp(vector<int>& num) {
        int n = num.size();
       int ans = 0;
      /* for(int i = 0 ; i<n-1 ; i++){
        int j = n-1;
        while(j > i && num[j] < num[i])j--;

        ans = max(ans , j-i);
       }*/


      // return ans;
       vector<int>leftMin(n) , rightMax(n);
        leftMin[0] = num[0];
        rightMax[n-1] = num[n-1];
       for(int i = 1 ; i<n ; i++){
        leftMin[i] = min(leftMin[i-1] , num[i]);
       }
       for(int i = n-2 ; i>=0 ; i--){
        rightMax[i] = max(rightMax[i+1] , num[i]);
       }

       int i = 0 , j = 0;
       while(i<n && j<n){
        if(leftMin[i] <= rightMax[j]){
            ans = max(ans , j-i);
            j++;
        }
        else i++;
       }
       return ans;
    }

};
