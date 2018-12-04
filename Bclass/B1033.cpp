#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string broken_key, text;
    getline(cin, broken_key);  // 坏件可以为空，所以要读取空行
    getline(cin, text);
    int len1 = broken_key.length(), len2 = text.length();
    bool hashtable[41] = {false};
    for (int i = 0; i < len1; i++)
    {
        if(isdigit(broken_key[i])) hashtable[26 + (broken_key[i] - '0')] = true;
        else if(isalpha(broken_key[i])) hashtable[tolower(broken_key[i]) - 'a'] = true;
        else if(broken_key[i] == '_') hashtable[36] = true;
        else if(broken_key[i] == ',') hashtable[37] = true;
        else if(broken_key[i] == '.') hashtable[38] = true;
        else if(broken_key[i] == '-') hashtable[39] = true;
        else if(broken_key[i] == '+') hashtable[40] = true;
    }
    for (int i = 0; i < len2; i++)
    {
        if(isdigit(text[i])) 
        {
            if(hashtable[26 + (text[i] - '0')] == false) cout << text[i];
            else continue;
        }
        else if(isupper(text[i]))
        {
            if(hashtable[tolower(text[i])-'a'] == false && hashtable[40] == false) cout << text[i];
            else continue;
        }
        else if(islower(text[i]))
        {
            if(hashtable[text[i]-'a'] == false) cout << text[i];
            else continue;
        }
        else if(text[i] == '_')
        {
            if(hashtable[36] == false) cout << '_';
            else continue;
        }
        else if(text[i] == ',')
        {
            if(hashtable[37] == false) cout << ',';
            else continue;
        }
        else if(text[i] == '.')
        {
            if(hashtable[38] == false) cout << '.';
            else continue;
        }
        else if(text[i] == '-')
        {
            if(hashtable[39] == false) cout << '-';
            else continue;
        }
    }
    cout << endl;
    return 0;
}