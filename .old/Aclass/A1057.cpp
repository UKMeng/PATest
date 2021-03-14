#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int sqrn = 316;
stack<int> st;
int block[sqrn], table[maxn];
void peekMedian(int k) {
    int sum = 0, bid = 0;
    while(sum + block[bid] < k) sum += block[bid++];
    int num = bid * sqrn;
    while(sum + table[num] < k) sum += table[num++];
    printf("%d\n", num);
}
int main() {
    int n;
    char cmd[20];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if(strcmp(cmd, "Push") == 0) {
            int temp;
            scanf("%d", &temp);
            st.push(temp);
            block[temp / sqrn]++;
            table[temp]++;
        } else if(strcmp(cmd, "Pop") == 0) {
           if(st.empty()) printf("Invalid\n");
           else {
               int temp = st.top();
               printf("%d\n", temp);
               st.pop();
               block[temp / sqrn]--;
               table[temp]--;
           }
        } else {
            if(st.empty()) printf("Invalid\n");
            else {
                int temp = st.size();
                if(temp % 2 == 0) temp = temp / 2;
                else temp = (temp + 1) / 2;
                peekMedian(temp);
            }
        }
    }
}
// #include <iostream> 运行超时
// #include <algorithm>
// #include <vector>
// using namespace std;
// vector<int> stv, temp;
// int main() {
//     int n, num = 0;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         if(s == "Pop") {
//             if(num == 0) cout << "Invalid" << endl;
//             else {
//                 int t = stv[stv.size() - 1];
//                 stv.pop_back();
//                 cout << t << endl;
//                 num--;
//             }
//         } else if(s == "PeekMedian") {
//             if(num == 0) cout << "Invalid" << endl;
//             else {
//                 temp.clear();
//                 temp = stv;
//                 sort(temp.begin(), temp.end());
//                 if(num % 2 == 0) cout << temp[num / 2 - 1] << endl;
//                 else cout << temp[(num + 1) / 2 - 1] << endl;
//             }
//         } else if(s == "Push") {
//             int t;
//             cin >> t;
//             stv.push_back(t);
//             num++;
//         }
//     }
//     return 0;
// }