#include<iostream>

using namespace std;

int countWays(int num){
    if(num < 0){
        return 0;
    }
    if(num == 0){
        return 1;
    }
    return countWays(num - 1) + countWays(num - 2);
}
int main(){
    int num;
    cout<<"Enter the nth step: ";
    cin>>num;
    int ans = countWays(num);
    cout<<"Total "<<ans<<" ways are possible to climb the "<<num<<"th stairs!"<<endl;

    return 0;
}