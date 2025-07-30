#include<iostream>
#include<map>
#include<queue>
#include<utility>
#include<list>
#include<vector>

using namespace std;

class DetectCycleInUndirected{

    map<int, list<int>> mp;
    
    int V, E;
    public:
    DetectCycleInUndirected(){
        int u, v, directed = 0;
        cout<<"Is it a directed graph? ";
        cin>>directed;
        cout<<"Enter the number vertices: ";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;
        for(int i = 0 ; i < E ; i++){
            cout<<"Enter the value of u: ";
            cin>>u;
            cout<<"Enter the value of v: ";
            cin>>v;
            mp[u].push_back(v);
            if(!directed){
                mp[v].push_back(u);
            }
        }
    }
    void printGraph(){
        for(pair<int, list<int>> x : mp){
            cout<<x.first<<"-> ";
            for(int y : x.second){
                cout<<y<<" ";
            }
            cout<<'\n';
        }
    }
    bool detectCycle(){
        map<int, bool> visited;
        for(pair<int, list<int>> x : mp){
            if(!visited[x.first]){
                int nodeCurr = x.first; 
                queue<pair<int, int>> q;
                q.push(make_pair(nodeCurr, -1));
                visited[nodeCurr] = 1;
                while(!q.empty()){
                    pair<int, int> myNode = q.front();
                    q.pop();
                    for(int y : mp[myNode.first]){
                        if(!visited[y]){
                            q.push(make_pair(y, myNode.first));
                            visited[y] = 1;
                        }else{
                            if(y != myNode.second){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    DetectCycleInUndirected* obj = new DetectCycleInUndirected();
    cout<<'\n';
    obj->printGraph();
    cout<<'\n';
    cout<<(obj->detectCycle()?"Graph contains cycle!" : "Graph does not contain any cycle!")<<endl;
    return 0;
}