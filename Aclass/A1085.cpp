#include <iostream> // Two Pointers
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef long long LL;
LL num[maxn];
int N, p;
int main()
{
    scanf("%d %d", &N, &p);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &num[i]);
    }
    sort(num, num + N);
    int a = 0, b = 0, count = 1;
    while(b < N && a < N)
    {
        while(num[b] <= num[a] * p && b < N)
        {
            b++; 
        }
        count = max(b - a, count);
        a++;
    }
    cout << count;
    return 0;
}