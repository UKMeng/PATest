#include <iostream>
#include <cmath>
using namespace std;
int hashtable[10010];
// bool prime[10010];
// void init() {
//     for(int i = 2; i < 10010; i++) {
//         int cnt = 2;
//         if(prime[i] == false) {
//             while(i * cnt < 10010) {
//                 prime[i * cnt] = true;
//                 cnt++;
//             }
//         }
//     }
// }
bool isPrime(int a) {
    if(a <= 1) return false;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0) return false;
    }
    return true;
}
int main() {
    // init();
    int n, query;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int id;
        cin >> id;
        hashtable[id] = i;
    }
    cin >> query;
    for(int i = 0; i < query; i++) {
        int id;
        cin >> id;
        printf("%04d: ", id);
        if(hashtable[id] == 1) {printf("Mystery Award\n"); hashtable[id] = -1;}
        else if(hashtable[id] == 0) printf("Are you kidding?\n");
        else if(hashtable[id] == -1) printf("Checked\n");
        else if(hashtable[id] > 1 && isPrime(hashtable[id])) {printf("Minion\n"); hashtable[id] = -1;}
        else {printf("Chocolate\n"); hashtable[id] = -1;}
    }
    return 0;
}