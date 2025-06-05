#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkPermutation(string str1, string str2){
    
    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);
    if(str2.length() > str1.length()){
        return false;
    }

    for(int i = 0 ; i < str2.length() ; i++){
        cnt1[str1[i] - 'a']++;
        cnt2[str2[i] - 'a']++;
    }
    if(cnt1 == cnt2){
        return true;
    }
8
    for(int i = str2.length() ; i < str1.length() ; i++){ 
        cnt1[str1[i] - 'a']++;
        cnt1[str1[i - str2.length()] - 'a']--;
        if(cnt1 == cnt2)
        return true;
    }
    return false;
}

int main(){
    string str1 = "eidbaooo";
    string str2 = "ab";
    bool ans = checkPermutation(str1, str2);

    if(ans){
        cout<<"Permutaion of "<<str2<<" is present in the string "<<str1<<"!"<<endl;
    }
    else{
        cout<<"Permutation of "<<str2<<" is not present in the string "<<str1<<"!"<<endl;
    }

    return 0;
}