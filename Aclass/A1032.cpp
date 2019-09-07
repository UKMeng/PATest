#include <iostream>
using namespace std;
const int maxn = 100010;
int ne[maxn];
bool hashtable[maxn];
int main() {
    int f1, f2, n;
    cin >> f1 >> f2 >> n;
    for(int i = 0; i < n; i++) {
        string t;
        int temp;
        cin >> temp >> t;
        cin >> ne[temp];
    }
    for(int i = f1; i != -1; i = ne[i]) hashtable[i] = true;
    for(int i = f2; i != -1; i = ne[i]) {
        if(hashtable[i]) {
            printf("%05d", i);
            return 0;
        }
    } 
    printf("-1");
    return 0;
}