#include <iostream>
#include <map>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
    string s, temp;
    map<string, int> word;
    int max = 0;
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            temp += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1) {
            if(temp.length() != 0) word[temp]++;
            temp.clear();
        }
    }
    for(auto it = word.begin(); it != word.end(); it++) {
        if(it -> second > max) {
            max = it -> second;
            temp = it -> first;
        }
    }
    cout << temp << " " << max;
    return 0;
}