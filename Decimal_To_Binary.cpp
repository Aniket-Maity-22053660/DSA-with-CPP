#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    long long decimal;
    cout << "Enter your decimal number: ";
    cin >> decimal;

    string binary = "";

    if (decimal == 0) {
        binary = "0";
    } else {
        while (decimal != 0) {
            int bit = decimal & 1;
            stringstream ss;
            ss<< bit;

            binary = ss.str() + binary;
            decimal >>= 1;
        }
    }

    cout << "Binary equivalent: " << binary << endl;
    return 0;
}
