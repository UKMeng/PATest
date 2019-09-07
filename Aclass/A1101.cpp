// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int maxn = 100010;
// const int maxInt = 1e9;
// int num[maxn], ans[maxn], leftmax[maxn], rightmin[maxn];
// int n, m = 0;
// int main()
// {
//     scanf("%d", &n);
//     scanf("%d", &num[0]);
//     leftmax[0] = 0, rightmin[n-1] = maxInt;
//     for(int i = 1; i < n; i++)
//     {
//         scanf("%d", &num[i]);
//         leftmax[i] = max(leftmax[i-1], num[i-1]);
//     }
//     for(int i = n - 2; i >= 0; i--)
//     {
//         rightmin[i] = min(rightmin[i+1], num[i+1]);
//     }
//     for(int i = 0; i < n; i++)
//     {
//         if(num[i] > leftmax[i] && num[i] < rightmin[i])
//         {
//             ans[m++] = num[i];
//         }
//     }
//     printf("%d\n", m);
//     for(int i = 0; i < m; i++)
//     {
//         if(i == 0) printf("%d", ans[i]);
//         else printf(" %d", ans[i]);
//     }
//     printf("\n");
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, max = 0;
    scanf("%d", &n);
    vector<int> a(n), temp, ans;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    temp = a;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) {
        if(a[i] == temp[i] && a[i] > max) { 
            ans.push_back(temp[i]);
            max = a[i];
        } else if(a[i] > max) {
            max = a[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}