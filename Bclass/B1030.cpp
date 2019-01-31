#include <iostream>  // binary search, 亦可用upper_bound函数
#include <algorithm>
using namespace std;
const int maxn = 100010;
int number[maxn];
int N, p;
int binarySearch(int i, long long x)
{
    if (number[N-1] <= x) return N;
    int left = i + 1, right = N - 1, mid;
    while(left < right)
    {
        mid = (left + right)/2;
        if(number[mid] <= x) left = mid + 1;
        else right = mid;
    }
    return left;
}
int main()
{   
    cin >> N >> p;
    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
    }
    sort(number, number + N);
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        int j = binarySearch(i, (long long)number[i]*p);
        int temp = j - i;
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}