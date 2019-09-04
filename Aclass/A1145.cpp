#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main() {
    int tsize, n, m;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isPrime(tsize)) tsize++;
    vector<int> hashtable(tsize);
    for(int i = 0; i < n; i++) {
        int a;
        bool flag = false;
        scanf("%d", &a);
        for(int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if(hashtable[pos] == 0) {
                hashtable[pos] = a;
                flag = true;
                break;
            }
        }
        if(!flag) cout << a << " cannot be inserted." << endl;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        for(int j = 0; j <= tsize; j++) {
            ans++;
            int pos = (a + j * j) % tsize;
            // cout << a << " " << pos << endl;
            if(hashtable[pos] == a || hashtable[pos] == 0) break;
        }
    }
    printf("%.1lf", ans * 1.0 / m);
    return 0;
}