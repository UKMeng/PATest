#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
    int address = -2, data, next, index;
}table[maxn];
bool cmp(node a, node b) {return a.index < b.index;}
int main() {
    int first, n, k, pos = 0;
    vector<node> temp;
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i++) {
        node t;
        scanf("%d %d %d", &t.address, &t.data, &t.next);
        if(t.address == first) {
            table[pos++] = t;
            first = t.next;
            int s = temp.size();
            bool f = false;
            while(s) {
                for(auto it = temp.begin(); it != temp.end(); it++) {
                    if((*it).address == first) {
                        table[pos++] = *it;
                        first = (*it).next;
                        temp.erase(it);
                        f = true;
                        break;
                    }
                }
                s--;
                if(!f) break; 
            }
        }
        else temp.push_back(t);
    }
    for(int i = 0; i < pos; i++) table[i].index = i;
    int ti = 0;
    while(ti + k <= pos) {
        for(int i = ti; i < ti + k; i++) {
            if(i - ti + 1 <= k / 2) {
                table[i].index += k - 1 - 2 * (i - ti);
                // cout << i << " " << table[i].index << endl;
            }
            else if(i - ti + 1 > k / 2) {
                table[i].index -= k - 1 - 2 * (ti + k - i - 1);
                // cout << i << " " << table[i].index << endl;
            }
        }
        ti += k;
    }
    sort(table, table + pos, cmp);
    for(int i = 0; i < pos - 1; i++) table[i].next = table[i + 1].address;
    table[pos - 1].next = -1;
    for(int i = 0; i < pos - 1; i++) printf("%05d %d %05d\n", table[i].address, table[i].data, table[i].next);
    printf("%05d %d %d\n", table[pos-1].address, table[pos-1].data, table[pos-1].next);
    return 0;
}