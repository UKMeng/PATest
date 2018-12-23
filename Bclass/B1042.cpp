#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    char id;
    int num;
}hashtable[26];

void init_hash()
{
    for(int i = 0; i < 26; i++)
    {
        hashtable[i].id = 'a' + i;
        hashtable[i].num = 0;
    }
}

bool cmp(node a, node b)
{
    if (a.num != b.num) return a.num > b.num;
    else return a.id < b.id;
}
int main()
{
    init_hash();
    string word;
    getline(cin, word);
    int len = word.length();
    for(int i = 0; i < len; i++)
        if(isalpha(word[i])) hashtable[tolower(word[i]) - 'a'].num++; 
    sort(hashtable, hashtable + 26, cmp);
    cout << hashtable[0].id << " " << hashtable[0].num;
    return 0;
}