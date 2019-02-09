#include <iostream> // 运行超时
#include <cstring>
#include <algorithm>
using namespace std;
int c[4] = {1000, 100, 10, 1};
bool cmp(char a, char b) {return a >= b;}
int main()
{
    string a, b, temp;
    cin >> temp;
    temp.insert(0, 4 - temp.length(), '0');
    // for(int i = 0; i < 4; i++)
    // {
    //     temp[i] = '0' + N / c[i];
    //     N = N % c[i];
    // }
    do
    {
        a = temp;
        b = temp;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        int n1 = stoi(a), n2 = stoi(b);
        int t = n2 - n1;
        temp = to_string(t);
        temp.insert(0, 4 - temp.length(), '0');
        cout << b << " - " << a << " = " << temp << endl;
    }while(temp != "6174" && temp != "0000");
    return 0;
}