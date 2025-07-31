#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<list>

using namespace std;

template<class T>
class CycleDetection{
    map<T, list<T>> adj;
    map<T, int> indegree;
    map<T, bool>  visited;
    vector<T> vertices;
    vector<T> ans;
    queue<T> q;
    int V, E, directed;

    void connectEdges(){
        T u, v, element;
        for(int i = 0 ; i < V ; i++){
            cout<<"Enter the vertice-"<<(i+1)<<": ";
            cin>>element;
            vertices.push_back(element);
            indegree[element] = 0;
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
            indegree[v]++;
        }
        printGraph();
    }
    void printGraph(){
        cout<<endl<<"The Graph:-"<<endl;
        for(pair<T, list<T>> x: adj){
            cout<<x.first<<"->";
            for(T y : x.second){
                cout<<y<<" ";
            }
            cout<<'\n';
        }
        return;
    }
    public:
    CycleDetection(){
        cout<<"Is it a directed graph? ";
        cin>>directed;
        cout<<"Enter the number of vertices: ";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;
        connectEdges();
    }
    void detectCycle(){
        for(int i = 0 ; i < V ; i++){
            if(indegree[vertices[i]] == 0){
                q.push(vertices[i]);
            }
        }
        while(!q.empty()){
            T front = q.front();
            q.pop();
            ans.push_back(front);
            for(T nbr : adj[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        cout<<"Topological order: ";
        if(!ans.empty()){
        for(T x : ans){
            cout<<x<<" ";
        }
        }else{
            cout<<"Cycle exits!";
        }
        cout<<endl<<"Does graph contain any cycle? ";
         if(!(ans.size() == V)){
            cout<<"Yes!"<<endl;
         }else{
            cout<<"No!"<<endl;
         }
    }
};

int main(){
    CycleDetection<char>* obj = new CycleDetection<char>();
    obj->detectCycle();
    
   
    return 0;
}