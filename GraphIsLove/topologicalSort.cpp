#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<stack>

using namespace std;

template<class T>
class TopologicalSort{
    map<T, list<T>> adj;
    vector<T> vertices;
    int V, E, directed;
    vector<T> ans;
    stack<T> st;
    map<T, bool> visited;
    void connectEdges(){
        T u, v, element;

        for(int i = 0 ; i < V ; i++){
            cout<<"Enter the value of vertice-"<<(i+1)<<": ";
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
        cout<<endl<<"The Graph:- "<<endl<<endl;
        printGraph();
    }

    void printGraph(){
        for(pair<T, list<T>> x: adj){
            cout<<x.first<<"->";
            for(T y : x.second){
                cout<<y<<" ";
            }
            cout<<'\n';
        }
    }

    void dfs(T curr){
        for(T nbr : adj[curr]){
            if(!visited[nbr]){
                visited[nbr] = true;
                dfs(nbr);
            }
        }
        st.push(curr);
    }
    public:
    TopologicalSort(){
        cout<<"Is it a directed graph? ";
        cin>>directed;
        cout<<"Enter the number of vertices:";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;
        connectEdges();
    }
    void sortTopologically(){
        for(int i = 0 ; i < V ; i++){
            if(!visited[vertices[i]]){
                visited[vertices[i]] = 1;
                dfs(vertices[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        typename vector<T>::iterator it;
        cout<<endl<<"Topological order: ";
        for(it = ans.begin() ; it != ans.end() ; it++){
            cout<<*it<<" ";
        }
        cout<<'\n';
    }
};

int main(){
    TopologicalSort<char>* obj = new TopologicalSort<char>();
    obj->sortTopologically();
    return 0;
}