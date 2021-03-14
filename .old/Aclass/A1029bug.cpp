#include <iostream> // 内存超限
#include <algorithm>
using namespace std;
const int maxn = 1000010;
int s1[maxn], s2[maxn], mer[maxn];
int n1, n2;
int main()
{
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++)
    {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &n2);
    int N = (n1 + n2 - 1)/2;
    int pos1 = 0, pos2 = 0;
    int flag = 0;
    scanf("%d", &s2[pos2]);
    for(int i = 0; i <= N; i++)
    {
        if(pos1 < n1 && pos2 < n2)
        { 
            if(s1[pos1] <= s2[pos2])
            {
                mer[i] = s1[pos1];
                pos1++;
            }
            else
            {
                mer[i] = s2[pos2];
                pos2++;
                scanf("%d", &s2[pos2]);
            }
        }
        else
        {
            if(pos1 == n1) {flag = 1; break;}
            else if(pos2 == n2) {flag = 2; break;}
        }
    }
    switch(flag)
    {
        case 0: 
            cout << mer[N];
            break;
        case 1:
            for(int i = pos2 + 1; i <= pos2 + N - pos1; i++)
                scanf("%d", &s2[i]);
            cout << s2[pos2 + N - pos1];
            break;
        case 2:
            cout << s1[pos1 + N - pos2];
    }
    return 0;
}