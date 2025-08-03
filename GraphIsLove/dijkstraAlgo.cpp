#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<list>
#include<climits>

using namespace std;

template<class T>
class ShortestPathInDirectedGraph{
    map<T, list<pair<T, int>>> adj;
    vector<T> vertices;
    map<T, int> distance;
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    int V, E, directed = 0;
    T src;
    
    void getVertices(){
        T element;
        for(int i = 0 ; i < V ; i++){
            cout<<"Enter the vertice"<<(i+1)<<": ";
            cin>>element;
            vertices.push_back(element);
        }
    }
    void connectEdge(){
        T u;
        T v;
        int w;
        for(int i = 0 ; i < E ; i++){
        cout<<"Enter the value of u: ";
        cin>>u;
        cout<<"Enter the value of v: ";
        cin>>v;
        cout<<"Enter the value of w: ";
        cin>>w;
        adj[u].push_back(make_pair(v, w));
        if(!directed){
            adj[v].push_back(make_pair(u, w));
        }
    }
    }

    void printDistance(){
        cout<<endl<<"Shortest distance from "<<src<<" to all vertices:-"<<endl;
        typename map<T, int>::iterator it;
        for(it = distance.begin() ; it != distance.end() ; it++){
            cout<<it->first<<"->"<<it->second<<endl;
        }
    }

    public:
    ShortestPathInDirectedGraph(){
        cout<<"Is this graph directed? ";
        cin>>directed;
        if(!directed){
            
        }
        cout<<"Enter the number of vertices: ";
        cin>>V;
        cout<<"Enter the number of edges: ";
        cin>>E;
        cout<<"Enter the value of src: ";
        cin>>src;
        getVertices();
        connectEdge();
        
        for(int i = 0 ; i < V ; i++){
            distance[vertices[i]] = INT_MAX; 
        }
    }
    void findShortest(){
        distance[src] = 0;
        pq.push(make_pair(0, src));
        while(!pq.empty()){
            pair<int, T> num = pq.top();
            pq.pop();
            for(pair<T, int> x: adj[num.second]){
                if(distance[num.second] + x.second < distance[x.first]){
                    distance[x.first] = distance[num.second] + x.second;
                    pq.push(make_pair(distance[x.first], x.first));
                }
            }
        }
        printDistance();
    }
};

int main(){
    cout<<"Dijkstras Algorithm:- "<<endl;
    ShortestPathInDirectedGraph<char>* obj = new ShortestPathInDirectedGraph<char>();
    obj->findShortest();
    cout<<endl;
    return 0;
}