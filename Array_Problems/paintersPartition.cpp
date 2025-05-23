#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int> vec, int mid, int painters){
    int paintersCnt = 1, totalTime = 0;
    for(int i = 0 ; i < vec.size() ; i++){
        if(vec[i]+totalTime <= mid){
            totalTime +=vec[i];
        }
        else{
            paintersCnt++;
            totalTime = vec[i];
            if(paintersCnt > painters || vec[i] >  mid){
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<int> vec{5, 5, 5, 5};
    int painters = 2, start = 0 , end = 0, ans = -1;

    for(const auto &x: vec){
        end += x;
    }

    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossible(vec, mid, painters)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout<<"Largest minimum distance was found: "<<ans<<endl;


    return 0;
}