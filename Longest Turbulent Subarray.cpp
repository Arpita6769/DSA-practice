class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int>dpOdd(n,1);
        int maxAns = 1;
        for(int k = 0 ; k<n-1 ; k++){
            if(k%2 == 0){
                if(arr[k] < arr[k+1])dpOdd[k+1] = dpOdd[k]+1;
            }
            else{
                if(arr[k] > arr[k+1])dpOdd[k+1] = dpOdd[k]+1;
            }
            maxAns = max(maxAns , dpOdd[k+1]);
        }
        vector<int>dpEven(n,1);
       
        for(int k = 0 ; k<n-1 ; k++){
            if(k%2 == 0){
                if(arr[k] > arr[k+1])dpEven[k+1] = dpEven[k]+1;
            }
            else{
                if(arr[k] < arr[k+1])dpEven[k+1] = dpEven[k]+1;
            }
            maxAns = max(maxAns , dpEven[k+1]);
        }

return maxAns;
    }
};
