#include <iostream>
#include <stack>
using namespace std;
int a[1010];
int main() {
    stack<int> st;
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = true;
        int pos = 0;
        while(!st.empty()) st.pop();
        for(int j = 0; j < n; j++) scanf("%d", &a[j]);
        for(int j = 1; j <= n; j++) {
            st.push(j);
            if(st.size() > m) {flag = false; break;}
            while(!st.empty() && st.top() == a[pos]) {
                st.pop();
                pos++;
            }
        }
        if(st.empty() && flag == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}