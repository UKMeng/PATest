#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
struct node {
    int v1, v2;
} Node[maxn];
bool hashtable[maxn] = {false};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &Node[i].v1, &Node[i].v2);
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        bool flag = true;
        fill(hashtable, hashtable + maxn, false);
        int t;
        scanf("%d", &t);
        for(int j = 0; j < t; j++) {
            int temp;
            scanf("%d", &temp);
            hashtable[temp] = true;
        }
        for(int j = 0; j < m; j++) {
            if(hashtable[Node[j].v1] == false && hashtable[Node[j].v2] == false) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}