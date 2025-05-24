#include<iostream>
#include<vector>

using namespace std;

int main(){
    string mystring;
    vector<char> word;
    cout<<"Enter the string: ";
    getline(cin, mystring);
    string answer = "";
    for(int i = 0 ; i < mystring.length() ; i++){
        if(!isalnum(mystring.at(i)) && mystring.at(i) != ' '){
            continue;
        }
        if(mystring.at(i) != ' '){
            word.push_back(mystring.at(i));
        }
        else{
            string temp(word.begin(), word.end());
            answer = temp + " " + answer;
            word.clear();
        }
    }
    string temp(word.begin(), word.end());
    answer = temp + " " + answer;
    cout<<mystring<<endl;
    cout<<answer<<endl;
    return 0;
}