class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int , int>>>adj(n);
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        int ans = -1 ,minCount = INT_MAX;
        for(int i = 0; i<n ; i++){
            vector<int>dist(n , INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>>pq;
            pq.push({0 , i});

            while(!pq.empty()){
                auto[d , node] = pq.top();
                pq.pop();

                if(d > distanceThreshold)continue;

                for(auto[v ,price] : adj[node]){
                    int newDist = price+d;
                    if(newDist < dist[v]){
                        dist[v] = newDist;
                        pq.push({dist[v] , v});
                    }
                }                
            }
            int cnt = 0;
            for(int j = 0 ; j<n ; j++){
                if(j != i && dist[j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt < minCount || (cnt == minCount && ans < i)){
                minCount = cnt;
                ans = i;
            }

        }
        return ans;
    }
};
