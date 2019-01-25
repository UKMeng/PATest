#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int number[maxn];
int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> number[i];
        if(number[i] != i) ans += 1;
    }
    cout << ans - 1;
    return 0;
}