#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr1 = {1,2,3,3,4,4,5,5,6};
    vector<int> arr2 = {2,3,4,2,7,6,7,8,4};
    map<int, int> mp;
    vector<int> vec;

    for(const auto &x: arr1){
        mp[x]++;
    }

    
    for(const auto &x: arr2){
      
        if(mp[x] > 0){
            vec.push_back(x);
            mp[x]--;
        }
    
    }
    vector<int>:: iterator it;
    cout<<"Intersection Array: ";
    sort(vec.begin(), vec.end());
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}