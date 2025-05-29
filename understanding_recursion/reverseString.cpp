#include<iostream>
#include<algorithm>
using namespace std;

string reverseString(string name, int l , int r){

    if(l > r){
        return name;
    }
    /* char temp = name[l];
    name[l] = name[r];
    name[r] = temp;
    */
    swap(name[l], name[r]);
    return reverseString(name, l+1, r-1);

}
int main(){
    string name = "Aniket Maity";
    string ans =  reverseString(name, 0, name.size()-1);
    cout<<"After reversal: "<<ans<<endl;
    return 0;
}