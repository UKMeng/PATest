#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int get_id(char *s) {
    int temp = 0;
    for(int i = 0; i < 3; i++) temp = temp * 26 + (s[i] - 'A');
    temp = temp * 10 + (s[3] - '0');
    return temp;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
int main() {
    int n, k, c, s, id;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &c, &s);
        for(int j = 0; j < s; j++) {
            scanf("%s", name);
            id = get_id(name);
            v[id].push_back(c);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        id = get_id(name);
        sort(v[id].begin(), v[id].end());
        int num = v[id].size();
        cout << name << " " << num;
        for(int j = 0; j < num; j++) cout << " " << v[id][j];
        if(i != n - 1) cout << endl;
    }
    return 0;
}