#include<iostream>
#include<map>
#include<vector>
#include<climits>

using namespace std;

int solve(vector<int> &coins, int sum, map<int, int> &dp){
    if(sum == 0){
        dp[sum] = sum;
        return dp[sum];
    }
    if(sum < 0){
        return INT_MAX;
    }
    if(dp.find(sum) != dp.end()){
        return dp[sum];
    }
    int mini = INT_MAX;
    dp[sum] = mini;
    for(int num : coins){
        int res = solve(coins, sum - num, dp);
        if(res < mini){
            mini = res;
            dp[sum] = res + 1;
        }
    }
    return dp[sum];
}
int main(){
    map<int, int> dp;
    vector<int> coins;
    int element, num;
    cout<<"Enter the number of coins: ";
    cin>>num;
    for(int i = 0 ; i < num ; i++){
        cout<<"Enter coin-"<<(i+1)<<": ";
        cin>>element;
        coins.push_back(element);
    }
    int sum;
    cout<<"Enter the value of sum: ";
    cin>>sum;
    int ans = solve(coins, sum, dp);
    cout<<"Minimum number of coins: "<<(ans == INT_MAX ? "Not possible!" : to_string(ans))<<endl;
    return 0;
}