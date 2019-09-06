#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> a;
void show() {
    for(int i = 1; i <= n; i++) {
        if(i != 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
}
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && a[j] < a[j + 1]) j++;
        if(a[i] >= a[j]) break;
        swap(a[i], a[j]);
        i = j, j = i * 2;
        show();
    }   
}
void createHeap() {
    cout << "Create Start" << endl;
    for(int i = n / 2; i >= 1; i--) downAdjust(i, n);
}
void heapSort() {
    cout << "Sort Start" << endl;
    for(int i = n; i > 1; i--) {
        swap(a[i], a[1]);
        show();
        downAdjust(1, i - 1);
    }
}
int main() {
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    show();
    createHeap();
    heapSort();
    return 0;
}