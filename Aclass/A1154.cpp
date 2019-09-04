#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node {
    int v1, v2;
} ;
int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<node> edge(m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &edge[i].v1, &edge[i].v2);
    } 
    scanf("%d", &k);
    while(k--) {
        int a[100010] = {0}, flag = 1;
        set<int> cnt;
        for(int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            a[i] = temp;
            cnt.insert(temp); 
        }
        for(int i = 0; i < m; i++) {
            if(a[edge[i].v1] == a[edge[i].v2]) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) printf("%d-coloring\n", cnt.size());
        else printf("No\n");
    }
    return 0;
}