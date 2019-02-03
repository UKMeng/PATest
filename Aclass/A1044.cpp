#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int chain[maxn], sum[maxn];
int ansl[maxn], ansr[maxn];
int N, M;
int Min = INT32_MAX, minNum = 0;
void record(int l, int r)
{
    ansl[minNum-1] = l + 1;
    ansr[minNum-1] = r;
}
void minCol(int temp, int r, int l)
{
    if(temp < Min)
    {
        Min = temp;
        minNum = 1;
        record(l, r);
    }
    else if(temp == Min)
    {
        minNum++;
        record(l, r);
    }
}
void binarySearch(int left, int right)
{
    int l = left, r = right;
    while(l <= r)
    {
        int mid = (r + l) / 2;
        // cout << l << " " << mid << " " << r << endl;
        int temp = sum[right] - sum[mid];
        // cout << "temp = " << temp << endl;
        if(temp >= M)
        {
            if(temp <= Min) minCol(temp, right, mid); 
            l = mid + 1;
        }
        else r = mid - 1;
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    sum[0] = 0;
    bool flag1 = false;
    int pos = 1;
    for(int i = 1; i < N + 1; i++)
    {
        scanf("%d", &chain[i]);
        sum[i] = sum[i-1] + chain[i];
        if(sum[i] >= M && flag1 == false)  {flag1 = true; pos = i;}
    }
    // for(int i = 0; i < N + 1; i++)
    //     cout << sum[i] << " " ;
    for(int i = pos; i < N + 1; i++)
    {
        binarySearch(0, i);
    }
    for(int i = 0; i < minNum; i++)
    {
        cout << ansl[i] << "-" << ansr[i] << endl;
    }
    return 0;
}