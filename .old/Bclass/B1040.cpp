#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int rem = 1000000007;
typedef long long LL;
string pat;
int main()
{
    cin >> pat;
    int leftP = 0, rightT = 0;
    int len = pat.length();
    LL ans = 0;
    for(int i = 0; i < len; i++)
    {
        if(pat[i] == 'T') rightT++;
    }
    for(int i = 0; i < len; i++)
    {
        if(pat[i] == 'A')
            ans += leftP * rightT;
        else if(pat[i] == 'P')
            leftP++;
        else if(pat[i] == 'T')
            rightT--;
    }
    cout << ans%rem;
    return 0;
}