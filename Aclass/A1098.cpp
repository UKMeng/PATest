#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> init, now, temp;
int n;
void downAdjust(int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && temp[j] > temp[j - 1]) j = j + 1;
        if(temp[j - 1] > temp[i - 1]) {
            swap(temp[j - 1], temp[i - 1]);
            i = j;
            j = i * 2;
        } else break;
    }
}
void show(vector<int> t) {
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        cout << t[i];
    }
}
int main() {
    bool f1 = false;
    int cnt = 2;
    cin >> n;
    init.resize(n);
    now.resize(n);
    for(int i = 0; i < n; i++) cin >> init[i];
    for(int i = 0; i < n; i++) cin >> now[i];
    temp = init;
    while(cnt <= n) {
        sort(temp.begin(), temp.begin() + cnt);
        cnt++;
        if(temp == now) {f1 = true; break;}
    }
    if(f1) {
        sort(temp.begin(), temp.begin() + cnt); 
        cout << "Insertion Sort" << endl;
        show(temp);
    }
    else {
        // temp = init;
        // downAdjust(1, n);
        cout << "Heap Sort" << endl;
        // int cnt1 = 0;
        // while(temp != now) {
        //     swap(temp[0], temp[n - 1 - cnt]);
        //     cnt++;
        //     downAdjust(1, n - cnt);
        // }
        // swap(temp[0], temp[n - 1 - cnt++]);
        // downAdjust(1, n - cnt);
        temp = now;
        int pos = n - 1;
        while(pos > 0 && temp[pos] == temp[pos - 1] + 1) pos--;
        swap(temp[0], temp[pos - 1]);
        downAdjust(1, pos - 1);
        show(temp);
    }
    return 0;
}