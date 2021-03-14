#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n == 0 || n == 1){
        printf("%d", n);
        return 0;
    }
    int f1 = 0, f2 = 1;
    int f3 = 1;
    while(f3 <= n){
        int t3 = f3;
        f3 = f1 + f2;
        f1 = f2;
        f2 = t3;
    }
    int d1 = f3 - n;
    int d2 = n - f2;
    if(d1 >= d2) {
        printf("%d", f2);
    } else{
        printf("%d", f3);
    }
    return 0;
}