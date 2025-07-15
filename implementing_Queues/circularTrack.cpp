#include<iostream>
#include<vector>
using namespace std;

int calculate(vector<int> gas, vector<int> cost){
    int balance = 0, deficit = 0, start = 0;

    for(int i = 0 ; i < gas.size() ; i++){
        balance += gas[i] - cost[i];

        if(balance < 0){
            start = i+1;
            deficit += balance;
            balance = 0;
        }
    }
    if(balance + deficit >=0){
        return start;
    }else{
        return -1;
    }
}
int main(){
    int stations;
    cout<<"Enter the number of stations: ";
    cin>>stations;
    vector<int> gas;
    vector<int> cost;
    int Gas, Cost;

    for(int i = 0 ; i < stations ; i++){
        cout<<"Enter gas for station "<<(i+1)<<": ";
        cin>>Gas;
        gas.push_back(Gas);
        cout<<"Enter cost for station "<<(i+1)<<": ";
        cin>>Cost;
        cost.push_back(Cost);
    }

    int start = calculate(gas, cost);
    if(start != -1){
        cout<<"Starting station is "<<start<<endl;
    }else{
        cout<<"There is no starting station possible for this circular track!"<<endl;
    }
}