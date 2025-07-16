#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void solve(int arrSize, int K){
    vector<int> vec;
    vector<pair<int, int>> ans;
    for(int i = 0 ; i < arrSize ; i++){
        cout<<"Enter teh element "<<(i+1)<<": ";
        int element;
        cin>>element;
        vec.push_back(element);
    }
    int start = 0, end = K - 1, min, max;
    while(end < arrSize){
        min = vec.at(start);
        max = vec.at(start);
        for(int i = start ; i <= end ; i++){
            if(vec.at(i) < min){
                min = vec.at(i);
            }
            if(vec.at(i) > max){
                max = vec.at(i);
            }
        }
        ans.push_back(make_pair(min, max));
        start++;
        end++;
    }
    cout<<"\n\n";
    cout<<"Initial given array: ";
    for(int i = 0 ; i < vec.size() ; i++){
        cout<<vec.at(i)<<" ";
    }
    cout<<"\n\n";
    for(int i = 0 ; i < ans.size() ; i++){
        pair<int, int> element;
        element = ans.at(i);
        cout<<"Min-Max elements for window "<<(i+1)<<":- "<<endl;
        cout<<"Min element: "<<element.first<<endl<<"Max element: "<<element.second<<endl;
    }
}

int main(){
    int arrSize, K;
    cout<<"Enter the size of the array: ";
    cin>>arrSize;
    cout<<"Enter the value of K(size of window): ";
    cin>>K;
    solve(arrSize, K);
    return 0;
}