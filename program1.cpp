#include<bits/stdc++.h>
#include<memory>
#include<sstream>
#include<array>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<map>
using namespace std;


typedef union Data {
  int intValue; // Member for integer value
  float floatValue; // Member for float value
  char strValue[50]; // Member for string value
} mydata;

class Base{
    mutable int x;
    mutable int  y;
    public:
    Base(){}
    Base(int a, int b): x{a}, y{b} {}
    void setX(int a) {x = a;}
    int getX() const { y = 30; return x;}
    
    virtual void func(){
       cout<<"See we are inside the base!"<<endl;
    }
    friend void setFriend(const Base*, int);

};

class Derived: public Base{
    public:
    using Base::func;
    void func(){
        cout<<"See we are inside the derived!"<<endl;
    }
};

void setFriend(const Base* obj, int x){
    obj->x = x;
    cout<<"That was changed through friend function!"<<endl;
}

int myAtoi(char* str){
    int res = 0 ;
    int sign = 1;
    int i = 0;

    if(str[i] == '-'){
        sign = -1;
        i++;
    }

    for(;str[i] != '\0'; i++){
        res = res*10 + str[i] - '0';
    }

    return (sign*res);
}

template<class T>
class Print{
    private:
    int x;
    public:
    static T var;
    void printVal(){
        cout<<++var<<endl;
    }
};

template<class T>
T Print<T>::var = 91;

enum class Color{
    red,
    green,
    blue
};




