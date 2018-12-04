#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string in, out;
    cin >> in >> out;
    int len1 = in.length(), len2 = out.length();
    bool hashtable[37] = {false};
    for (int i = 0; i < len2; i++)
    {
        if(isdigit(out[i])) hashtable[26+(out[i]-'0')] = true;
        else if(isalpha(out[i])) hashtable[tolower(out[i])-'a'] = true;
        else hashtable[36] = true;
    }
    for (int i = 0; i < len1; i++)
    {
        if(isdigit(in[i])) 
        {
            if(hashtable[26+(in[i]-'0')] == false)
            {
                cout << in[i];
                hashtable[26+(in[i]-'0')] = true;
            }
        }
        else if(isalpha(in[i])) 
        {
            if(hashtable[tolower(in[i])-'a'] == false)
            {
                cout << char(toupper(in[i]));
                hashtable[tolower(in[i])-'a'] = true;
            }
        }
        else 
        {
            if(hashtable[36] == false)
            {
                cout << '_';
                hashtable[36] = true;
            }
        }
    }
    return 0;
}