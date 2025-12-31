class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        //int mod = 1000000007;
        int n = arr.size();
        stack<int>st;
        vector <int> nsi(n);
        nsi[n-1] = n;

        st.push(n-1);
        for(int i = n-2 ; i>=0 ; i--){
             while(st.size() > 0 &&arr[i] < arr[st.top()]){
                st.pop();
             }
             if(st.size() != 0) nsi[i] = st.top();
             else nsi[i] = n;
             st.push(i);

        }
        stack<int>s;
        vector<int>psi(n);
        psi[0] = -1;

        s.push(0);
        for(int i = 1 ; i<n ; i++){
            while(s.size() > 0 && arr[i] <= arr[s.top()]){
                s.pop();
            }
            if(s.size() != 0) psi[i] = s.top();
            else psi[i] = -1;
            s.push(i);
        }
        long long ans = 0;
        for(int i = 0 ; i<n ; i++){
            long long num = (i - psi[i]) * (nsi[i] - i);
            long long pro = (num*arr[i]);
            ans = ans+pro;

        }
        return ans;}

        long long sumSubarrayMaxs(vector<int>& arr) {
       // int mod = 1000000007;
        int n = arr.size();
        stack<int>st;
        vector <int> nsi(n);
        nsi[n-1] = n;

        st.push(n-1);
        for(int i = n-2 ; i>=0 ; i--){
             while(st.size() > 0 &&arr[i] > arr[st.top()]){
                st.pop();
             }
             if(st.size() != 0) nsi[i] = st.top();
             else nsi[i] = n;
             st.push(i);

        }
        stack<int>s;
        vector<int>psi(n);
        psi[0] = -1;

        s.push(0);
        for(int i = 1 ; i<n ; i++){
            while(s.size() > 0 && arr[i] >= arr[s.top()]){
                s.pop();
            }
            if(s.size() != 0) psi[i] = s.top();
            else psi[i] = -1;
            s.push(i);
        }
        long long ans = 0;
        for(int i = 0 ; i<n ; i++){
           long long num = (i - psi[i]) * (nsi[i] - i);
            long long pro = (num*arr[i]);
            ans = ans+pro;
        }
        return ans;}
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
         long long minSum = sumSubarrayMins(nums);

         return maxSum-minSum;
       
    }
};
