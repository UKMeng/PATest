#include <iostream> // ???????
using namespace std;
int hashtable[2010];
int main() {
    int n, amount;
    scanf("%d %d", &n, &amount);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        hashtable[temp]++;
    }
    for(int i = 0; i < 1001; i++) {
        if(i > amount / 2) break;
        if(hashtable[i]) {
            hashtable[i]--;
            if(hashtable[amount - i]) {
                cout << i << " " << amount - i<< endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}