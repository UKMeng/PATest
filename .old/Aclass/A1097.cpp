#include <iostream> // 第三个检查点段错误
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
vector<int> list, rm;
int ne[maxn], key[maxn];
bool isK[maxn];
void show(vector<int> a) {
    int s = a.size();
    for(int i = 0; i < s - 1; i++) printf("%05d %d %05d\n", a[i], key[a[i]], a[i+1]);
    if(s > 0) printf("%05d %d -1\n", a[s-1], key[a[s-1]]);
}
int main() {
    int first, n, temp;
    cin >> first >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        cin >> key[temp] >> ne[temp];
    }
    while(first != -1) {
        if(!isK[abs(key[first])]) {
            isK[abs(key[first])] = true;
            list.push_back(first);
            first = ne[first];
        }
        else {
            rm.push_back(first);
            first = ne[first];
        }
    }
    show(list);
    show(rm);
    return 0;
}  