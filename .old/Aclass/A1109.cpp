#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node {
    int height;
    string name;
} Student[10010];
bool cmp(node a, node b) {
    if(a.height != b.height) return a.height > b.height;
    else return a.name < b.name;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) cin >> Student[i].name >> Student[i].height;
    sort(Student, Student + n, cmp);
    int pos = 0, w = k;
    while(w) {
        int rnum;
        vector<node> ans;
        if(w == k) rnum = n - n / k * (k - 1);
        else rnum = n / k;
        ans.resize(rnum);
        for(int i = pos; i < pos + rnum; i += 2) ans[rnum / 2 + (i - pos) / 2] = Student[i];
        for(int i = pos + 1; i < pos + rnum; i += 2) ans[rnum / 2 - (i - pos + 1) / 2] = Student[i];
        for(int i = 0; i < rnum; i++) {
            if(i != 0) cout << " ";
            cout << ans[i].name;
        }
        cout << endl;
        pos += rnum;
        w--;
    }
    return 0;
}