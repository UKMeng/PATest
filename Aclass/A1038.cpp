#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
string num[maxn];

bool cmp(string a, string b)
{
    return a + b < b + a;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N, cmp);
    string ans;
    for (int i = 0; i < N; i++)
    {
        ans += num[i];
    }
    while(ans[0] == '0' && ans.size() != 0)
    {
        ans.erase(ans.begin());
    }
    if(ans.size() == 0) cout << "0";
    else cout << ans;
    return 0;
}