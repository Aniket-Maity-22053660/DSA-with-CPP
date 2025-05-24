#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    string mystring;
    vector<char> word;
    deque<char> dq;
    cout<<"Enter the string: ";
    getline(cin, mystring);
    string answer = "";
    string answer2 = "";
    for(int i = 0 ; i < mystring.length() ; i++){
        if(!isalnum(mystring.at(i)) && mystring.at(i) != ' '){
            continue;
        }
        if(mystring.at(i) != ' '){
            word.push_back(mystring.at(i));
            dq.push_front(mystring.at(i));
        }
        else{
            string temp(word.begin(), word.end());
            string temp2(dq.begin(), dq.end());
            answer = temp + " " + answer;
            answer2 = temp2 + " " + answer2;
            word.clear();
            dq.clear();
        }
    }
    string temp(word.begin(), word.end());
    string temp2(dq.begin(), dq.end());
    answer = temp + " " + answer;
    answer2 = temp2 + " " + answer2;
    cout<<mystring<<endl;
    cout<<answer<<endl;
    cout<<answer2<<endl;
    return 0;
}