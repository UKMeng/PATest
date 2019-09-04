#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int judge(int n) {
    bool j1 = isPrime(n);
    bool j2 = isPrime(n + 6);
    bool j3 = isPrime(n - 6);
    if(j1 && j3) return n - 6;
    else if(j1 && j2) return n + 6;
    else return -1;
}
int main(){
    int n;
    cin >> n;
    if(judge(n) != -1) {
        cout << "Yes" << endl << judge(n) << endl;
    } else {
        while(judge(n) == -1) n++;
        cout << "No" << endl << n << endl;
    }
    return 0;
}