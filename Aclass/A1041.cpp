#include <iostream>
using namespace std;
const int maxn = 10010;
const int maxp = 100010;
int le[maxp], hashtable[maxn];
int main() {
    int n, win = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &le[i]);
        hashtable[le[i]]++;
    }
    for(int i = 0; i < n; i++) if(hashtable[le[i]] == 1) {win = le[i]; break;}
    if(win == -1) cout << "None";
    else cout << win;
    return 0;
}