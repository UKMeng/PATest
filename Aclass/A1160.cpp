#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int sum_after, before;
} ;
vector<node> ans;
int n, SUM, SUM_AFTER;
int divisor(int a, int b) {
    if(a % b == 0) return b;
    else return divisor(b, a % b);
}
bool isPrime(int a) {
    if(a <= 2) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}
int getSum(int x) {
    int sum = 0;
    while(x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
bool check(int a) {
    int b = a + 1;
    SUM_AFTER = getSum(b);
    return isPrime(divisor(SUM, SUM_AFTER));
}
void dfs(string &str, int index, int digit, int sum) {
    if(index >= n || sum > SUM) return;
    if(sum + 9 * (n - index - 1) < SUM) return;
    str[index] = digit + '0';
    if(sum == SUM && index == n - 1) {
        int a = stoi(str);
        if(check(a)) {
            ans.push_back((node){SUM_AFTER, a});
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        dfs(str, index + 1, i, sum + i);
    }
}
bool cmp(node a, node b) {
    if(a.sum_after != b.sum_after) return a.sum_after < b.sum_after;
    else return a.before < b.before;
}
int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        ans.clear();
        cin >> n >> SUM;
        cout << "Case: " << i + 1 << endl;
        string str(n, '0');
        for(int j = 1; j < 10; j++) {
            dfs(str, 0, j, j);
        }
        if(ans.size() == 0) {
            cout << "No Solution" << endl;
            break;
        } else {
            sort(ans.begin(), ans.end(), cmp);
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i].sum_after << " " << ans[i].before << endl;
            }
        }
    }
    return 0;
}