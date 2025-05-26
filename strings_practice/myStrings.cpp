#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){

    /* APPEND
    string str1;
    string str2 = "Writing ";
    string str3 = "print 10 and then 5 more";
    
    str1.append(str2);
    cout<<str1<<endl;
    str1.append(str3, 6 , 3);
    cout<<str1<<endl;
    str1.append("dots are cool", 5);
    cout<<str1<<endl;
    str1.append("here: ");
    cout<<str1<<endl;
    str1.append(10, '.');
    cout<<str1<<endl;
    APPEND*/

    /*ASSIGN

    string str ;
    string base = "The quick brown fox jump over a lazy dog.";

    str.assign(base);
    cout<<str<<endl;
    str.assign(base, 10, 9);
    cout<<str<<endl;
    str.assign("pangrams are cool", 7);
    cout<<str<<endl;
    str.assign("c-string");
    cout<<str<<endl;
    str.assign(10, '$');
    cout<<str<<endl;
    str.assign(base.begin(), base.end());
    cout<<str<<endl;

    ASSIGN*/
    
    /* at()
    string str ("Test String");
    for(unsigned i = 0 ; i < str.length() ; i++){
        cout<<str.at(i);
    }
    at() */

    /* back()

    string str(" Hello C++.");
    str.back() = '!';
    str.front() = '@';
    cout<<str<<endl;

    back()*/
    
    /*begin()
    string str("Test Strings");
    string:: iterator it = str.begin();
    while(it != str.end()){
        cout<<*it;
        it++;
    }
    cout<<'\n';
    begin()*/

    /* c_str 
    string str ("Please split this sentence into tokens");

    const char * cstr  = str.c_str();//new char[str.length()+1];
    //strcpy(cstr, str.c_str());
    cout<<cstr<<endl;
    
    //delete [] cstr;

    c_str*/

    /* cbegin()

    string str ("Lorem Ipsum");
    for(string:: const_iterator it = str.cbegin() ; it != str.cend() ; it++){
         
        cout<<*it;
    }
    cout<<'\n';
    cbegin()*/

    /*compare()

    string str1 ("Green apple");
    string str2 ("Red apple");

    if(str1.compare(str2) != 0){
        cout<<str1<<" is not "<<str2<<endl;
    }

    if(str1.compare(6,5,"apple") == 0){
    cout<<"Still "<<str1<<" is an "<<"apple"<<endl;    
    }
    
    if(str2.compare(4, 5, "apple") == 0){
        cout<<"Still "<<str2<<" is an "<<"apple"<<endl;
    }
    compare()*/

    /*copy()

    char* buffer = new char[20];

    string str ("Test String");
    unsigned len = str.copy(buffer, 6, 5);
    buffer[len] = '\0';
    cout<<"buffer contains: "<<buffer<<endl;
    delete [] buffer;
    copy()*/

    /*insert()

    string str = "to be question";
    string str2 = "the ";
    string str3 = "or not to be ";
    string:: iterator it;

    str.insert(6, str2);
    cout<<str<<endl;
    str.insert(6, str3, 3, 4);
    cout<<str<<endl;
    str.insert(10, "that is cool", 8);
    str.insert(10, "to be ");
    str.insert(15, 1, ':');

    cout<<str<<endl;

    insert()*/

    /*replace()*/

    string base = "this is a test string.";
    string str2 = "n example";
    string str3 = "sample phrase";
    string str4 = "useful.";

    string str = base;
    cout<<str<<endl;
    str.replace(9, 5, str2);
    cout<<str<<endl;
    str.replace(19, 6, str3, 7, 6);
    cout<<str<<endl;
    str.replace(8, 10, "just a");
    cout<<str<<endl;

    

    return 0;
}