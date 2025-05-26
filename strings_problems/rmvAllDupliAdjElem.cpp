#include<iostream>
#include<string>

using namespace std;

int main(){
    string str = "azxxzy";
    int s = 0 , e = str.length();

    cout<<"Given string: "<<str<<endl;
    while(s < str.length() - 1){
        if(str.at(s) == str.at(s+1)){
            str.erase(s, 2);
            s = 0;
        }
        else{
            s++;
        }
    }
    
    cout<<"After removing all adjacent duplicates from the string: "<<str<<endl;
    return 0;
}