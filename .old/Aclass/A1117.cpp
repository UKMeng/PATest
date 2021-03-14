#include <iostream>
using namespace std;
const int maxn = 1000010;
int hashtable[maxn];
int addition[maxn];
int main() {
    int n, max = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp > max) max = temp;
        hashtable[temp]++;
    }
    while(max > 0) {
        addition[max - 1] = addition[max] + hashtable[max];
        max--;
        if(addition[max] >= max) break;
    }
    cout << max;
    return 0;
}