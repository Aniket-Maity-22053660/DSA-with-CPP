#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main(){
    vector<int> vec1{1,22,3,4};
    vector<int> vec2{2,3,4,5};
    list<int> ans;

    int i = vec1.size()-1, j = vec2.size()-1, carry = 0;

    while(i >= 0 && j >= 0){
        int sum = vec1.at(i) + vec2.at(j) + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_front(sum);
        i--;
        j--;
    }

    while(i >= 0){
        int sum = vec1.at(i) + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_front(sum);
        i--;
    }
    while(j >= 0){
        int sum = vec2.at(j) + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_front(sum);
        j--;
    }

    while(carry != 0){
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_front(sum);
    }

    list<int>:: iterator it = ans.begin();
    
    cout<<"1st Array: ";
    for(const auto& x: vec1){
        cout<<x<<" ";
    }
    cout<<endl<<"2nd Array: ";
    for(const auto& x: vec2){
        cout<<x<<" ";
    }
    cout<<endl<<"After Addition: ";
    while(it != ans.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    return 0;
}