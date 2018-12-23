#include <iostream>
using namespace std;
const int maxn = 10010;
const int maxp = 100010;

int main()
{
    int hashtable[maxn] = {0};
    int n;
    int player[maxp] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> player[i];
        hashtable[player[i]]++;
    }
    int flag = 0;
    for(flag = 0; flag < n; flag++)
    {
        if (hashtable[player[flag]] == 1)
        {
            cout << player[flag];
            break;
        }
    }
    if (flag == n) cout << "None";
    return 0;
}