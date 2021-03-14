#include <iostream>  
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];
int main()
{
    int N;
    scanf("%d", &N);
    int ans = 0;
    int wrongpos = 0;
    int temp;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        pos[temp] = i;
        if(pos[temp] != temp && temp != 0) wrongpos++;          
    }
    int k = 1; // 判断某个数是否在本位，回归本位后的数是不再会变化位置的
    while(wrongpos > 0)
    {   
        if(pos[0] != 0) 
        {
            swap(pos[0], pos[pos[0]]);
            ans++;
            wrongpos--;
        }
        else if(pos[0] == 0)
        {
           while(k < N)
           {
               if(pos[k] != k)
               {
                   swap(pos[0], pos[k]);
                   ans++;
                   break;
               }
               k++;
           }
        }
    }
    cout << ans;
    return 0;
}