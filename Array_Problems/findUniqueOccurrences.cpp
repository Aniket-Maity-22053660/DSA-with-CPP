#include<iostream>
#include<map>
#include<set>

using namespace std;

int main(){
    int arr[] = {1,2,2,2,3,3,3,4,4};
    bool ans = true;
    map<int, int> mp;
    set<int> st;

    for(const auto &x: arr){
        mp[x]++;
    }

    map<int, int>:: iterator it;
    for(it = mp.begin() ; it != mp.end() ; it++){
        if(!st.count(it->second)){
            st.insert(it->second);
        }
        else{
            ans = false;
            break;
        }
    }

    if(ans){
        cout<<"Yes, the array has unique occurrences of elements!"<<endl;
    }
    else{
        cout<<"The array does not have unique occurrences of elements!"<<endl;
    }

    return 0;
}