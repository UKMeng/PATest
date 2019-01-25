#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[6] = {1, 4, 3, 2, 5, 8};
    sort(a, a + 6);
    for(int i = 0; i < 6; i++)
    {
        cout << i << " ";
    }
    return 0;
}