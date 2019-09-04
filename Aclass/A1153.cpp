// #include <iostream>        // 运行超时，代码太烂
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// struct node {
//     string cid, date, type, kid;
//     int score;
//     node(string a, int b, string c, string d, string e) : cid(a), score(b), type(c), kid(d), date(e) {};
// };
// unordered_map<string, vector<node> > date, type, kid;
// bool cmp(node a, node b) {
//     if(a.score != b.score) return a.score > b.score;
//     else return a.cid < b.cid;
// }
// unordered_map<string, int> hashtable;
// bool cmp1(string a, string b) {
//     if(hashtable[a] != hashtable[b]) return hashtable[a] > hashtable[b];
//     else return a < b;
// }
// int main() {
//     int n, query, tscore;
//     string tid, tdate, ttype, tkid;
//     cin >> n >> query;
//     for(int i = 0; i < n; i++) {
//         cin >> tid >> tscore;
//         ttype = tid.substr(0, 1);
//         tkid = tid.substr(1, 3);
//         tdate = tid.substr(4, 6);
//         date[tdate].push_back(node(tid, tscore, ttype, tkid, tdate));
//         type[ttype].push_back(node(tid, tscore, ttype, tkid, tdate));
//         kid[tkid].push_back(node(tid, tscore, ttype, tkid, tdate));
//         // cout << tkid << " " << ttype << " " << tdate << endl;
//     }
//     for(int i = 1; i <= query; i++) {
//         int ttype;
//         string term;
//         cin >> ttype >> term;
//         cout <<  "Case " << i << ": " << ttype << " " << term << endl;
//         if(ttype == 1) {
//             sort(type[term].begin(), type[term].end(), cmp);
//             for(int j = 0; j < type[term].size(); j++) {
//                 cout << type[term][j].cid << " " << type[term][j].score << endl;
//             }
//             if(type[term].size() == 0) cout << "NA" << endl;
//         } else if(ttype == 2) {
//             if(kid[term].size() == 0) cout << "NA" << endl;
//             else {
//                 int sum = 0;
//                 for(int j = 0; j < kid[term].size(); j++) {
//                     sum += kid[term][j].score;
//                 }
//                 cout << kid[term].size() << " " << sum << endl;
//             }
//         } else if(ttype == 3) {
//             if(date[term].size() == 0) cout << "NA" << endl;
//             else {
//                 vector<string> ans;
//                 for(int j = 0; j < date[term].size(); j++) {
//                     if(hashtable[date[term][j].kid] == 0) ans.push_back(date[term][j].kid);
//                     hashtable[date[term][j].kid]++;
//                 }
//                 sort(ans.begin(), ans.end(), cmp1);
//                 for(int j = 0; j < ans.size(); j++) {
//                     cout << ans[j] << " " << hashtable[ans[j]] << endl;
//                 }
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    string t;
    int value;
} ;
bool cmp(const node &a, const node &b) {
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}
int main() {
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].value;
    }
    for(int i = 1; i <= k; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;
        if(num == 1) {
            for(int j = 0; j < n; j++) {
                if(v[j].t[0] == s[0]) ans.push_back(v[j]);
            } 
        } else if(num == 2) {
            for(int j = 0; j < n; j++) {
                if(v[j].t.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if(cnt != 0) printf("%d %d\n", cnt, sum);
        } else if(num == 3) {
            unordered_map<string, int> m;
            for(int j = 0; j < n; j++) {
                if(v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
            }
            for(auto it : m) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int j = 0; j < ans.size(); j++) {
            printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
        }
        if(((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) printf("NA\n");
    }
    return 0;
}