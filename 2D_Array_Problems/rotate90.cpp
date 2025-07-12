#include<iostream>
#include<vector>
#include<list>

#define Row 2
#define Col 3
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}};
    //vector<int> row (arr.size());
    vector<vector<int>> ans(Col, vector<int> (Row));
    for(int i = 0 ; i < Row ; i++){
        for(int j = 0 ; j < Col ; j++){
            
            ans[j][(arr.size()-1)-i] = arr[i][j];
        }
    }

    for(int i = 0 ; i < Col ; i++){
        for(int j = 0 ; j < Row ; j++){
            ans[i][j] = arr[(Row-1)-j][i];
        }
    }
    
    list<list<int>> li;

    for(int i = 0 ; i < Col ; i++){
        list<int> li1;
        for(int j = 0 ; j < Row ; j++){
            li1.push_front(arr[j][i]);
        }
        li.push_back(li1);
    }

    
    list<list<int>>:: const_iterator rowIt = li.cbegin();
    list<int>:: const_iterator colIt;
    
    for(; rowIt != li.cend() ; rowIt++){
        for(colIt = rowIt->cbegin(); colIt != rowIt->cend() ; colIt++){
            cout<<*colIt<<" ";
        }
        cout<<endl;
    }
    return 0;
}