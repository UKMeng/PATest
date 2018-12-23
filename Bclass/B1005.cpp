#include <iostream>
#include <algorithm>
using namespace std;
int coverall[110] = {0};
int coverallnum = 0;
bool noneedtest[110] = {false};
int cal(int n)
{
    if(n%2 == 0) return n/2;
    else return (3*n+1)/2;
}

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int N;
    cin >> N;
    int test[110] = {0};
    for(int i = 0; i < N; i++)
        cin >> test[i];
    for(int i = 0; i < N; i++)
    {
        if(noneedtest[test[i]] == true) continue;
        bool hashtable[10010] = {false};
        int temp = test[i];
        while(temp != 1) 
        {
            temp = cal(temp);
            hashtable[temp] = true;
        }
        for(int j = 0; j < N; j++)
        {
            if(i == j) continue;
            if(noneedtest[test[j]] == true) continue;
            if(hashtable[test[j]] == true)
            {
                noneedtest[test[j]] = true;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(noneedtest[test[i]] == false)
        {
            coverallnum++;
            coverall[coverallnum-1] = test[i];
        }
    }
    sort(coverall, coverall+coverallnum, cmp);
    for(int i = 0; i < coverallnum; i++)
    {
        if(i != 0) cout << " ";
        cout << coverall[i];
    }
    return 0;
}