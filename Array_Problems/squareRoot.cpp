#include<iostream>

using namespace std;

double precision(int num, int precision, double ans){
    double factor = 1.00;
    for(int i = 0 ; i < precision ; i++){
        factor /= 10;
        for(double j = ans ; j*j < num ; ans = j, j += factor);
        //ans = ans - factor;
        
    }
    return ans;
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    double ans = -1;
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
            ans = mid;
            left = mid + 1;
        }
    }
    if(ans != -1)
    {
        ans = precision(num, 10, ans);
        cout<<"Square root of "<<num<<": "<<ans<<endl;
    }
  
    return 0;
}