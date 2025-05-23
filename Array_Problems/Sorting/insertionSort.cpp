#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq{2,3,4,3,1,23,4,6,4,3,2,4,56,6,5,4,3,4,5,7,5};
    int j ;
    for(int i = 1 ; i < dq.size() ; i++){
        int num = dq.at(i);
        j = i;
        while( j > 0 && num > dq.at(j-1)){
            dq.at(j) = dq.at(j-1);
            j--;
        }
        dq.at(j) = num;
    }

    cout<<"Insertion Sort: ";
    for(const auto& x: dq){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}