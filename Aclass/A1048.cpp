#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, total;
    int v1 = -1, v2 = -1;
    scanf("%d %d", & N, & total);
    int coin[100010] = {0};
    for(int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", & temp);
        coin[temp]++;
    }
    for(int i = 0; i < total; i++)
    {
        if(coin[i])
        {
            if(total - i == i) coin[i]--;
            if(coin[total-i])
            {
                v1 = i;
                v2 = total - i;
                break;
            }
        }
    }
    if(v1 == -1 || v2 == -1)
        cout << "No Solution";
    else 
        cout << v1 << " " << v2;
    return 0;
}
// struct node  // 超时
// {
//     int v1, v2;
//     bool flag = false;
// }value[100010];
// int main()
// {
//     int N, total;
//     scanf("%d %d", & N, & total);
//     int coin[100010] = {0};
//     for(int i = 0; i < N; i++)
//     {
//         scanf("%d", & coin[i]);
//         if(coin[i] >= total) continue;
//         for(int j = 0; j < i; j++)
//         {
//             int tv1, tv2, temp;
//             if(coin[j] <= coin[i])
//             {
//                 tv1 = coin[j];
//                 tv2 = coin[i];
//             }
//             else
//             {
//                 tv1 = coin[i];
//                 tv2 = coin[j];
//             }
//             temp = tv1 + tv2;
//             if(value[temp].flag == false)
//             {
//                 value[temp].flag = true;
//                 value[temp].v1 = tv1;
//                 value[temp].v2 = tv2;
//             }
//             else
//             {
//                 if (tv1 < value[temp].v1)
//                 {
//                     value[temp].v1 = tv1;
//                     value[temp].v2 = tv2;
//                 }
//             }
//         }
//     }
//     if (value[total].flag == false)
//     {
//         printf("No Solution");
//     }
//     else 
//     {
//         printf("%d %d", value[total].v1, value[total].v2);
//     }
//     return 0;
// }