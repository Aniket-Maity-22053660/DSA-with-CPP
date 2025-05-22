#include<iostream>

using namespace std;

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int ans = -1;
    int left = 1, right = num;
    while(left <= right){
        int mid = left + (right - left)/2;

        if(mid*mid == num){
            ans = mid;
            break;
        }
        else if(mid*mid > num){
            right = mid - 1;
        }
        else{
            ans = left;
            left = mid + 1;
        }
    }
    if(ans != -1){
        cout<<"Square root of "<<num<<": "<<ans<<endl;
    }
    else{
        cout<<"Square root of "<<num<<": "<<ans<<endl;
    }
    return 0;
}