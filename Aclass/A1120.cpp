// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// bool hashtable[10010];
// int main() {
//     int n;
//     vector<int> ans;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         int temp, sum = 0;
//         cin >> temp;
//         while(temp) {
//             int t = temp % 10;
//             sum += t;
//             temp /= 10;
//         }
//         if(hashtable[sum] == false) {
//             hashtable[sum] = true;
//             ans.push_back(sum);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     cout << ans.size() << endl;
//     for(int i = 0; i < ans.size(); i++) {
//         if(i != 0) cout << " ";
//         cout << ans[i];
//     }
//     return 0;
// }
#include <iostream>
#include <set>
using namespace std;
set<int> ans;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num, temp = 0; 
        cin >> num;
        while(num) {
            temp += num % 10;
            num /= 10;
        }
        ans.insert(temp);
    }
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it < ans.end(); it++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}