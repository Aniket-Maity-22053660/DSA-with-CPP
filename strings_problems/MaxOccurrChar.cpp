#include<iostream>
#include<map>

using namespace std;

int main(){
    string myString;
    cout<<"Enter your string: ";
    cin>>myString;

    map<char, int> mp;
    for(int i = 0 ; i < myString.length() ; i++){
        mp[myString.at(i)]++;
    }

    map<char, int>:: iterator max = mp.begin();
    map<char, int>:: iterator it;

    
    for(it = mp.begin(); it != mp.end() ; it++){
        if(it->second >= max->second){
            if(it->second == max->second){
                if (it->first < max->first) {
                max = it;
                }
            }else{
            max = it;
            }
        }
    }

    cout<<"The maximum occurring character in the string was found to be: "<<max->first<<endl;
    return 0;
}