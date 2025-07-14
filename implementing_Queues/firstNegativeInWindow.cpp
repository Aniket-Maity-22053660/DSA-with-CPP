#include<iostream>
#include<vector>
using namespace std;

void findInWindow(vector<int> &vec, int window, vector<int> &ans){
    int start = 0 , end = start + (window - 1);
    for(int i = end, j = start ; i < vec.size() ; i++, j++){
        int flag = 1;
        for(int a = j; a <= i ; a++){
            if(vec.at(a) < 0){
                ans.push_back(vec.at(a));
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            ans.push_back(0);
        }
    }
}
void print(vector<int> arr){
    
    vector<int>::iterator it;
    for(it = arr.begin() ; it != arr.end() ; it++){
        cout<<*it<<" ";
    }
}
int main(){
    int window, arrSize;
    cout<<"Enter the array size: ";
    cin>>arrSize;
    cout<<"Enter the window size: ";
    cin>>window;
    vector<int> vec(arrSize);
    vector<int> ans;
    for(int i = 0 ; i < arrSize ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>vec.at(i);
    }
    findInWindow(vec, window, ans);
    cout<<"Given array: ";
    print(vec);
    cout<<'\n';
    cout<<"Array of first negatives in window of "<<window<<" size: ";
    print(ans);
    cout<<'\n';




    return 0;
}