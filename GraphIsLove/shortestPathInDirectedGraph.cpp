class Solution {
           
           void dfs(map<int, list<pair<int, int>>> &adj, int curr, vector<int> &visited, stack<int> &st){
               
               for(pair<int, int> x: adj[curr]){
                   if(!visited[x.first]){
                       visited[x.first] = 1;
                       dfs(adj, x.first, visited, st);
                   }
               }
               
               st.push(curr);
               return;
           }                                                                 

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<int> distance(V, INT_MAX);
        map<int, list<pair<int, int>>> adj;
        for(vector<int> y : edges){
            adj[y[0]].push_back({y[1], y[2]});
        }
        vector<int> visited(V, false);
        stack<int> st;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(adj, i, visited, st);
            }
        }
        distance[0] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(distance[top] != INT_MAX){
                int u = top;
                for(pair<int, int> x : adj[top]){
                    int v = x.first;
                    int wt = x.second;
                    if(distance[u] + wt < distance[v]){
                        distance[v] = distance[u] + wt;
                    }
                }
            }
        }
        for(int i = 0 ; i < V ; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};
