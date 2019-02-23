#include <iostream>
using namespace std;
const int maxn = 0x7fffffff;
bool hashtable[maxn];
int main() {
    int n, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp < 0) continue;
        hashtable[temp] = true;
    }
    for(int i = 1; i <= maxn; i++) {
        if(hashtable[i] == false) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}