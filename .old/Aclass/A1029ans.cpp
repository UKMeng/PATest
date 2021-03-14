#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
    queue<int> a, b;
    int n, m, num, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        a.push(num);
    }
    a.push(INT_MAX);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &num);
        b.push(num);
        if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())   
            a.pop();
        else                        
            b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())    
            a.pop();
        else                         
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}

// from: https://blog.csdn.net/xmj15715216140/article/details/80925186 
