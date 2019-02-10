#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        double temp;
        scanf("%lf", &temp);
        ans += temp * (i + 1) * (n - i);
    }
    printf("%.2lf", ans);
    return 0;
}