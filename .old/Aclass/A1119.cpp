#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool isUnique = true;
void getIn(int preL, int preR, int postL, int postR) {
    if(preL == preR) {
        in.push_back(pre[preL]);
        return;
    }
    if(pre[preL] == post[postR]) {
        int i = preL + 1;
        while(i <= preR && pre[i] != post[postR - 1]) i++;
        if(i - preL > 1) {
            getIn(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
        } else isUnique = false;
        in.push_back(post[postR]);
        getIn(i, preR, postL + (i - preL - 1), postR - 1);
    }
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    getIn(0, n - 1, 0, n - 1);
    printf("%s\n%d", isUnique == true ? "Yes" : "No", in[0]);
    for(int i = 1; i < n; i++) {
        printf(" %d", in[i]);
    }
    printf("\n");
    return 0;
}