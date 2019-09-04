// #include <iostream>
// #include <cmath>
// using namespace std;
// int hashtable[10010];
// // bool prime[10010];
// // void init() {
// //     for(int i = 2; i < 10010; i++) {
// //         int cnt = 2;
// //         if(prime[i] == false) {
// //             while(i * cnt < 10010) {
// //                 prime[i * cnt] = true;
// //                 cnt++;
// //             }
// //         }
// //     }
// // }
// bool isPrime(int a) {
//     if(a <= 1) return false;
//     int Sqrt = sqrt((double)a);
//     for(int i = 2; i <= Sqrt; i++) {
//         if(a % i == 0) return false;
//     }
//     return true;
// }
// int main() {
//     // init();
//     int n, query;
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         int id;
//         cin >> id;
//         hashtable[id] = i;
//     }
//     cin >> query;
//     for(int i = 0; i < query; i++) {
//         int id;
//         cin >> id;
//         printf("%04d: ", id);
//         if(hashtable[id] == 1) {printf("Mystery Award\n"); hashtable[id] = -1;}
//         else if(hashtable[id] == 0) printf("Are you kidding?\n");
//         else if(hashtable[id] == -1) printf("Checked\n");
//         else if(hashtable[id] > 1 && isPrime(hashtable[id])) {printf("Minion\n"); hashtable[id] = -1;}
//         else {printf("Chocolate\n"); hashtable[id] = -1;}
//     }
//     return 0;
// }
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<string, int> m;
int hashtable[10010];
bool isPrime(int n) {
    if(n < 2) return false;
    else {
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        m[temp] = i + 1;
        int t = stoi(temp);
        hashtable[t] = 1;
    }
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
        string test;
        cin >> test;
        cout << test << ": ";
        int tt = stoi(test);
        if(hashtable[tt] == 0) cout << "Are you kidding?" << endl;
        else if(hashtable[tt] == 1) {
            if(m[test] == 1) cout << "Mystery Award" << endl;
            else {
                if(isPrime(m[test])) cout << "Minion" << endl;
                else cout << "Chocolate" << endl;
            }
            hashtable[tt] = 2;
        }
        else if(hashtable[tt] == 2) cout << "Checked" << endl;
    }
    return 0;
}