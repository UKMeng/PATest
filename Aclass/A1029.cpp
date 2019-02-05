#include <iostream> // 内存超限，解决办法是第二个序列边读边存,但还是通不过最后一个检查点
#include <algorithm>
using namespace std;
const int maxn = 1000010;
const int INF = 2e31 - 1;
int s1[maxn], s2[maxn];
int n1, n2;
int main()
{
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++)
    {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &n2);
    s1[n1] = INF;
    s2[n2] = INF;
    int N = (n1 + n2 - 1)/2;
    int pos1 = 0, pos2 = 0, count = 0;
    scanf("%d", &s2[pos2]);
    while(count < N)
    {
        if(s1[pos1] <= s2[pos2]) 
        {
            // cout << s1[pos1] << " ";
            pos1++;
        }
        else 
        {
            // cout << s2[pos2] << " ";
            pos2++;
            scanf("%d", &s2[pos2]);
        }
        count++;
    }
    cout << min(s1[pos1], s2[pos2]);
    // cout << s1[pos1] << " " << s2[pos2] << " ";
    // if(s1[pos1] <= s2[pos2]) cout << s1[pos1];
    // else cout << s2[pos2];
    return 0;
}
//     int flag = 0; 超出内存限制以及未知错误
//     for(int i = 0; i < N; i++)
//     {
//         if(pos1 < n1 && pos2 < n2)
//         { 
//             if(s1[pos1] <= s2[pos2])
//             {
//                 pos1++;
//             }
//             else
//             {
//                 pos2++;
//             }
//         }
//         else
//         {
//             if(pos1 == n1) {flag = 1; break;}
//             else if(pos2 == n2) {flag = 2; break;}
//         }
//     }
//     switch(flag)
//     {
//         case 0: 
//             cout << min(s1[pos1], s2[pos2]);
//             break;
//         case 1:
//             cout << s2[pos2 + N - pos1];
//             break;
//         case 2:
//             cout << s1[pos1 + N - pos2];
//             break;
//     }
//     return 0;
// }