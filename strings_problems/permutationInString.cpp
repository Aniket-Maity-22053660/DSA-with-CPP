#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string str1 = "eidbaooo";
    string str2 = "aeae";
    bool ans = true;

    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);
    for(int i = 0 ; i < str1.length() ; i++){
        cnt1.at(str1.at(i)-'a')++;
    }
    for(int i = 0 ; i < str2.length() ; i++){
        cnt2.at(str2.at(i)-'a')++;
    }

    for(int i = 0 ; i < str2.length() ; i++){
        if(cnt1[i] != cnt2[i]){
            ans = false;
            break;
        }
    }
    if(ans){
        cout<<"Permutaion of "<<str2<<" is present in the string "<<str1<<"!"<<endl;
    }
    else{
        cout<<"Permutation of "<<str2<<" is not present in the string "<<str1<<"!"<<endl;
    }

    return 0;
}