#include<iostream>

using namespace std;

int main (){
    /*int *ptr = NULL;
    cout<<"Value of ptr: "<<*ptr<<endl;*/
    int arr[10];
    cout<<"Address of arr: "<<arr<<endl;
    cout<<"Value of &arr: "<<&arr<<endl;
    cout<<"Value of &arr[0]: "<<&arr[0]<<endl;

    int*ptr = arr;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;
    int a[20] = {1, 2, 3, 5};
    cout<<&a<<endl;

    char ch[] = "Aniket Maity";
    ch[0] = 'a';

    char *c = &ch[0];
    cout<<"Value of c: "<<c<<endl;
    char temp = 'A';
    char* ptr1 = &temp;
    cout<<ptr1<<endl;
    char* ptr2 = "Aniket Maity";
   // ptr2[0] = 'a';
    cout<<"Risky: "<<ptr2<<endl;


    return 0;
}