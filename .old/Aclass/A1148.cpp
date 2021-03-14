#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> word, ans;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        word.push_back(temp);
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            vector<int> A, lie;
            A.resize(n);
            A[i - 1] = A[j - 1] = -1;
            for(int id = 1; id <= n; id++) {
                int temp = word[id - 1];
                if(temp < 0) {
                    if(A[abs(temp) - 1] == 0) lie.push_back(id); 
                } else if(temp > 0) {
                    if(A[temp - 1] == -1) lie.push_back(id); 
                }
            }
            if(lie.size() == 2 && A[lie[0] - 1] + A[lie[1] - 1] == -1) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    if(ans.size() == 0) cout << "No Solution";
    else cout << ans[0] << " " << ans[1] << endl;
    return 0;
}