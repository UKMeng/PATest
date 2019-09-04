// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// vector<string> ans;
// bool search(string s) {
//     for(int i = 0; i < ans.size(); i++) {
//         if(ans[i] == s) return false;
//     }
//     return true;
// }
// int main() {
//     int m, n, s;
//     cin >> m >> n >> s;
//     string temp;
//     for(int i = 1; i <= m; i++){
//         cin >> temp;
//         if(s == i) {
//             if(search(temp)) {
//                 ans.push_back(temp);
//                 s = s + n;
//             } else s++;
//         }
//     }
//     for(int i = 0 ; i < ans.size(); i++) {
//         cout << ans[i] << endl;
//     }
//     if(ans.size() == 0) cout << "Keep going..." << endl;
//     return 0;
// }
#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for(int i = 1; i <= m; i++) {
        cin >> str;
        if(mapp[str] == 1) s = s + 1;
        if(i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s = s + n;
        }
    }
    if(flag == false) cout << "Keep going...";
    return 0; 
}