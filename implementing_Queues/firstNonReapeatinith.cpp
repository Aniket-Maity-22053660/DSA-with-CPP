#include<iostream>
#include<queue>
#include<vector>

using namespace std;

string find(string str){
    queue<char> q;
    vector<int> freq(26, 0);
    string ans;
    for(char ch: str){
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        if(!q.empty()){
            ans += q.front();
        }else{
            ans += '#';
        }
    }
    return ans;
}

int main(){
    string str = "aabcbc";
    string ans = find(str);
    cout<<ans<<endl;
    return 0;
}