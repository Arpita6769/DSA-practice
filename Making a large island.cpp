class Solution {
public:
int find(int x , vector<int> &parent){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x] , parent);
}
void unite_sets(int a , int b , vector<int> &size , vector<int> &parent){
    a = find(a , parent);
    b = find(b , parent);

    if(a == b)return;
    if(size[a] > size[b]){
        size[a] += size[b];
        parent[b] = a;
    }
    else{
        parent[a] = b;
        size[b]+=size[a];
    }
    return;
}

bool isValid(int i , int j , int n){
    if(i>=0 && j>=0 && i<n && j<n)return true;
    return false;
}
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>parent(n*n);
        vector<int>size(n*n , 1);
        for(int i = 0 ; i<n*n ; i++)parent[i] = i;


        vector<vector<int>>dir = {{0,1} , {0,-1} , {1,0} , {-1 , 0}};

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0)continue;

                for(int idx = 0 ; idx < 4 ; idx++){
                    int nr = i + dir[idx][0];
                    int nc = j + dir[idx][1];

                    if(isValid(nr,nc,n) && grid[nr][nc] == 1){
                            int nodeNo = i*n+j;
                            int adjNode = nr*n+nc;

                            unite_sets(nodeNo , adjNode , size , parent);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1)continue;
                set<int>s;
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nr = i + dir[idx][0];
                    int nc = j + dir[idx][1];

                    if(isValid(nr,nc,n) && grid[nr][nc] == 1){
                            int nodeNo = nr*n+nc;
                            s.insert(find(nodeNo , parent));                            
                           
                    }
                }
                int total = 0;
                for(auto it : s){
                    total += size[it];
                }
                ans = max(ans , total+1);
            }
        }
        for(int i = 0 ; i<n*n ; i++){
            ans = max(ans , size[find(i , parent)]);
        }
        return ans;
    }
};
