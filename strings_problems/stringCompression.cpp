#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    const char chars []= "aabbccccccccccccccccccccccccc";
    string str;
    char ptr = chars[0];
    int count = 1;
    for(int i = 1 ; chars[i] != '\0' ; i++){
         if(chars[i] != ptr){
            if(count<10){
            str.push_back(ptr);
            str.append(to_string(count));
            }
            else{
                str.push_back(ptr);
                int pos = str.size()-1;
                while(count != 0){
                    int rem = count%10;
                    str.insert(pos, to_string(rem));
                    count /= 10;
                }
            }
            ptr = chars[i];
            count = 1; 
         }
         else{
            count++;
         }
    }
    if(count<10){
            str.push_back(ptr);
            str.append(to_string(count));
            }
            else{
                str.push_back(ptr);
                int pos = str.size();
                while(count != 0){
                    int rem = count%10;
                    str.insert(pos, to_string(rem));
                    count /= 10;
                    pos = str.size() - 1;
                }
            }
    cout<<str<<endl;
    const char* chars_new = str.c_str(); 
    cout<<chars_new<<endl;
    char *newChars = str.data();
    cout<<newChars<<endl;
    return 0;
}