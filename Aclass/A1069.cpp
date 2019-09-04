#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(char a, char b) {return a >= b;}
int main() {
    int f;
    cin >> f;
    string s = to_string(f);
    s.insert(0, 4 - s.length(), '0');
    do {
        string a, b;
        a = s, b = s;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        int num1, num2;
        num1 = stoi(a);
        num2 = stoi(b);
        int temp = num2 - num1;
        string t = to_string(temp);
        t.insert(0, 4 - t.length(), '0');
        cout << b << " - " << a << " = " << t << endl;
        s = t;
    } while(s != "0000" && s != "6174");
    return 0;
}