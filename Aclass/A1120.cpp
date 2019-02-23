#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool hashtable[10010];
int main() {
    int n;
    vector<int> ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp, sum = 0;
        cin >> temp;
        while(temp) {
            int t = temp % 10;
            sum += t;
            temp /= 10;
        }
        if(hashtable[sum] == false) {
            hashtable[sum] = true;
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}