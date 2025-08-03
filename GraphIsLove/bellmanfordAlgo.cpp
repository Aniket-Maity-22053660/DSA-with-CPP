// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        const long long INF = 1e8;
        map<int, list<pair<int, int>>> adj;
        for(vector<int> vec : edges){
            adj[vec.at(0)].push_back(make_pair(vec.at(1), vec.at(2)));
        }
        vector<long long> distance(V, INF);
        distance[src] = 0;
        for(int i = 1 ; i <= V-1 ; i++){
            map<int, list<pair<int, int>>>::iterator it;
            for(it = adj.begin() ; it != adj.end() ; it++){
                int u = it->first;
                for(pair<int, int> x: it->second){
                    int v = x.first;
                    int w = x.second;
                    if(distance[u] != INF && distance[u] + w < distance[v]){
                        distance[v] = distance[u] + w;
                    }
                }
            }
        }
        map<int, list<pair<int, int>>>:: iterator it;
        for(it = adj.begin() ; it != adj.end() ; it++){
            int u = it->first;
            for(pair<int, int> x : it->second){
                int v = x.first;
                int w = x.second;
                if(distance[u] != INF && distance[u] + w < distance[v]){
                    vector<int> ans{-1};
                    return ans;
                }
            }
        }
        vector<int> ans(V);
        for(int i = 0 ; i < V ; i++){
            ans[i] = (distance[i] >= INF ? INF : distance[i]);
        }
        
        return ans;
    }
};
