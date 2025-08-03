#include <iostream>
using namespace std;

const long long MOD = 1e9+7; // Optional if you want to avoid overflow

pair<long long,long long> fib(long long n) {
    // returns {F(n), F(n+1)}
    if (n == 0) return {0, 1};
    
    auto p = fib(n >> 1);   // n/2
    long long a = p.first;  // F(k)
    long long b = p.second; // F(k+1)
    
    long long c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD; // F(2k)
    long long d = (a * a % MOD + b * b % MOD) % MOD;           // F(2k+1)
    
    if (n & 1) 
        return {d, (c + d) % MOD};  // odd n -> return {F(n), F(n+1)}
    else 
        return {c, d};              // even n -> return {F(n), F(n+1)}
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << n << "th Fibonacci number: " << fib(n).first << endl;
    return 0;
}
