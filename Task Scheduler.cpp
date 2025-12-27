#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>mp;
        for(char c : tasks){
            mp[c]++;
        }
        priority_queue<int>pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n+1;

            while(cycle>0 && !pq.empty()){
                int task = pq.top();
                pq.pop();
                task--;
                if(task > 0) temp.push_back(task);
                cycle--;
                time++;

            }
            for(int x : temp){
                pq.push(x);
            }
            if(!pq.empty()){
                time += cycle;
            }
        }
        return time;
    }
};
