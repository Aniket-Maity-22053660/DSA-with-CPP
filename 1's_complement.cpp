#include <iostream>
#include<sstream>
using namespace std;

int main() {
    int num;
    cout << "Enter the binary pattern: ";
    cin >> num;
    
    stringstream ss;
    ss<<num;
    string number = ss.str();
    bool invalid = false;

    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '1') {
            number[i] = '0';
        } else if (number[i] == '0') {
            number[i] = '1';
        } else {
            // Invalid character detected
            invalid = true;
            break;
        }
    }

    if (invalid) {
        cout << "Error: Invalid binary input. Only 0 and 1 are allowed." << endl;
    } else {
        cout << "Your number after 1's complement: " << number << endl;
    }

    return 0;
}
