#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int maxInt = 1e9;
int num[maxn], ans[maxn], leftmax[maxn], rightmin[maxn];
int n, m = 0;
int main()
{
    scanf("%d", &n);
    scanf("%d", &num[0]);
    leftmax[0] = 0, rightmin[n-1] = maxInt;
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &num[i]);
        leftmax[i] = max(leftmax[i-1], num[i-1]);
    }
    for(int i = n - 2; i >= 0; i--)
    {
        rightmin[i] = min(rightmin[i+1], num[i+1]);
    }
    for(int i = 0; i < n; i++)
    {
        if(num[i] > leftmax[i] && num[i] < rightmin[i])
        {
            ans[m++] = num[i];
        }
    }
    printf("%d\n", m);
    for(int i = 0; i < m; i++)
    {
        if(i == 0) printf("%d", ans[i]);
        else printf(" %d", ans[i]);
    }
    printf("\n");
    return 0;
}