#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> vec1{1,2,1,4,3,2,6,4,3,2,7,5,3,4,5,6,7};
    vector<int> vec2{12,34,65,67,42,376, 8946,2345,56,21};
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    vector<int> vec3 (vec1.size() + vec2.size());

    int i = 0, j = 0, k=0;

    while(i < vec1.size() && j < vec2.size()){
        if(vec1.at(i) < vec2.at(j)){
            vec3.at(k++) = vec1.at(i);
            i++;
        }
        else{
            vec3.at(k++) = vec2.at(j);
            j++;
        }
    }
    while(i < vec1.size()){
        vec3.at(k++) = vec1.at(i++);
    }
    while(j < vec2.size()){
        vec3.at(k++) = vec2.at(j++);
    }
    cout<<"Merged Array: ";
    for(const auto& x: vec3){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}