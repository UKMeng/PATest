#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    int len1 = s1.length();
    int len2 = s2.length();
    bool hashtable[128] = {false}; 
    for (int i = 0; i < len2; i++)
    {
        hashtable[s2[i]] = true;
    }
    for (int i = 0; i < len1; i++)
    {
        if(hashtable[s1[i]] == false) cout << s1[i];
    }
    return 0;
}