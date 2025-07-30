#include<iostream>
#include<map>
#include<list>

using namespace std;

template<class T>
class Graph{
    map<T, list<T>> mp;
    public:
    void addEdge(T u, T v, int isDirect){
        mp[u].push_back(v);
        if(!isDirect){
            mp[v].push_back(u);
        }
    }
    void printGraph(){
        for(pair<T, list<T>> i : mp){
            cout<<i.first<<"->";
            for(T j : i.second){
                cout<<j<<" ";
            }
            cout<<'\n';
        }
    }
};

int main(){
    int u, v, n, m, directed;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Is it a directed graph? ";
    cin>>directed;

    Graph<int>* obj = new Graph<int>();

    for(int i = 0 ; i < m ; i++){
        cout<<"Enter the value of u: ";
        cin>>u;
        cout<<"Enter the value of v: ";
        cin>>v;
        obj->addEdge(u, v, directed);
    }
    obj->printGraph();
    return 0;
}