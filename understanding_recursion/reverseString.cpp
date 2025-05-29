#include<iostream>
#include<algorithm>
using namespace std;

void reverseString(string &name, int l , int r){

    if(l > r){
        return;
    }
    /* char temp = name[l];
    name[l] = name[r];
    name[r] = temp;
    */
    swap(name[l], name[r]);
    reverseString(name, l+1, r-1);

}
int main(){
    string name = "Aniket Maity";
    reverseString(name, 0, name.size()-1);
    cout<<"After reversal: "<<name<<endl;
    return 0;
}