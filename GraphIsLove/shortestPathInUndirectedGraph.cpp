#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<queue>

using namespace std;

template<class T>
class ShortestPath{
    map<T, list<T>> adj;
    map<T, bool> visited;
    map<T, T> parents;
    int V, E, directed;
    public:
    ShortestPath(){
        
        cout<<"Enter the number of vertices: ";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;

    }

};