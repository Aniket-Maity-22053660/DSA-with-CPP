#include<iostream>

using namespace std;

bool checkPalindrome(string name, int l , int r){
    if(l > r){
        return true;
    }
    else if(name[l] != name[r]){
        return false;
    }else{
        return checkPalindrome(name, l+1, r-1);
    }
}
int main(){
    string name = "Satas";
    bool ans = checkPalindrome(name, 0, name.length()-1);
    if(ans){
        cout<<"yes! the string is a palindrome.";
    }
    else{
        cout<<"The string is not a palindrome!";
    }
    cout<<'\n';
    return 0;
}