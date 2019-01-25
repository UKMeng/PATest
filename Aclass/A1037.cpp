#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
long long coupon[maxn];
long long product[maxn];
bool cmp(long long a, long long b)
{
    return a > b;
}
int main()
{
    int N, M;
    int p1 = 0, p2 = 0, n1 = 0, n2 = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &coupon[i]);
        if (coupon[i] > 0) p1++;
        else if(coupon[i] < 0) n1++;
    }
    sort(coupon, coupon + N, cmp);
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%lld", &product[i]);
        if (product[i] > 0) p2++;
        else if(product[i] < 0) n2++;
    }
    sort(product, product + M, cmp);
    int pm = min(p1, p2), nm = min(n1, n2);
    int total = 0;
    for(int i = 0; i < pm; i++)
    {
        total += coupon[i] * product[i];
    }
    for(int i = 0; i < nm; i++)
    {
        total += coupon[N-i-1] * product[M-i-1];
    }
    cout << total;
    return 0;
}