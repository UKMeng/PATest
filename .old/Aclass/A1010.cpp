#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL table[256];
string N1, N2;
int tag, radix;
void init()
{
    for(int c = '0'; c <= '9'; c++)
    {
        table[c] = c - '0';
    }
    for(char c = 'a'; c <= 'z'; c++)
    {
        table[c] = c - 'a' + 10;
    }
}
LL turntoRadix10(string a, int n)
{
    LL ans = 0;
    int len = a.length();
    for(int i = 0; i < len; i++)
    {
        ans = ans * n + table[a[i]];
        if(ans < 0) break;
    }
    return ans;
}
LL findMin(string a)
{
    int len = a.length();
    LL ans = 0;
    for(int i = 0; i < len; i++)
    {
        ans = max(ans, table[a[i]]);
    }
    return ans + 1;
}
LL binarySearch(LL min, LL max, LL t)
{
    LL left = min, right = max, mid;
    LL ans = -1;
    while(left <= right)
    {
        mid = (left + right)/2;
        LL temp = turntoRadix10(N2, mid);
        // cout << mid << " " << temp << endl;
        if (temp > t || temp < 0) right = mid - 1;
        else if (temp < t) left = mid + 1;
        else if (temp == t) {ans = mid; right = mid - 1;}
    }
    return ans;
}
int main()
{
    init();
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2) swap(N1, N2);
    LL dec = turntoRadix10(N1, radix);
    // cout << dec << endl;
    LL Min = findMin(N2);
    LL Max = max(Min, dec) + 1;
    // cout << Min << " " << Max << endl;
    LL ans = binarySearch(Min, Max, dec);
    if (ans == -1) cout << "Impossible";
    else cout << ans;
    return 0;
}