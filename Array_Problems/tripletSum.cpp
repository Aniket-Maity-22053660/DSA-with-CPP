#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,2,4,5,2,6,7,6,8,9};
    vector<int> vec(arr, arr+(sizeof(arr)/sizeof(int)));
    vector<vector<int>>  ans;
    int sum = 9;
    int left, right;

    sort(vec.begin(), vec.end());

    for(int i = 0 ; i < vec.size()-2 ; i++){
        left = i+1;
        right = vec.size()-1;

        while(left<right){
            int total = vec[i]+vec[left]+vec[right];
            if(sum == total){
                vector<int> temp {vec[i], vec[left], vec[right]};
                ans.push_back(temp);
                left++;
                right--;
            }
            else if(total < sum){
                left++;
            }
            else{
                right--;
            }
        }
    }

    cout<<"Triplet sum: ";
    vector<int>:: iterator it;
    for(const auto &triplet: ans){
     cout << "(" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << ") ";
    }
    cout<<endl;
    return 0;
}