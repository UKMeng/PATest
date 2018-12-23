#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

string pat = "PATest";
int hashtable[6];
int num = 0;
void hashinput(int n)
{
    hashtable[n]++;
    num++;
}
void hashoutput(int n)
{
    if(hashtable[n] != 0)
    {
        cout << pat[n];
        hashtable[n]--;
        num--;
    }
}
int main()
{
    string word;
    cin >> word;
    int len = word.length();
    for(int i = 0; i < len; i++)
    {
        if(word[i] == 'P') hashinput(0);
        else if(word[i] == 'A') hashinput(1);
        else if(word[i] == 'T') hashinput(2);
        else if(word[i] == 'e') hashinput(3);
        else if(word[i] == 's') hashinput(4);
        else if(word[i] == 't') hashinput(5);
    }
    while(num)
    {
        for(int i = 0; i < 6; i++)
            hashoutput(i);
    }
    return 0;
}