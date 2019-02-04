#include <iostream> // Binary Search
#include <algorithm>
using namespace std;
const int maxn = 100010;
int coin[maxn];
int N, M, V1, V2;
bool binarySearch(int left)
{
    int l = left + 1, r = N - 1;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(coin[mid] + coin[left] == M)
        {
            V1 = coin[left];
            V2 = coin[mid];
            return true;
        } 
        else if(coin[mid] + coin[left] < M) l = mid + 1;
        else if(coin[mid] + coin[left] > M) r = mid - 1;
    }
    return false;
}
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin + N);
    int left = 0;
    bool flag = false;
    while(coin[left] <= M || left = N - 1)
    {
        flag = binarySearch(left);
        if(flag) break;
        left++;
    }
    if(!flag) cout << "No Solution";
    else cout << V1 << " " << V2;
    return 0;
}