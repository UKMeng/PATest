#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    int ad, value, next;
} Node[maxn];
vector<int> v[3];
int main() {
    int start, n, k;
    scanf("%d %d %d", &start, &n, &k);
    for(int i = 0; i < n; i++) {
        int ad, v, ne;
        scanf("%d %d %d", &ad, &v, &ne);
        Node[ad].ad = ad;
        Node[ad].next = ne;
        Node[ad].value = v;
    }
    while(start != -1) {
        if(Node[start].value < 0) v[0].push_back(start);
        else if(Node[start].value <= k) v[1].push_back(start);
        else v[2].push_back(start);
        start = Node[start].next;
    }
    bool flag = false;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(!flag) {
                printf("%05d %d", v[i][j], Node[v[i][j]].value);
                flag = true;
            } else {
                printf(" %05d\n%05d %d", v[i][j], v[i][j], Node[v[i][j]].value);
            }
        }
    }
    printf(" -1\n");
    return 0;
}