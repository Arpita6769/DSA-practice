class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>>adj(n);
        for(int i = 0 ; i<roads.size() ; i++){
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        const int MOD = 1e9 + 7;
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<>>pq;
        pq.push({0 , 0});
        vector<long long>dist(n , LLONG_MAX);
        vector<int>ways(n);
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto[d , node] = pq.top();
            pq.pop();

            if(d > dist[node])continue;
            //if(node == n-1) break;

            for(auto[v , c] : adj[node]){
               if(dist[v] > dist[node] + c){
                    dist[v] = dist[node] + c;
                    ways[v] = ways[node];
                    pq.push({dist[v] , v});
                }
                else if(c+dist[node] == dist[v]){
                    ways[v]  = (ways[v] + ways[node])%MOD;;
                }
            } 
        }
        return ways[n-1];
        
    }
};
