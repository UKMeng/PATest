#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
    int ad, ke;
}list[maxn];
int key[maxn], ne[maxn];
bool cmp(node a, node b) {return a.ke < b.ke;}
int main() {
    int n, first, sum = 0, temp;
    bool flag = false;
    cin >> n >> first;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        cin >> key[temp] >> ne[temp];
        if(temp == first) flag = true;
    }
    while(first != -1 && flag) {
        list[sum].ad = first;
        list[sum++].ke = key[first];
        first = ne[first];
    }
    if(sum == 0) {cout << "0 -1"; return 0;}
    sort(list, list + sum, cmp);
    printf("%d %05d\n", sum, list[0].ad);
    for(int i = 0; i < sum - 1; i++) printf("%05d %d %05d\n", list[i].ad, list[i].ke, list[i+1].ad);
    printf("%05d %d -1", list[sum-1].ad, list[sum-1].ke);
    return 0;
}