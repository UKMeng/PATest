#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    string a = "abcd";
    char b = 'a';
    cout << a[0] << endl;
    cout << toupper(a[0]) << endl;  // toupper 和 tolower 函数的返回值均为 int 类型
    cout << toupper(b) << endl;
    return 0;
}