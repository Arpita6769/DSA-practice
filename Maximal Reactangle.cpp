class Solution {
public:
int rectHistogram(vector<int> &arr){
    stack<int>st;
    int n = arr.size();
    vector<int>nsi(n);
    nsi[n-1] = n;
    st.push(n-1);
    for(int i = n-2 ; i>=0 ; i--){
        while(st.size() > 0 && arr[i] <= arr[st.top()]){
            st.pop();}
        if(st.empty())nsi[i] = n;
        else nsi[i] = st.top();
        st.push(i);}

    while(!st.empty()){
        st.pop();
    }

    vector<int>psi(n);
    psi[0] = -1;
    st.push(0);
    for(int i = 1 ; i<n ; i++){
        while(st.size() > 0 && arr[i] <= arr[st.top()]){
            st.pop();}
        if(st.empty())psi[i] = -1;
        else psi[i] = st.top();
        st.push(i);}

        int maxArea = 0;
        for(int i = 0; i<n ; i++){
            int height = arr[i];
            int bdth = nsi[i]-psi[i]-1;
            int area = height*bdth;
            if(area>maxArea) maxArea = area;
        }
        return maxArea;
}
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size() , n = mat[0].size();

        vector<vector<int>>matrix(m , vector<int>(n));

        for(int i = 0; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                matrix[i][j] = mat[i][j] - '0';
            }
        }

        for(int i = 1 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j] != 0) matrix[i][j] += matrix[i-1][j];
            }
        } 
      
    int ans = -1;
        for(int i = 0 ; i<m ; i++){
            int area = rectHistogram(matrix[i]);
            cout<<area<<" ";
            if(area > ans) ans = area;
        }      
        return ans;
    }
};
