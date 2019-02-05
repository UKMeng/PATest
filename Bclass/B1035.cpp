#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
int N;
int init[maxn], mid[maxn], temp[maxn], fin[maxn];
bool flag = false;
bool isSame(int a[], int b[])
{
    for(int i = 0; i < N; i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}
void showArrow(int a[])
{
    cout << a[0];
    for(int i = 1; i < N; i++)
    {
        cout << " " << a[i];
    }
}
void insertQ(int a[])
{
    int pos = 0;
    for(int i = 1; i < N; i++)
    {
        if(i > 1 && isSame(mid, a)) flag = true;   // i > 1 是为了保证第一次排序没有变化而产生的多解
        int j = i, temp = a[i];
        while(j > 0 && a[j - 1] > temp)
        {
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
        if(flag)
        {
            cout << "Insertion Sort" << endl;
            showArrow(a);
            return;
        }
        if(isSame(fin, a)) return;
    }
}
void mergeQ(int a[])
{
    bool f = false;
    // showArrow(a);
    for(int step = 2; step/2 <= N; step *= 2)
    {
        if(step > 2 && isSame(a, mid)) f = true;  
        for(int i = 0; i < N; i += step)
        {
            sort(a + i, a + min(i + step, N));
            // showArrow(a);
            // cout << endl;
        }
        if(f)
        {
            showArrow(a);
            return;
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {   
        cin >> init[i];
        fin[i] = init[i];
        temp[i] = init[i];
    }
    for(int i = 0; i < N; i++)
        cin >> mid[i];
    sort(fin, fin + N);
    insertQ(init);
    if(!flag)
    {
        cout << "Merge Sort" << endl;
        mergeQ(temp);
    }
    return 0;
}