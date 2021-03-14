#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int no_num;
int hashtable[62];

void hashwork(int n)
{
    if (hashtable[n]>0)
    {
        no_num--;
        hashtable[n]--;
    }
}
int main()
{
    string fact, want;
    cin >> fact >> want;
    int len1 = fact.length();
    int len2 = want.length();
    no_num = len2;
    for(int i = 0; i < len1; i++)
    {
        if (isupper(fact[i])) hashtable[fact[i] - 'A']++;
        else if (islower(fact[i])) hashtable[fact[i] - 'a' + 26]++;
        else hashtable[fact[i] - '0' + 52]++;
    }
    for(int i = 0; i < len2; i++)
    {
        if(isupper(want[i])) 
            hashwork(want[i]-'A');
        else if(islower(want[i])) 
            hashwork(want[i]-'a'+26);
        else
            hashwork(want[i]-'0'+52);
    }
    if(no_num == 0) cout << "Yes" << " " << len1 - len2;
    else cout << "No" << " " << no_num;
    return 0;
}