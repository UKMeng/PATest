#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
struct node {
    string id;
    int score;
} ;
bool cmp(node a, node b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<node> v(n);
    for(int i = 0; i < n; i++) {
       cin >> v[i].id >> v[i].score;
    }
    for(int i = 0; i < k; i++) {
        int type;
        string s;
        int sum = 0, cnt = 0;
        cin >> type >> s;
        cout << "Case " << i + 1 << ": " << type << " " << s << endl;
        vector<node> ans;
        if(type == 1) {
            for(int j = 0; j < n; j++) {
                if(v[j].id.substr(0, 1) == s) {
                    ans.push_back(v[j]);
                }
            }
        } else if(type == 2) {
            for(int j = 0; j < n; j++) {      
                if(v[j].id.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].score;
                }
            } if(cnt != 0) cout << cnt << " " << sum << endl;
        } else if(type == 3) {
            map<string, int> m;
            for(int j = 0; j < n; j++) {
                if(v[j].id.substr(4, 6) == s) {
                    m[v[j].id.substr(1, 3)]++;
                }
            }
            for(auto it = m.begin(); it != m.end(); it++) {
                node temp;
                temp.id = it -> first;
                temp.score = it -> second;
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int j = 0; j < ans.size(); j++) {
            cout << ans[j].id << " " << ans[j].score << endl;
        }
        if(((type == 1 || type == 3) && ans.size() == 0) || (type == 2 && cnt == 0)) cout << "NA" << endl;
    }
    return 0;
}