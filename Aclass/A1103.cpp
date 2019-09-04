// #include <iostream> // https://github.com/liuchuo/PAT/blob/master/AdvancedLevel_C%2B%2B/1103.%20Integer%20Factorization%20(30)%20.cpp
// #include <vector>
// #include <cmath>
// using namespace std;
// int n, k, p, maxFacSum = -1;
// vector<int> v, ans, tempAns;
// void init() {
//     int temp = 0, index = 1;
//     while (temp <= n) {
//         v.push_back(temp);
//         temp = pow(index, p);
//         index++;
//     }
// }
// void dfs(int index, int tempSum, int tempK, int facSum) {
//     if (tempK == k) {
//         if (tempSum == n && facSum > maxFacSum) {
//                 ans = tempAns;
//                 maxFacSum = facSum;
//         }
//         return;
//     }
//     while(index >= 1) {
//         if (tempSum + v[index] <= n) {
//             tempAns[tempK] = index;
//             dfs(index, tempSum + v[index], tempK + 1, facSum + index);
//         }
//         if (index == 1) return;
//         index--;
//     }
// }
// int main() {
//     scanf("%d%d%d", &n, &k, &p);
//     init(); 
//     tempAns.resize(k);
//     dfs(v.size() - 1, 0, 0, 0);
//     if (maxFacSum == -1) {
//         printf("Impossible");
//         return 0;
//     }
//     printf("%d = ", n);
//     for (int i = 0; i < ans.size(); i++) {
//         if (i != 0) printf(" + ");
//         printf("%d^%d", ans[i], p);
//     }
//     return 0;
// }
#include <iostream>      // 未知原因造成一个点超时
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> temp, ans, v;
unordered_map<int, int> table;
int n, k, p, maxSum = -1;
void init2() {
    int i = 1;
    for(int i = 0; i < v.size(); i++) {
        for(int j = v[i]; j < v[i + 1]; j++) {
            table[j] = i;
        }
    }
}
void init() {
    int t = 0, index = 1;
    while (t <= n) {
        v.push_back(t);
        t = pow(index, p);
        index++;
    }
    v.push_back(t);
    init2();
}
void dfs(int index, int res, int sum, int premax) {
    int start;
    for(start = table[res]; start >= 1; start--) {
        // cout << res << " " << start << endl;
        if(start > premax) continue;
        if(index != k - 1) {
            if(v[start] < res) {
                temp.push_back(start);
                dfs(index + 1, res - v[start], sum + start, start);
                temp.pop_back();
            }
        } else if(index == k - 1) {
            if(v[start] == res) {
                if(sum + start > maxSum) {
                    temp.push_back(start);
                    ans = temp;
                    maxSum = sum + start;
                    temp.pop_back();
                } else if(sum == maxSum) {
                    temp.push_back(start);
                    for(int i = 0; i < k; i++) {
                        if(temp[i] != ans[i]) {
                            if(temp[i] > ans[i]) ans = temp;
                            break;
                        } 
                    }
                    temp.pop_back();
                }
            }
        }
    }
}
int main() {
    cin >> n >> k >> p;
    init();
    dfs(0, n, 0, table[n]);
    if(maxSum == -1) cout << "Impossible" << endl;
    else {
        cout << n << " = ";
        for(int i = 0; i < k; i++) {
            if(i != 0) cout << " + ";
            cout << ans[i] << "^" << p;
        }
    }
    return 0;
}