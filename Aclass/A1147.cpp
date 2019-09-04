#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int query, n;
void postOrder(int now) {
    if(now > n - 1) return;
    postOrder(now * 2 + 1);
    postOrder(now * 2 + 2);
    printf("%d%s", v[now], now == 0? "\n" : " ");
}
int main() {
    scanf("%d %d", &query, &n);
    v.resize(n);
    for(int i = 0; i < query; i++) {
        for(int j = 0; j < n; j++) scanf("%d", &v[j]);
        int flag = v[0] > v[1] ? 1 : -1;
        for(int j = 0; j < n / 2; j++) {
            int left = j * 2 + 1, right = j * 2 + 2;
            if(flag == 1) {
                if(v[j] < v[left] || (right < n && v[j] < v[right])) flag = 0;
            } else {
                if(v[j] > v[left] || (right < n && v[j] > v[right])) flag = 0;
            }
        }
        if(flag == 0) printf("Not Heap\n");
        else printf("%s Heap\n", flag == 1 ? "Max" : "Min");
        postOrder(0);
    }
    return 0;
}