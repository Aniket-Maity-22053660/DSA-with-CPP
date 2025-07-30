#include<iostream>
#include<map>
#include<list>

using namespace std;

class Graph{
    map<int, list<int>> mp;
    public:
    void addEdge(int u, int v, int isDirect){
        mp[u].push_back(v);
        if(!isDirect){
            mp[v].push_back(u);
        }
    }
    void printGraph(){
        for(pair<int, list<int>> i : mp){
            cout<<i.first<<"->";
            for(int j : i.second){
                cout<<j<<", ";
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

    Graph* obj = new Graph();

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