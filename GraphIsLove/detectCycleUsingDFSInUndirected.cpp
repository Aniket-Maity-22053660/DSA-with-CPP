#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

template<class T>
class DetectCycleUsingDFS{
    map<T, list<T>> adj;
    map<T, bool> visited;
    map<T, T> parent;
    vector<T> vertices;
    int V, E;
    public:
    DetectCycleUsingDFS(){
        T u, v, directed = 0;
        T element;
        cout<<"Is it a directed graph? ";
        cin>>directed;
        cout<<"Enter the number vertices: ";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;
        for(int i = 0 ; i < V ; i++){
            cout<<"Enter the vertice-"<<(i+1)<<": ";
            cin>>element;
            vertices.push_back(element);
        }
        for(int i = 0 ; i < E ; i++){
        cout<<"Enter the value of u: ";
        cin>>u;
        cout<<"Enter the value of v: ";
        cin>>v;
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
        }
        for(int i = 0 ; i < V ; i++){
            visited[vertices[i]] = false;
        }
    }
    void printGraph(){
        for(pair<T, list<T>> x: adj){
            cout<<x.first<<"->";
            for(T y: x.second){
                cout<<y<<" ";
            }
            cout<<'\n';
        }
        return;
    }
    bool dfs(T curr, T Parent){
        for(T nbr : adj[curr]){
            if(!visited[nbr]){
                visited[nbr] = 1;
                if(dfs(nbr, curr)){
                    return true;
                }
            }else{
                if(nbr != Parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool detectCycle(){
        for(int i = 0 ; i < V ; i++){
        if(!visited[vertices[i]]){
        visited[vertices[i]] = true;
        if(dfs(vertices[i], T())){
            return true;
        };
    }
        }
        return false;
    }
};
int main(){
    DetectCycleUsingDFS<char>* obj = new DetectCycleUsingDFS<char>();
    cout<<'\n';
    cout<<"The graph:-"<<endl;
    obj->printGraph();

    cout<<endl<<"Does this graph contain any cycle? ";
    cout<<(obj->detectCycle() ? "Yes!" : "No!")<<endl;
    return 0;
}