#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;
struct node {
    string name;
    int ns;
    double score;
    int s;
    node(string a) : name(a) {};
};
map<string, int> mapp;
vector<node> ans;
double getscore(string id, double s) {
    if(id[0] == 'A') return s;
    else if(id[0] == 'T') return s * 1.5;
    else return s / 1.5;
}
bool cmp(node a, node b) {
    if(a.s != b.s) return a.s > b.s;
    else if(a.ns != b.ns) return a.ns < b.ns;
    else return a.name < b.name;
}
int main() {
    int n, cnt = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string id, tname;
        double s;
        cin >> id >> s >> tname;
        transform(tname.begin(), tname.end(), tname.begin(), ::tolower);
        double score = getscore(id, s);
        if(mapp[tname] == 0) {
            mapp[tname] = cnt++;
            node temp = node(tname);
            temp.ns = 1;
            temp.score = score;
            ans.push_back(temp);
        } else {
            int index = mapp[tname] - 1;
            ans[index].ns++;
            ans[index].score += score;
        }
    }
    for(int i = 0; i < ans.size(); i++) ans[i].s = (int)ans[i].score;
    sort(ans.begin(), ans.end(), cmp);
    int rank = 1, ran = 1;
    cout << ans.size() << endl;
    cout << rank << " " << ans[0].name << " " << ans[0].s << " " << ans[0].ns << endl;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i].s == ans[i - 1].s)  ran++;
        else {
            rank += ran;
            ran = 1;
        }
        cout << rank << " " << ans[i].name << " " << ans[i].s << " " << ans[i].ns << endl;
    }
    return 0;
}