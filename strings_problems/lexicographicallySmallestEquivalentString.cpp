#include<iostream>
#include<vector>
using namespace std;

int find(int x, vector<int> &groups){
    if(groups.at(x) != x){
         groups.at(x) = find(groups.at(x), groups);
    }
    return groups[x];
}
void unite(int x, int y, vector<int> &groups){
    int px = find(x, groups);
    int py = find(y, groups);
    if(px == py){
        return;
    }
    else if(px < py){
        groups.at(py) = px;
    }
    else{
        groups.at(px) = py;
    }
}
string lexicographicallySmallestEquivalentString(string str1, string str2, string base ,vector<int> &groups){
    string ans = "";
    for(int i = 0 ; i < 26 ; i++){
        groups.at(i) = i;
    }
    int i = 0;
    while(i < str1.length()){
        int x = str1.at(i) - 'a';
        int y = str2.at(i) - 'a';
        unite(x, y, groups);
        i++;
    }
    i = 0; 
    while(i < base.length()){
        int lead = find(base.at(i++) - 'a', groups);
        ans += static_cast<char>(lead+'a');
    }
    return ans;
}
int main(){
    string str1 = "leetcode";
    string str2 = "programs";
    string base = "sourcecode";
    vector<int> groups(26);
    string ans = lexicographicallySmallestEquivalentString(str1, str2, base, groups);
    cout<<"Lexicographically smallest equivalent string between "<<str1<<" and "<<str2<<" is "<<ans<<endl;
    return 0; 
}