int main(){
    union Data data1;
    cout<<"Hello World!"<<endl;
    char name[] = "Aniket Maity";
    cout<<"My name: "<<name<<endl;
    for(char &c : name){
        if(c != '\0')
        c = 'A';
    }
    cout<<"New: "<<name<<endl;
    data1.intValue = 45;
    data1.floatValue = 45.55;
    strcpy(data1.strValue, "King Star");
    cout<<"int value: "<<data1.intValue<<endl;
    cout<<"float value: "<<data1.floatValue<<endl;
    cout<<"string value: "<<data1.strValue<<endl;
    int *a = new int(10);
    void*ptr = static_cast<void*>(a);
    cout<<"Void ptr: "<<*(int*)ptr<<endl;
    Base obj;
    obj.setX(12);
    cout<<obj.getX()<<endl;
    
    Derived d1;
    Base *objptr = static_cast<Base*> (&d1);
    objptr->func();
    setFriend(objptr, 90);
    cout<<objptr->getX()<<endl;
    
    float f = 9.8;
    int a1;
    a1 = f;
    cout<<"Implicit Cast: "<<a1<<endl;
    a1 = static_cast<int>(f);
    cout<<"Static Cast: "<<a1<<endl;
    int * const ptr1 = a;
    int a2 = 34;
    *ptr1 = a2;
    cout<<"ptr1: "<<*ptr1<<endl;
    const int a3 = 35;
    int * const ptr2 = const_cast<int*>(&a3);
    *ptr2 = 92;
    cout<<"After const_cast: "<<*ptr2<<endl;
    int (*func)(char*) = myAtoi;

    cout<<"My atoi: "<<(*func)("-2344332")<<endl;
    
    Print<int> print1;
    print1.printVal();
    Print<int> print2;
    print2.printVal();
    Print<char> print3;
    print3.printVal();

    Color myColor = Color::green;
    cout<<"Scoped Enum: "<<static_cast<int> (myColor)<<endl;
    cout<<"Smart Pointers:- "<<endl;
    unique_ptr<int> uptr = make_unique<int>(99);
    cout<<"&uptr: "<<(&uptr)<<endl<<"*uptr: "<<*uptr<<endl;
    unique_ptr<int> uptr2 = make_unique<int>(89);
    uptr2 = move(uptr);
    if(!uptr)
    cout<<"After move uptr is null!"<<endl<<"Value of uptr2 is "<<*uptr2<<endl;
    shared_ptr<int>sptr = make_shared<int>(*uptr2);
    cout<<"Shared pointer:-"<<endl;
    cout<<"*sptr: "<<*sptr<<endl<<"Shared_count: "<<sptr.use_count()<<endl;
    shared_ptr<int> sptr2 = sptr;
    cout<<"*sptr2: "<<*sptr2<<endl<<"Shared Count: "<<sptr2.use_count()<<endl;
    string myname = "Aniket Maity";

    stringstream ss(myname);
    string word;
    ss>>word;
    cout<<word<<endl;
    ss>>word;
    cout<<word<<endl;
    cout<<ss.str()<<endl;
    stringstream ss1("King Star Khan");
    cout<<ss1.str()<<endl;
    stringstream ss2("123 324");
    string c, d;
    ss2>>c>>d;
    cout<<c+d<<endl;
    ss2<<23;
    cout<<ss2.str()<<endl;

    stringstream ss3;
    ss3<<34<<34<<45;
    int num ;
    ss3>>num;
    cout<<ss3.str()<<endl;
    stringstream ss4;
    ss4<<"23 54 68 98";
    string str6;
    while(ss4>>str6){
        cout<<str6<<endl;
    }
    
    cout<<"-------STL-------"<<endl;

    array<int, 5> arr = {1,2,3,75,3478};
    cout<<arr.at(4)<<endl;
    cout<<"Front: "<<arr.front()<<endl;
    cout<<"Back: "<<arr.back()<<endl;
    cout<<"data(): "<<(arr.data())<<endl;
    arr.at(4) = 599;
    cout<<"Back: "<<arr.back()<<endl;
    vector<int> Vec;
    for(int i = 0 ; i < 5 ; i++){
        Vec.push_back(i+7);
    }
    for(int &x:Vec){
        cout<<x<<" ";
    }
    cout<<"Size: "<<Vec.size()<<endl<<"capacity: "<<Vec.capacity()<<endl;
    Vec.at(0) = 99;
    cout<<Vec.front()<<endl;
    set<int> Set;
    vector<int> Vec2(5, 9);
    for(int &x: Vec2){
        cout<<x<<" ";
    }

    cout<<"List:- "<<endl;
    list<int> li;
    for(int j = 0 ; j < 90 ; j++){
        li.push_back(j+1);
    }
    for(int &x : li){
        cout<<x<<" ";
    }
    Vec.at(0) = 500;
    cout<<endl;
    for(int i = 0 ; i < Vec.size() ; i++){
        cout<<Vec[i]<<" ";
    }
    queue<int> q ;
    for(int i = 0 ; i < 18 ; i++){
        q.push(i+90);
    }
    cout<<"Queue top: "<<q.front()<<endl;
    cout<<"Front Changed! "<<endl;
    q.front() = 999;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    } 
    deque<int> dq;
    for(int i = 0 ; i < 100 ; i++){
        if(i%2 == 0 ){
            dq.push_back(i);
        }
        else{
            dq.push_front(i);
        }
    }
    cout<<"Deque  before delete:- "<<endl;
    for(int &x: dq){
        cout<<x<<" ";
    }
    dq.pop_back();
    dq.pop_front();
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
    cout<<"deque is empty? "<<(dq.empty()?"Yes!":"No")<<endl;
    map<int, string> mp;
    cout<<"Enter how many slots you want to enter?: ";
    int slot;
    cin>>slot;
    for(int i = 0 ; i < slot ; i++){
        cout<<"Enter slot "<<(i+1)<<"details: ";
        int key;
        string value;
        cin>>key;
        cin.ignore();
        getline(cin, value);
        mp.insert({key, value});
    }

    map<int, string>:: iterator it = mp.begin();
    while (it != mp.end()) {
    if (it->first == 4) {
        it = mp.erase(it); // erase and advance
    } else {
        cout << it->first << " " << it->second << endl;
        ++it; // manually advance
    }
}
it = mp.find(3);
if(it != mp.end()){
    cout<<"Value found: "<<it->second<<" at key="<<it->first<<endl;
}
else{
    cout<<"Value not found!"<<endl;
}
    




return 0;
}
