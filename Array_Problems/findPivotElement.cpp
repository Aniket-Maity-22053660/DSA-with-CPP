#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec {1,2,3,7,8,9};
    int left = 0, right = vec.size()-1;

    while(left< right){
        int mid = left+(right-left)/2;

        if(vec[mid] < vec[0]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    cout<<"Pivot element: "<<vec.at(right)<<endl;

    return 0;
}