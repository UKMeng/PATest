#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(int a, int b) {return a > b;}
int main() {
    int n, ln, lm;
    vector<int> input;
    scanf("%d", &n);
    input.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &input[i]);
    sort(input.begin(), input.end(), cmp);
    if(n == 1) {lm = 1, ln = 1;}
    else {
        for(int i = sqrt(n); i > 0; i--) {
            if(n % i == 0) {
                ln = i;
                lm = n / i;
                break;
            }
        }
    }
    int ans[lm][ln], cnt = 0, nowc = 0, nowk = 0, l = 0;
    while(cnt < n) {
        if(nowc < ln - 1 - l && nowk == l) ans[nowk][nowc++] = input[cnt++];
        else if(nowc == ln - 1 - l && nowk < lm - 1 - l) ans[nowk++][nowc] = input[cnt++];
        else if(nowc > l && nowk == lm - 1 - l) ans[nowk][nowc--] = input[cnt++];
        else if(nowc == l && nowk > l) {
            if(nowk - 2 == l) l++;
            ans[nowk--][nowc] = input[cnt++];
        } 
        else if(cnt + 1 == n) ans[nowk][nowc] = input[cnt++];
    }
    for(int i = 0; i < lm; i++) {
        for(int j = 0; j < ln; j++) {
            if(j != 0) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}